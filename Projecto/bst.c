#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct No
{
    int valor;
    struct No *esq;
    struct No *dir;
};

struct BST
{
    No *raiz;
};

BST *criarBST()
{
    BST *arvore = (BST *)malloc(sizeof(BST));
    arvore->raiz = NULL;
    return arvore;
}
No *criarNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
No *inserirRec(No *raiz, int valor)
{
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserirRec(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserirRec(raiz->dir, valor);

    return raiz;
}

void inserir(BST *arvore, int valor)
{
    arvore->raiz = inserirRec(arvore->raiz, valor);
}
int buscarRec(No *raiz, int valor)
{
    if (raiz == NULL)
        return 0;

    if (valor == raiz->valor)
        return 1;

    if (valor < raiz->valor)
        return buscarRec(raiz->esq, valor);
    else
        return buscarRec(raiz->dir, valor);
}

int buscar(BST *arvore, int valor)
{
    return buscarRec(arvore->raiz, valor);
}
void emOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void imprimirEmOrdem(BST *arvore)
{
    emOrdem(arvore->raiz);
}

void preOrdem(No *raiz)
{
    if (raiz)
    {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void imprimirPreOrdem(BST *arvore)
{
    preOrdem(arvore->raiz);
}