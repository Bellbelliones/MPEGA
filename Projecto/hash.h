#ifndef HASH_H
#define HASH_H
#include "lista.h"
#define TAM 101

void inicializarTabela(Lista t[]);
int funcaoHash(int id);

void inserir_usuario(Lista t[], Usuario u);
No *buscarUsuario(Lista t[], int id);
int remover(Lista t[], int id);
void imprimirTabela(Lista t[]);

// Funções de controle do sistema (Cadastro, Menus e Login)
void cadastrar_usuario(Lista t[]);
void fazerLogin(Lista t[]);

// Menus
void menuPassageiro(Usuario u);
void menuAdmin(Usuario u);
void menuCondutor(Usuario u);
void sessao();

Usuario *login(Lista t[], char email[], char senha[]);

#endif