#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct tNo tNo;

struct tNo
{
    tNo *dir, *esq;
    const char *chave;
};

tNo *criar_arvore(const char *expressao);
float resolver_avore(tNo *no);
void liberar_arvore(tNo *no);




#endif
