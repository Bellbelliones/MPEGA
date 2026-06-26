#ifndef LISTA_H
#define LISTA_H

typedef struct
{
    int id;
    char telefone[20];
    char nome[50];
    char email[100];
    char senha[30];
    int tipo;
} Usuario;

typedef struct no
{
    Usuario user;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

void inicializar(Lista *l);
void inserir_Lista(Lista *l, Usuario u);
No *buscar(Lista *l, int id);
int remover_Lista(Lista *l, int id);
void imprimir(Lista *l);

#endif