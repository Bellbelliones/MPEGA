#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ficheiros.h"
#include "hash.h"
#include "grafo.h"
#include "viagem.h"

// funcoes de usuario
void guardarUsuarios(Lista t[])
{
    FILE *fp = fopen("usuarios.txt", "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < TAM; i++)
    {
        No *aux = t[i].inicio;

        while (aux != NULL)
        {
            fprintf(fp,
                    "%d;%s;%s;%s;%s;%d;%d\n",
                    aux->user.id,
                    aux->user.nome,
                    aux->user.telefone,
                    aux->user.email,
                    aux->user.senha,
                    aux->user.tipo,
                    aux->user.estado);

            aux = aux->prox;
        }
    }

    fclose(fp);
}
void carregarUsuarios(Lista t[])
{
    FILE *fp = fopen("usuarios.txt", "r");

    if (fp == NULL)
        return;

    Usuario u;

    while (fscanf(fp,
                  "%d;%49[^;];%19[^;];%99[^;];%29[^;];%d;%d\n",
                  &u.id,
                  u.nome,
                  u.telefone,
                  u.email,
                  u.senha,
                  &u.tipo,
                  &u.estado) == 7)
    {
        inserir_usuario(t, u);
    }

    fclose(fp);
}
// Funcoes das cidades, rotas e viagens

void guardarCidades()
{
    FILE *fp = fopen("cidades.txt", "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < totalCidades; i++)
    {
        fprintf(fp, "%d;%s\n",
                cidades[i].idCidade,
                cidades[i].nome);
    }

    fclose(fp);
}
void carregarCidades()
{
    FILE *fp = fopen("cidades.txt", "r");

    if (fp == NULL)
    {
        printf("ERRO: nao foi possivel abrir cidades.txt\n");
        return;
    }

    printf("Ficheiro aberto com sucesso!\n");

    Cidade c;

    while (fscanf(fp, "%d;%49[^\n]",
                  &c.idCidade,
                  c.nome) == 2)
    {
        printf("Lida cidade: %d - %s\n", c.idCidade, c.nome);

        adicionarCidade(c);
    }

    fclose(fp);

    printf("Total cidades = %d\n", totalCidades);
}
void guardarRotas()
{
    FILE *fp = fopen("rotas.txt", "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < totalRotas; i++)
    {
        fprintf(fp,
                "%s;%s;%s;%d;%d;%s\n",
                rotas[i].idRota,
                rotas[i].origem,
                rotas[i].destino,
                rotas[i].distancia,
                rotas[i].tempoEstimado,
                rotas[i].estadoVia);
    }

    fclose(fp);
}
void carregarRotas()
{
    FILE *fp = fopen("rotas.txt", "r");

    if (fp == NULL)
        return;

    totalRotas = 0;

    inicializarGrafo(); // limpa apenas a matriz

    Rota r;

    while (fscanf(fp,
                  "%19[^;];%49[^;];%49[^;];%d;%d;%199[^\n]",
                  r.idRota,
                  r.origem,
                  r.destino,
                  &r.distancia,
                  &r.tempoEstimado,
                  r.estadoVia) == 6)
    {
        rotas[totalRotas] = r;

        int origem = procurarCidadePorNome(r.origem);
        int destino = procurarCidadePorNome(r.destino);

        if (origem != -1 && destino != -1)
        {
            matriz[origem][destino] = r.distancia;
        }
        printf("Rota de %s para %s adicionada\n", r.origem, r.destino);
        totalRotas++;
    }

    fclose(fp);
}

// PARA CONTROLE DE VIAGENS
void guardarViagens()
{
    FILE *fp = fopen("viagens.txt", "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < totalViagens; i++)
    {
        fprintf(fp,
                "%d;%d;%d;%s;%s;%d;%d;%.2f;%d;%s\n",
                viagens[i].idViagem,
                viagens[i].idMotorista,
                viagens[i].idVeiculo,
                viagens[i].cidadeOrigem,
                viagens[i].cidadeDestino,
                viagens[i].distancia,
                viagens[i].tempoEstimado,
                viagens[i].precoEstimado,
                viagens[i].lugaresDisponiveis,
                viagens[i].estado);
    }

    fclose(fp);
}
void carregarViagens()
{
    FILE *fp = fopen("viagens.txt", "r");

    if (fp == NULL)
        return;

    totalViagens = 0;

    while (fscanf(fp,
                  "%d;%d;%d;%49[^;];%49[^;];%d;%d;%f;%d;%199[^\n]\n",
                  &viagens[totalViagens].idViagem,
                  &viagens[totalViagens].idMotorista,
                  &viagens[totalViagens].idVeiculo,
                  viagens[totalViagens].cidadeOrigem,
                  viagens[totalViagens].cidadeDestino,
                  &viagens[totalViagens].distancia,
                  &viagens[totalViagens].tempoEstimado,
                  &viagens[totalViagens].precoEstimado,
                  &viagens[totalViagens].lugaresDisponiveis,
                  viagens[totalViagens].estado) == 10)
    {
        printf("Viagem do usuario de id %d\n carregada com sucesso\n", viagens[totalViagens].idMotorista);
        viagens[totalViagens].listaPassageiros = NULL;
        totalViagens++;
    }

    fclose(fp);
}
/*Reserva de viagens*/
void guardarReservas()
{
    FILE *fp = fopen("reservas.txt", "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < totalViagens; i++)
    {
        NoPassageiro *aux = viagens[i].listaPassageiros;

        while (aux != NULL)
        {
            fprintf(fp, "%d;%d\n",
                    viagens[i].idViagem,
                    aux->idPassageiro);

            aux = aux->prox;
        }
    }

    fclose(fp);
}
void carregarReservas()
{
    FILE *fp = fopen("reservas.txt", "r");

    if (fp == NULL)
        return;

    int idViagem;
    int idPassageiro;

    while (fscanf(fp, "%d;%d\n",
                  &idViagem,
                  &idPassageiro) == 2)
    {
        Viagem *v = buscarViagem(idViagem);

        if (v != NULL)
        {
            NoPassageiro *novo =
                (NoPassageiro *)malloc(sizeof(NoPassageiro));

            if (novo != NULL)
            {
                novo->idPassageiro = idPassageiro;

                novo->prox = v->listaPassageiros;

                v->listaPassageiros = novo;
            }
        }
    }

    fclose(fp);
}
