#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

/*
 * Estrutura tNo
 *
 * Descrição  : Estrutura básica da AB.
 * 
 * Atributos  : dir e esq   - nós filhos;
 *              chave       - armazena operação/número em
 *                            formato de ponteiro para char.
 * 
 * Observações: A chave aponta diretamente para o número/operação na
 *              expressão.
 *              
 * Exemplo:
 *      Expressão         :   (*(33)(+(405)(7)))
 *      Ponteiros         :    ^ ^   ^ ^    ^
 *      Chaves (string)   :   *(33)(+(405)(7)))
 *                            33)(+(405)(7)))
 *                            +(405)(7)))
 *                            405)(7)))
 *                            7)))
 *
*/
typedef struct tNo tNo;
struct tNo
{
    tNo *dir, *esq;
    const char *chave;
};

/*
 * Função
 * 
 * Descrição  :
 * 
 * Parâmetros :
 * 
 * Retorno    :
 * 
 * Observações:
 * 
 * Exemplo    :
 * 
 * 
*/
tNo *criar_arvore(const char *expressao);

/*
 * Função
 * 
 * Descrição  :
 * 
 * Parâmetros :
 * 
 * Retorno    :
 * 
 * Observações:
 * 
 * Exemplo    :
 * 
 * 
*/
float resolver_avore(tNo *no);

/*
 * Função
 * 
 * Descrição  :
 * 
 * Parâmetros :
 * 
 * Retorno    :
 * 
 * Observações:
 * 
 * Exemplo    :
 * 
 * 
*/
void liberar_arvore(tNo *no);

#endif

/*
 * Função
 * 
 * Descrição  :
 * 
 * Parâmetros :
 * 
 * Retorno    :
 * 
 * Observações:
 * 
 * Exemplo    :
 * 
 * 
*/