#ifndef HASH_H
#define HASH_H

#include "lista.h"

#define TAM 101

// ================= HASH TABLE =================
void inicializarTabela(Lista t[]);
int funcaoHash(int id);

void inserir_usuario(Lista t[], Usuario u);
No *buscarUsuario(Lista t[], int id);
int atualizarUsuario(Lista t[], int id, char *nome, char *telemovel, char *email, char *senha, int acesso);
int removerUsuario(Lista t[], int id);
int bloquearDesbloquearUsuario(Lista t[], int id);
void imprimirTabela(Lista t[]);
void exibirUsuario(Lista t[], int id);

// ========== Funções de controlo do sistema ==========
void cadastrar_usuario(Lista t[]);
Usuario *login(Lista t[], char email[], char senha[]);
void fazerLogin(Lista t[]);
void sessao(Lista t[]);

// ================= Auxiliares =================
void limparTela();
void aguardarEnter();

#endif