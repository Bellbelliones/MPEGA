#ifndef AVL_H
#define AVL_H

#include "lista.h"

// Nó da Árvore AVL
typedef struct noAvl {
    Usuario user;         
    struct noAvl *esq;      
    struct noAvl *dir;      
    int altura;             
} NoAvl;

#endif