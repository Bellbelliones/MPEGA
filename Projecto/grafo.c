#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "tipos.h"

Cidade cidades[MAX_CIDADES];
Rota rotas[MAX_ROTAS];

int totalCidades = 0;
int totalRotas = 0;

int matriz[MAX_CIDADES][MAX_CIDADES];

void inicializarGrafo()
{
    for (int i = 0; i < MAX_CIDADES; i++)
        for (int j = 0; j < MAX_CIDADES; j++)
            matriz[i][j] = 0;
}

int existeCidade(int idCidade)
{
    for (int i = 0; i < totalCidades; i++)
        if (cidades[i].idCidade == idCidade)
            return 1;
    return 0;
}

int procurarCidadePorNome(char nome[])
{
    for (int i = 0; i < totalCidades; i++)
        if (strcmp(cidades[i].nome, nome) == 0)
            return i;
    return -1;
}

int adicionarCidade(Cidade cidade)
{
    if (totalCidades >= MAX_CIDADES)
        return 0;
    if (cidade.idCidade <= 0)
        return 0;
    if (strlen(cidade.nome) == 0)
        return 0;
    if (existeCidade(cidade.idCidade))
        return 0;

    cidades[totalCidades++] = cidade;
    return 1;
}

void listarCidades()
{
    for (int i = 0; i < totalCidades; i++)
        printf("%d - %s\n", cidades[i].idCidade, cidades[i].nome);
}

int existeRota(int origem, int destino)
{
    return matriz[origem][destino] != 0;
}

int adicionarRota(Rota rota)
{
    if (totalRotas >= MAX_ROTAS)
        return 0;

    if (!existeCidade(rota.origem))
        return 0;
    if (!existeCidade(rota.destino))
        return 0;

    if (rota.origem == rota.destino)
        return 0;
    if (rota.distancia <= 0)
        return 0;

    if (existeRota(rota.origem, rota.destino))
        return 0;

    rotas[totalRotas++] = rota;
    matriz[rota.origem][rota.destino] = rota.distancia;

    return 1;
}

int atualizarEstadoVia(int origem, int destino, char novoEstado[])
{
    if (!existeRota(origem, destino))
        return 0;

    for (int i = 0; i < totalRotas; i++)
    {
        if (rotas[i].origem == origem && rotas[i].destino == destino)
        {
            strcpy(rotas[i].estadoVia, novoEstado);
            return 1;
        }
    }
    return 0;
}

void listarRotas()
{
    for (int i = 0; i < totalRotas; i++)
    {
        printf("Rota %d: %d -> %d (%d km)\n",
               rotas[i].idRota,
               rotas[i].origem,
               rotas[i].destino,
               rotas[i].distancia);
    }
}

void dijkstra(int origem, int destino)
{
    if (!existeCidade(origem) || !existeCidade(destino))
        return;

    printf("Dijkstra a executar...\n");
}