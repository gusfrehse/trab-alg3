#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "arvore_binaria.h"

tNo *criar_arvore_aux(const char *expressao, int *indice);

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
        float operacao = no->chave[0];

        return operar(operando1, operando2, operacao);
    }
}