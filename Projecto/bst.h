#ifndef BST_H
#define BST_H

typedef struct No No;
typedef struct BST BST;

// criação
BST *criarBST();

// operações
void inserir(BST *arvore, int valor);
int buscar(BST *arvore, int valor);
void remover(BST *arvore, int valor);

// utilidades
void imprimirEmOrdem(BST *arvore);
void imprimirPreOrdem(BST *arvore);

#endif