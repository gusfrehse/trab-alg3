#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct tNo tNo;

struct tNo
{
    tNo *dir, *esq;
    char *chave;
};

tNo *criar_arvore(const char *expressao);

#endif
