#ifndef FILA_H
#define FILA_H

#include "lista.h" 

// Nó da fila
typedef struct noFila {
    Usuario user;           
    struct noFila *prox;
} NoFila;

// Controlo da Fila
typedef struct {
    NoFila *frente;         
    NoFila *atras;           
    int tamanho;
} Fila;

#endif