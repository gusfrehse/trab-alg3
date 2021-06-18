#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct tNo tNo;

struct tNo
{
    tNo *dir, *esq;
};

// Não sei se é bom nome
tNo *criar_no(const char *expressao);

#endif
