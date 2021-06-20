#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "arvore_binaria.h"

tNo *criar_arvore_aux(const char *expressao, int *indice);
float operar(float operando1, float operando2, char operacao);
void imprimir_operacao(float operando1, float operando2, char operacao);


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

tNo *criar_arvore_aux(const char *expressao, int *indice)
{
    (*indice)++;
    const char *chave = expressao + *indice;

    tNo *no = criar_no(chave);
    //printf("criado no: %s\n", chave);

    //printf("teste\n");

    if (isdigit(*chave))
    {
        //printf("eh digito chave:%s\n", chave);
        //getchar();
        while (isdigit(expressao[*indice]))
        {
            (*indice)++;
        }
    }
    else
    {
        (*indice)++;
        no->esq = criar_arvore_aux(expressao, indice);
        no->dir = criar_arvore_aux(expressao, indice);
    }

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

float resolver_avore(tNo *no)
{

    if (eh_folha(no))
    {
        return atof(no->chave);
    }
    else
    {
        float operando1 = resolver_avore(no->esq);
        float operando2 = resolver_avore(no->dir);
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