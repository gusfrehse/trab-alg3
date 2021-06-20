#include <stdlib.h>
#include <ctype.h>
#include "arvore_binaria.h"

tNo *criar_arvore(const char *expressao)
{
    int indice_inicial = 0;
    return criar_arvore_aux(expressao, &indice_inicial);
}

tNo *criar_no(int chave)
{
    tNo *no = malloc(sizeof(tNo));

    no->chave = chave;
    no->dir = NULL;
    no->esq = NULL;

    return no;
}

tNo *criar_arvore_aux(const char *expressao, int *indice)
{
    *indice++;
    const char *chave = expressao + *indice;

    tNo *no = criar_no(chave);

    if (isdigit(chave))
    {
        while (isdigit(expressao[*indice]))
        {
            *indice++;
        }
    }
    else
    {
        no->esq = criar_arvore_aux(expressao, indice);
        no->dir = criar_arvore_aux(expressao, indice);
    }

    *indice++;

    return no;
}
