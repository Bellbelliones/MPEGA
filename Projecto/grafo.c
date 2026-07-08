#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ficheiros.h"
#include "grafo.h"
#include "tipos.h"

/*=========================================
            VARIÁVEIS GLOBAIS
=========================================*/

Cidade cidades[MAX_CIDADES];
Rota rotas[MAX_ROTAS];

int totalCidades = 0;
int totalRotas = 0;

/* Matriz de adjacência.
   Guarda a distância entre duas cidades.
   0 significa que não existe ligação. */
int matriz[MAX_CIDADES][MAX_CIDADES];

/*=========================================
        INICIALIZAÇÃO DO GRAFO
=========================================*/

void inicializarGrafo()
{
    int i, j;

    for (i = 0; i < MAX_CIDADES; i++)
    {
        for (j = 0; j < MAX_CIDADES; j++)
        {
            matriz[i][j] = 0;
        }
    }

    totalCidades = 0;
    totalRotas = 0;
}

/*=========================================
        VALIDAÇÕES DAS CIDADES
=========================================*/

/* Verifica se o ID existe */
int existeCidade(int idCidade)
{
    int i;
    for (i = 0; i < totalCidades; i++)
    {
        if (cidades[i].idCidade == idCidade)
        {
            return 1;
        }
    }
    return 0;
}

