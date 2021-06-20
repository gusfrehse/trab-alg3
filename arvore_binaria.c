#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "arvore_binaria.h"

tNo *criar_arvore_aux(const char *expressao, int *indice);


tNo *criar_arvore(const char *expressao)
{
    int indice_inicial = 0;
    return criar_arvore_aux(expressao, &indice_inicial);
}

tNo *criar_no(const char* chave)
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
