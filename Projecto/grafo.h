#ifndef grafos_h
#define grafos_h

#include "tipos.h"

#define MAX_CIDADES 100
#define INFINITO 999999

void inicializarGrafo();

/* CIDADES */
int adicionarCidade(Cidade cidade);
int removerCidade(int idCidade);
int existeCidade(int idCidade);
int procurarCidadePorNome(char nome[]);
void listarCidades();

/* ROTAS */
int adicionarRota(Rota rota);
int removerRota(int origem,int destino);
int existeRota(int origem,int destino);
int atualizarEstadoVia(int origem,int destino,char novoEstado[]);
void listarRotas();

/* DIJKSTRA */
void dijkstra(int origem,int destino);

#endif