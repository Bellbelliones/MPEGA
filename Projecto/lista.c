#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

No* criarNo(Usuario u){
    No *novo = malloc(sizeof(No));
    if(!novo) return NULL;

    novo->user = u;
    novo->prox = NULL;
    return novo;
}

void inserir_Lista(Lista *l, Usuario u){
    No *novo = criarNo(u);

    if(!novo){
        printf("Erro de memoria\n");
        return;
    }

    novo->prox = l->inicio;
    l->inicio = novo;
    l->tam++;
}

No* buscar(Lista *l, int id){
    No *aux = l->inicio;

    while(aux){
        if(aux->user.id == id)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

int remover_Lista(Lista *l, int id){
    No *aux = l->inicio;
    No *ant = NULL;

    while(aux && aux->user.id != id){
        ant = aux;
        aux = aux->prox;
    }

    if(!aux) return 0;

    if(!ant)
        l->inicio = aux->prox;
    else
        ant->prox = aux->prox;

    free(aux);
    l->tam--;

    return 1;
}

void imprimir(Lista *l){
    No *aux = l->inicio;

    while(aux){
        printf("[%d - %s] -> ", aux->user.id, aux->user.nome);
        aux = aux->prox;
    }

    printf("NULL\n");
}