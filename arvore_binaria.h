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
 * Exemplo    :
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

/* =================================================================
 *
 * Função criar_arvore(const char *expressao)
 * 
 * Descrição  : Cria uma AB a partir de uma expressão bem formatada.
 * 
 * Parâmetros : expressao   - string a ser evaluada.
 * 
 * Retorno    : Nó raiz da árvore gerada.
 * 
 * Observações: A função não checa se a expressão é mal formatada;
 *              A árvore precisa ser liberada manualmente (com
 *              liberar_arvore()).
 * 
 * Exemplo    : tNo *arvore = criar_arvore("(+(3)(2))");
 * 
*/
tNo *criar_arvore(const char *expressao);

/* =================================================================
 *
 * Função resolver_arvore(tNo *no)
 * 
 * Descrição  : Resolve a expressão armazenada na AB.
 * 
 * Parâmetros : no  - Nó raiz da árvore.
 * 
 * Retorno    : Valor calculado.
 * 
 * Observações: Imprime na tela as operações intermediárias
 *              realizadas.
 * 
 * Exemplo    : float resultado = resolver_arvore(arvore);
 * 
*/
float resolver_arvore(tNo *no);

/* =================================================================
 *
 * Função liberar_arvore(tNo *no)
 * 
 * Descrição  : Libera a árvore da memória (free())
 * 
 * Parâmetros : no  - Nó raiz da árvore.
 * 
 * Retorno    : Nenhum.
 * 
 * Observações: Não esquecer de chamar essa função sempre que
 *              terminar de utilizar uma árvore.
 * 
 * Exemplo    : liberar_arvore(arvore);
 * 
*/
void liberar_arvore(tNo *no);

#endif