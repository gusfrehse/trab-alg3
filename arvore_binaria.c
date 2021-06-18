#include "arvore_binaria.h"

tNo *criar_arvore(const char *expressao)
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