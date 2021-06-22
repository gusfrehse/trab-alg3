/*
 * Trabalho 1 - CI1057 (Algorimos e Estruturas de Dados III)
 *
 * Autores:
 *      Vinícius M. Ribeiro
 *          GRR20203911
 *      Gustavo S. Frehse
 *          GRR20203927
 * 
 * Data : 21/06/21
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

#define MAX_INPUT_SIZE 256

int main()
{
    char input[MAX_INPUT_SIZE];

    // Lê a entrada do usuário e garante que ela não ultrapasse
    // o tamanho máximo do vetor.
    fgets(input, MAX_INPUT_SIZE - 1, stdin);

    tNo *arvore = criar_arvore(input);
    
    float resultado = resolver_arvore(arvore);
    
    // imprime o resultado com duas casas decimais
    printf("%.2f\n", resultado);

    liberar_arvore(arvore);
    
    return 0;
}
