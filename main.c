#include <stdio.h>
#include "arvore_binaria.h"

int main()
{
    char* str = "(*(5)(+(2)(3)))";
    tNo* arvore = criar_arvore(str);
    
    return 0;
}