/* Verifica se já existe uma cidade com o mesmo nome */
int existeCidadeNome(char nome[])
{
    int i;
    for (i = 0; i < totalCidades; i++)
    {
        if (strcmp(cidades[i].nome, nome) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/* Procura a posição da cidade no vetor */
int procurarCidadePorNome(char nome[])
{
    int i;
    for (i = 0; i < totalCidades; i++)
    {
        if (strcmp(cidades[i].nome, nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

/*=========================================
        ADICIONAR CIDADE
=========================================*/

int adicionarCidade(Cidade cidade)
{
    if (totalCidades >= MAX_CIDADES)
    {
        printf("Limite de cidades atingido.\n");
        return 0;
    }

    if (cidade.idCidade <= 0)
    {
        printf("ID inválido.\n");
        return 0;
    }

    if (strlen(cidade.nome) == 0)
    {
        printf("Nome obrigatório.\n");
        return 0;
    }

    if (existeCidade(cidade.idCidade))
    {
        printf("Já existe uma cidade com este código.\n");
        return 0;
    }

    if (existeCidadeNome(cidade.nome))
    {
        printf("Já existe uma cidade com este nome.\n");
        return 0;
    }

    cidades[totalCidades] = cidade;
    totalCidades++;

    printf("Cidade cadastrada com sucesso.\n");
    guardarCidades();
    return 1;
}

/*=========================================
        REMOVER CIDADE
=========================================*/

int removerCidade(int idCidade)
{
    int i, j, k;

    if (!existeCidade(idCidade))
    {
        printf("Cidade não encontrada.\n");
        return 0;
    }

    for (i = 0; i < totalCidades; i++)
    {
        if (cidades[i].idCidade == idCidade)
        {
            // 1. Remover da matriz de adjacência todas as rotas ligadas a esta cidade
            for (j = 0; j < totalCidades; j++)
            {
                matriz[i][j] = 0;
                matriz[j][i] = 0;
            }

            // Deslocar as linhas e colunas seguintes na matriz para alinhar com o vetor descido
            for (j = i; j < totalCidades - 1; j++)
            {
                for (k = 0; k < totalCidades; k++)
                {
                    matriz[j][k] = matriz[j + 1][k];
                }
            }
            for (j = i; j < totalCidades - 1; j++)
            {
                for (k = 0; k < totalCidades; k++)
                {
                    matriz[k][j] = matriz[k][j + 1];
                }
            }

            // 2. Remover do vetor de rotas qualquer rota que fizesse uso desta cidade
            for (j = 0; j < totalRotas; j++)
            {
                if (strcmp(rotas[j].origem, cidades[i].nome) == 0 || strcmp(rotas[j].destino, cidades[i].nome) == 0)
                {
                    for (k = j; k < totalRotas - 1; k++)
                    {
                        rotas[k] = rotas[k + 1];
                    }
                    totalRotas--;
                    j--;
                }
            }

            // 3. Deslocar o vetor de cidades
            for (j = i; j < totalCidades - 1; j++)
            {
                cidades[j] = cidades[j + 1];
            }

            totalCidades--;
            printf("Cidade e as suas rotas associadas removidas com sucesso.\n");
            guardarCidades();
            guardarRotas();
            return 1;
        }
    }

    return 0;
}

/*=========================================
        LISTAR CIDADES
=========================================*/

void listarCidades()
{
    int i;

    if (totalCidades == 0)
    {
        printf("\nNenhuma cidade cadastrada.\n");
        return;
    }

    printf("\n========== CIDADES ==========\n");

    for (i = 0; i < totalCidades; i++)
    {
        printf("Código: %d\n", cidades[i].idCidade);
        printf("Nome  : %s\n", cidades[i].nome);
        printf("-----------------------------\n");
    }
}

/*=========================================
        VALIDAÇÕES DAS ROTAS
=========================================*/

/* Verifica se o código da rota (String) já existe */
int existeCodigoRota(char idRota[])
{
    int i;
    for (i = 0; i < totalRotas; i++)
    {
        if (strcmp(rotas[i].idRota, idRota) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/* CORRIGIDO: Removidas as anotações textuais inválidas do compilador */
int estadoValido(char estado[])
{
    if (strcmp(estado, "Boa") == 0 || strcmp(estado, "Razoável") == 0 ||
        strcmp(estado, "Má") == 0 || strcmp(estado, "Interditada") == 0)
        return 1;

    return 0;
}

/* Verifica se já existe uma rota entre origem e destino */
int existeRota(char origem[], char destino[])
{
    int i;
    for (i = 0; i < totalRotas; i++)
    {
        if (strcmp(rotas[i].origem, origem) == 0 &&
            strcmp(rotas[i].destino, destino) == 0)
        {
            return 1;
        }
    }
    return 0;
}

/*=========================================
            ADICIONAR ROTA
=========================================*/

int adicionarRota(Rota rota)
{
    int posOrigem;
    int posDestino;

    if (totalRotas >= MAX_ROTAS)
    {
        printf("Limite de rotas atingido.\n");
        return 0;
    }

    if (strlen(rota.idRota) == 0)
    {
        printf("Código da rota inválido/obrigatório.\n");
        return 0;
    }

    if (existeCodigoRota(rota.idRota))
    {
        printf("Já existe uma rota com este código.\n");
        return 0;
    }

    if (strlen(rota.origem) == 0 || strlen(rota.destino) == 0)
    {
        printf("Origem e destino são obrigatórios.\n");
        return 0;
    }

    /* CORRIGIDO: Limpos os lixos de texto estrutural */
    if (strcmp(rota.origem, rota.destino) == 0)
    {
        printf("Origem e destino não podem ser iguais.\n");
        return 0;
    }

    if (!existeCidadeNome(rota.origem))
    {
        printf("Cidade de origem inexistente.\n");
        return 0;
    }

    if (!existeCidadeNome(rota.destino))
    {
        printf("Cidade de destino inexistente.\n");
        return 0;
    }

    if (existeRota(rota.origem, rota.destino))
    {
        printf("Esta rota já está cadastrada.\n");
        return 0;
    }

    if (rota.distancia <= 0)
    {
        printf("Distância inválida.\n");
        return 0;
    }

    if (rota.tempoEstimado <= 0)
    {
        printf("Tempo estimado inválido.\n");
        return 0;
    }

    if (!estadoValido(rota.estadoVia))
    {
        printf("Estado da via inválido.\n");
        return 0;
    }

    posOrigem = procurarCidadePorNome(rota.origem);
    posDestino = procurarCidadePorNome(rota.destino);

    rotas[totalRotas] = rota;
    totalRotas++;

    matriz[posOrigem][posDestino] = rota.distancia;

    printf("Rota cadastrada com sucesso.\n");
    guardarRotas();
    return 1;
}

/*=========================================
            REMOVER ROTA
=========================================*/

int removerRota(char origem[], char destino[])
{
    int i, j;
    int posOrigem, posDestino;

    if (!existeRota(origem, destino))
    {
        printf("Rota não encontrada.\n");
        return 0;
    }

    posOrigem = procurarCidadePorNome(origem);
    posDestino = procurarCidadePorNome(destino);

    matriz[posOrigem][posDestino] = 0;

    for (i = 0; i < totalRotas; i++)
    {
        if (strcmp(rotas[i].origem, origem) == 0 &&
            strcmp(rotas[i].destino, destino) == 0)
        {
            for (j = i; j < totalRotas - 1; j++)
            {
                rotas[j] = rotas[j + 1];
            }

            totalRotas--;
            guardarRotas();
            printf("Rota removida com sucesso.\n");
            return 1;
        }
    }

    return 0;
}

/*=========================================
        ATUALIZAR ESTADO DA VIA
=========================================*/

int atualizarEstadoVia(char origem[], char destino[], char novoEstado[])
{
    int i;

    if (!estadoValido(novoEstado))
    {
        printf("Estado inválido.\n");
        return 0;
    }

    for (i = 0; i < totalRotas; i++)
    {
        if (strcmp(rotas[i].origem, origem) == 0 &&
            strcmp(rotas[i].destino, destino) == 0)
        {
            strcpy(rotas[i].estadoVia, novoEstado);
            guardarRotas();
            printf("Estado da via atualizado com sucesso.\n");
            return 1;
        }
    }

    printf("Rota não encontrada.\n");
    return 0;
}

/*=========================================
            LISTAR ROTAS
=========================================*/

void listarRotas()
{
    int i;

    if (totalRotas == 0)
    {
        printf("\nNenhuma rota cadastrada.\n");
        return;
    }

    printf("\n========== ROTAS ==========\n");

    for (i = 0; i < totalRotas; i++)
    {
        printf("Código : %s\n", rotas[i].idRota);
        printf("Origem : %s\n", rotas[i].origem);
        printf("Destino: %s\n", rotas[i].destino);
        printf("Distância: %d km\n", rotas[i].distancia);
        printf("Tempo: %d minutos\n", rotas[i].tempoEstimado);
        printf("Estado: %s\n", rotas[i].estadoVia);
        printf("-----------------------------------\n");
    }
}

/*=========================================
            MOSTRAR MATRIZ
=========================================*/

void mostrarMatriz()
{
    int i, j;

    if (totalCidades == 0)
    {
        printf("\nNenhuma cidade cadastrada.\n");
        return;
    }

    printf("\n=========== MATRIZ DE ADJACÊNCIA ===========\n\n");
    printf("%15s", "");

    for (i = 0; i < totalCidades; i++)
    {
        printf("%15s", cidades[i].nome);
    }
    printf("\n");

    for (i = 0; i < totalCidades; i++)
    {
        printf("%15s", cidades[i].nome);
        for (j = 0; j < totalCidades; j++)
        {
            printf("%15d", matriz[i][j]);
        }
        printf("\n");
    }
}

/*=========================================
            EXISTE CAMINHO
=========================================*/

int existeCaminho(char origem[], char destino[])
{
    int o = procurarCidadePorNome(origem);
    int d = procurarCidadePorNome(destino);

    if (o == -1 || d == -1)
        return 0;

    if (matriz[o][d] != 0)
        return 1;

    return 0;
}

/*=========================================
              DIJKSTRA
=========================================*/

void dijkstra(char origem[], char destino[])
{
    int origemIndex = procurarCidadePorNome(origem);
    int destinoIndex = procurarCidadePorNome(destino);

    int distancia[MAX_CIDADES];
    int visitado[MAX_CIDADES];
    int anterior[MAX_CIDADES];

    int i, j, menor, u;

    if (origemIndex == -1)
    {
        printf("Cidade de origem inexistente.\n");
        return;
    }

    if (destinoIndex == -1)
    {
        printf("Cidade de destino inexistente.\n");
        return;
    }

    for (i = 0; i < totalCidades; i++)
    {
        distancia[i] = INFINITO;
        visitado[i] = 0;
        anterior[i] = -1;
    }

    distancia[origemIndex] = 0;

    for (i = 0; i < totalCidades - 1; i++)
    {
        menor = INFINITO;
        u = -1;

        for (j = 0; j < totalCidades; j++)
        {
            if (!visitado[j] && distancia[j] < menor)
            {
                menor = distancia[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visitado[u] = 1;

        for (j = 0; j < totalCidades; j++)
        {
            if (matriz[u][j] > 0 && !visitado[j] &&
                distancia[u] + matriz[u][j] < distancia[j])
            {
                distancia[j] = distancia[u] + matriz[u][j];
                anterior[j] = u;
            }
        }
    }

    if (distancia[destinoIndex] == INFINITO)
    {
        printf("\nNão existe caminho disponível entre %s e %s.\n", origem, destino);
        return;
    }

    printf("\n========== MELHOR ROTA ==========\n");
    printf("Origem : %s\n", origem);
    printf("Destino: %s\n", destino);
    printf("Distância Total: %d km\n", distancia[destinoIndex]);
    printf("\nPercurso:\n");

    int caminho[MAX_CIDADES];
    int contador = 0;
    int atual = destinoIndex;

    while (atual != -1)
    {
        caminho[contador++] = atual;
        atual = anterior[atual];
    }

    for (i = contador - 1; i >= 0; i--)
    {
        printf("%s", cidades[caminho[i]].nome);
        if (i != 0)
            printf(" -> ");
    }
    printf("\n");
}
