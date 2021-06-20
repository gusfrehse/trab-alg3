#include <stdlib.h>
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

tNo *criar_arvore_aux(const char *expressao)
{
    const char *chave = expressao + 1;

    tNo *no = criar_no(chave);

    if (!isdigit(chave))
    {
        no->esq = criar_arvore(primeiro_argumento(expressao));
        no->dir = criar_arvore(segundo_argumento(expressao));
    }

    return no;
}