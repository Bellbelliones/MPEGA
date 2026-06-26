#ifndef AVL_H
#define AVL_H

#include "lista.h"

// Estruturas da AVL
typedef struct noAvl
{
    int chave;
    // Usuario user;
    struct noAvl *esq;
    struct noAvl *dir;
    int altura;
} NoAvl;
typedef struct avl
{
    struct avl *inicio;
} avl;

// Funções da AVL

avl *criarAVL();
NoAvl *criarNoAvl(int valor);
NoAvl *inserirNoAvl(NoAvl *raiz, int valor);
void emOrdem(NoAvl *raiz);

#endif