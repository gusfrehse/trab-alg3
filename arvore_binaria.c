#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#include "arvore_binaria.h"

tNo *criar_no(const char *chave);

bool eh_folha(tNo *no);

tNo *criar_arvore_aux(const char *expressao, int *indice);

float operar(float operando1, float operando2, char operacao);

void imprimir_operacao(float operando1, float operando2, char operacao);

// Documentação em arvore_binaria.h
// Prepara a chamada da função que realiza a verdadeira criação.
tNo *criar_arvore(const char *expressao)
{
    int indice_inicial = 0;
    return criar_arvore_aux(expressao, &indice_inicial);
}

tNo *criar_no(const char *chave)
{
    tNo *no = malloc(sizeof(tNo));

    no->chave = chave;
    no->dir = NULL;
    no->esq = NULL;

    return no;
}

/*
 * Realiza o "trabalho pesado" de criação.
 *
 * Parâmetros : expressao   - string a ser evaluada.
 *              indice      - Controle para a função saber
 *                            em que parte da expressão está.
 * 
 * Retorno    : Nó raiz da árvore gerada.
*/
tNo *criar_arvore_aux(const char *expressao, int *indice)
{
    // Pula o abre parênteses "("
    (*indice)++;

    // Utiliza o índice para obter a posição correta do número/operação
    const char *chave = expressao + *indice;

    tNo *no = criar_no(chave);

    if (isdigit(*chave)) // Chave é número
    {
        /* Como o número pode ter mais de um caractere, para chegar ao
         * seu fim precisamos incrementar o índice até o número acabar.
         * Ex:
         *      (5555534234)...
         *       ^         | 
         *     índice      + -- Precisamos chegar até aqui
        */
        while (isdigit(expressao[*indice]))
        {
            (*indice)++;
        }
    }
    else // Chave é operação
    {
        // Pula a operação, deixa o índice "apontando" para o parênteses
        // do primeiro argumento.
        (*indice)++;

        /* Cria as subárvores que contém as expressões do primeiro e segundo
         * operandos.
         * Ex:
         * (*(+(5)(44))(-(7)(33)))
         *  ||         ^ operando 2
         *  |+ -- operando 1
         *  + -- operação
        */
        no->esq = criar_arvore_aux(expressao, indice); // primeiro operando

        // a criar_arvore_aux() da chamada passada atualizou o índice para
        // o começo do operando 2.
        no->dir = criar_arvore_aux(expressao, indice); // segundo operando
    }

    // Pula o fecha parênteses ")"
    (*indice)++;

    return no;
}

bool eh_folha(tNo *no)
{
    if (no->dir == NULL && no->esq == NULL)
    {
        return true;
    }

    return false;
}

float resolver_arvore(tNo *no)
{

    if (eh_folha(no))
    {
        return atof(no->chave);
    }
    else
    {
        float operando1 = resolver_arvore(no->esq);
        float operando2 = resolver_arvore(no->dir);
        char operacao = no->chave[0];
        imprimir_operacao(operando1, operando2, operacao);
        return operar(operando1, operando2, operacao);
    }
}

void imprimir_operacao(float operando1, float operando2, char operacao)
{
    printf("%.2f %c %.2f\n", operando1, operacao, operando2);
}

float operar(float operando1, float operando2, char operacao)
{
    switch (operacao)
    {
    case '*':
        return operando1 * operando2;
    case '+':
        return operando1 + operando2;
    case '-':
        return operando1 - operando2;
    case '/':
        return operando1 / operando2;
    default:
        return -1;
    }
}

void liberar_arvore(tNo *no)
{
    if (!eh_folha(no))
    {
        liberar_arvore(no->esq);
        liberar_arvore(no->dir);
    }
    free(no);
}