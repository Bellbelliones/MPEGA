#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

avl *criarAVL()
{
    return NULL;
}
#include <stdlib.h>

NoAvl *criarNoAvl(int valor)
{

    NoAvl *novo = (NoAvl *)malloc(sizeof(NoAvl));

    if (novo != NULL)
    {
        novo->chave = valor;
        novo->altura = 1;
        novo->esq = NULL;
        novo->dir = NULL;
    }

    return novo;
}
NoAvl *inserirNoAvl(NoAvl *raiz, int valor)
{
    if (!raiz)
        return criarNoAvl(valor);

    if (valor < raiz->chave)
        raiz->esq = inserirNoAvl(raiz->esq, valor);

    else if (valor > raiz->chave)
        raiz->dir = inserirNoAvl(raiz->dir, valor);

    return raiz;
}
void emOrdem(NoAvl *raiz)
{

    if (raiz != NULL)
    {

        emOrdem(raiz->esq);

        printf("%d ", raiz->chave);

        emOrdem(raiz->dir);
    }
}