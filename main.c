#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main()
{
    char* str = "(*(5)(+(4)(3))";

    tNo* arvore = criar_arvore(str);
    float resultado = resolver_avore(arvore);
    printf("%.2f\n", resultado);
    liberar_arvore(arvore);
    return 0;
}
