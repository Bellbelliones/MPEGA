#ifndef GRAFO_H
#define GRAFO_H

// 1. Representa a ligação (Aresta) para outra cidade
typedef struct adjacencia {
    int vertice_destino;     // ID da cidade de destino
    float preco;             // Peso da aresta (ex: custo da viagem)
    float distancia;         // Outro peso opcional (ex: quilómetros)
    struct adjacencia *prox; // Próxima ligação desta mesma cidade de origem
} Adjacencia;

// 2. Representa a estrutura de cada Cidade (Vértice)
typedef struct {
    int id;                  // ID único da cidade
    char nome[60];           // Nome da localidade/ponto de paragem
    Adjacencia *inicio;      // Ponteiro para a lista de cidades vizinhas
} Vertice;

// 3. Estrutura Principal do Grafo
typedef struct {
    int num_vertices;        // Total de cidades cadastradas
    int max_vertices;        // Limite máximo alocado para o array
    Vertice *vertices;       // Array (ponteiro) que vai conter as cidades
} Grafo;

#endif