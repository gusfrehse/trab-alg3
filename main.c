#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

#define MAX_INPUT_SIZE 256

int main()
{
    //char* str = "(*(5)(+(4)(3))";
    char input[MAX_INPUT_SIZE];

    fgets(input, MAX_INPUT_SIZE - 1, stdin);

    tNo *arvore = criar_arvore(input);
    float resultado = resolver_avore(arvore);
    printf("%.2f\n", resultado);
    liberar_arvore(arvore);
    return 0;
}
