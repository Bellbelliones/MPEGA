#ifndef GRAFO_H
#define GRAFO_H

#include "tipos.h"

#define INFINITO 999999
extern Cidade cidades[MAX_CIDADES];

extern Rota rotas[MAX_ROTAS];

extern int totalCidades;

extern int totalRotas;

extern int matriz[MAX_CIDADES][MAX_CIDADES];

/*=========================================
            INICIALIZAÇÃO DO GRAFO
=========================================*/

void inicializarGrafo();

/*=========================================
            CIDADES (VÉRTICES)
=========================================*/

/* Adiciona uma nova cidade no vetor em memória */
int adicionarCidade(Cidade cidade);

/* Remove uma cidade, limpa as suas rotas na matriz e reorganiza os índices */
int removerCidade(int idCidade);

/* Verifica se uma cidade existe através do seu ID numérico */
int existeCidade(int idCidade);

/* Verifica se uma cidade existe através do seu Nome (String) */
int existeCidadeNome(char nome[]);

/* Retorna o índice correspondente da cidade no vetor para uso na Matriz */
int procurarCidadePorNome(char nome[]);

/* Lista todas as cidades cadastradas no ecrã */
void listarCidades();

/*=========================================
            ROTAS (ARESTAS)
=========================================*/

/* Adiciona uma nova rota ligando duas cidades por nome e atualiza a matriz */
int adicionarRota(Rota rota);

/* Remove a rota entre duas cidades e zera o valor na matriz de adjacência */
int removerRota(char origem[], char destino[]);

/* Verifica se já existe uma rota direta cadastrada entre duas cidades (por Nome) */
int existeRota(char origem[], char destino[]);

/* VALIDAÇÃO: Verifica se o código identificador da rota (String) já existe */
int existeCodigoRota(char idRota[]);

/* Atualiza o estado da via ("Boa", "Razoável", "Má" ou "Interditada") */
int atualizarEstadoVia(char origem[], char destino[], char novoEstado[]);

/* Valida se o texto introduzido condiz com as opções de estado aceites pelo sistema */
int estadoValido(char estado[]);

/* Lista todas as rotas registadas com os seus respetivos dados e estados */
void listarRotas();

/*=========================================
          ALGORITMOS E MATRIZ
=========================================*/

/* Algoritmo de Dijkstra: Calcula e exibe o caminho mais rápido/curto entre duas cidades */
void dijkstra(char origem[], char destino[]);

/* Verifica se existe alguma ligação na matriz entre as duas cidades */
int existeCaminho(char origem[], char destino[]);

/* Exibe visualmente a Matriz de Adjacência com as distâncias entre todas as cidades */
void mostrarMatriz();

#endif