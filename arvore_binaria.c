#include <ctype.h>
#include "arvore_binaria.h"

tNo *criar_arvore_aux(const char *expressao, int *indice)
{
    *indice++;
    const char *chave = expressao + indice;

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
