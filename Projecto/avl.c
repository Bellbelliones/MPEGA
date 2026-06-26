#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

// Criando a avl

AVL *criarAVL(void)
{
    AVL *arvore = (AVL *)malloc(sizeof(AVL));

    if (arvore != NULL)
    {
        arvore->raiz = NULL;
        arvore->tamanho = 0;
    }

    return arvore;
}

// criando o nó

NoAvl *criarNoAVL(int chave)
{
    NoAvl *novo = (NoAvl *)malloc(sizeof(NoAvl));

    if (novo != NULL)
    {
        novo->chave = chave;
        novo->altura = 1;
        novo->esq = NULL;
        novo->dir = NULL;
    }

    return novo;
}

// funcoes auxiliares

int maximoAVL(int a, int b)
{
    return (a > b) ? a : b;
}

int alturaAVL(NoAvl *raiz)
{
    if (raiz == NULL)
        return 0;

    return raiz->altura;
}

int fatorBalanceamento(NoAvl *raiz)
{
    if (raiz == NULL)
        return 0;

    return alturaAVL(raiz->esq) - alturaAVL(raiz->dir);
}

NoAvl *menorNoAVL(NoAvl *raiz)
{
    NoAvl *atual = raiz;

    while (atual != NULL && atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

// area das rotacoes

NoAvl *rotacaoDireita(NoAvl *y)
{
    NoAvl *x = y->esq;
    NoAvl *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = 1 + maximoAVL(
                        alturaAVL(y->esq),
                        alturaAVL(y->dir));

    x->altura = 1 + maximoAVL(
                        alturaAVL(x->esq),
                        alturaAVL(x->dir));

    return x;
}

NoAvl *rotacaoEsquerda(NoAvl *x)
{
    NoAvl *y = x->dir;
    NoAvl *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = 1 + maximoAVL(
                        alturaAVL(x->esq),
                        alturaAVL(x->dir));

    y->altura = 1 + maximoAVL(
                        alturaAVL(y->esq),
                        alturaAVL(y->dir));

    return y;
}

// inserindo na avl

NoAvl *inserirAVL(NoAvl *raiz, int chave)
{
    if (raiz == NULL)
        return criarNoAVL(chave);

    if (chave < raiz->chave)
        raiz->esq = inserirAVL(raiz->esq, chave);

    else if (chave > raiz->chave)
        raiz->dir = inserirAVL(raiz->dir, chave);

    else
        return raiz;

    raiz->altura = 1 + maximoAVL(
                           alturaAVL(raiz->esq),
                           alturaAVL(raiz->dir));

    int fb = fatorBalanceamento(raiz);

    /* Rotacao simples a esquerda */
    if (fb > 1 && chave < raiz->esq->chave)
        return rotacaoDireita(raiz);

    /* Rotacao simples a direita */
    if (fb < -1 && chave > raiz->dir->chave)
        return rotacaoEsquerda(raiz);

    /* Rotacao esquerda, direita */
    if (fb > 1 && chave > raiz->esq->chave)
    {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    /* Rotacao direita, esquerda */
    if (fb < -1 && chave < raiz->dir->chave)
    {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// remoção na avl

NoAvl *removerAVL(NoAvl *raiz, int chave)
{
    if (raiz == NULL)
        return NULL;

    /* Procura o nó */
    if (chave < raiz->chave)
    {
        raiz->esq = removerAVL(raiz->esq, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->dir = removerAVL(raiz->dir, chave);
    }
    else
    {
        // Eu aqui dividi em partes ou casos Delfina e Briana, para poderem entender melhor
        /* Caso 1: Nó sem filhos */
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }

        /* Caso 2: Apenas filho direito */
        if (raiz->esq == NULL)
        {
            NoAvl *temp = raiz->dir;
            free(raiz);
            return temp;
        }

        /* Caso 3: Apenas filho esquerdo */
        if (raiz->dir == NULL)
        {
            NoAvl *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        /* Caso 4: Dois filhos */
        NoAvl *temp = menorNoAVL(raiz->dir);

        raiz->chave = temp->chave;

        raiz->dir = removerAVL(raiz->dir, temp->chave);
    }

    /* Atualiza altura */
    raiz->altura = 1 + maximoAVL(
                           alturaAVL(raiz->esq),
                           alturaAVL(raiz->dir));

    /* Calcula o fator de balanceamento */
    int fb = fatorBalanceamento(raiz);

    /* LL */
    if (fb > 1 && fatorBalanceamento(raiz->esq) >= 0)
        return rotacaoDireita(raiz);

    /* LR */
    if (fb > 1 && fatorBalanceamento(raiz->esq) < 0)
    {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    /* RR */
    if (fb < -1 && fatorBalanceamento(raiz->dir) <= 0)
        return rotacaoEsquerda(raiz);

    /* RL */
    if (fb < -1 && fatorBalanceamento(raiz->dir) > 0)
    {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// BUsca

NoAvl *buscarAVL(NoAvl *raiz, int chave)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->chave == chave)
        return raiz;

    if (chave < raiz->chave)
        return buscarAVL(raiz->esq, chave);

    return buscarAVL(raiz->dir, chave);
}

// Exibição

// Aqui adicionei as 3 formas de exibição que aprendemos em bst

void emOrdem(NoAvl *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);

        printf("%d ", raiz->chave);

        emOrdem(raiz->dir);
    }
}

void preOrdem(NoAvl *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->chave);

        preOrdem(raiz->esq);

        preOrdem(raiz->dir);
    }
}

void posOrdem(NoAvl *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esq);

        posOrdem(raiz->dir);

        printf("%d ", raiz->chave);
    }
}

// vizualização

void mostrarAVL(NoAvl *raiz, int nivel)
{
    if (raiz == NULL)
        return;

    mostrarAVL(raiz->dir, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("    ");

    printf("%d\n", raiz->chave);

    mostrarAVL(raiz->esq, nivel + 1);
}
// utilidades

int contarNos(NoAvl *raiz)
{
    if (raiz == NULL)
        return 0;

    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

int arvoreVazia(NoAvl *raiz)
{
    return raiz == NULL;
}

void destruirAVL(NoAvl *raiz)
{
    if (raiz != NULL)
    {
        destruirAVL(raiz->esq);

        destruirAVL(raiz->dir);

        free(raiz);
    }
}