#include <stdio.h>
#include "bst.h"

int main()
{
    BST *arvore = criarBST();

    printf("\n\n");
    inserir(arvore, 10);
    inserir(arvore, 5);
    inserir(arvore, 15);
    inserir(arvore, 3);
    inserir(arvore, 4);
    inserir(arvore, 17);
    inserir(arvore, 13);
    inserir(arvore, 19);
    inserir(arvore, 18);

    imprimirEmOrdem(arvore);
    printf("\n\n");
    imprimirPreOrdem(arvore);
    printf("\n\n");

    return 0;
}