#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "viagem.h"
#include "grafo.h"
#include "tipos.h"
#include "ficheiros.h"
Viagem viagens[MAX_VIAGENS];

int totalViagens = 0;
int condutorPossuiViagemAtiva(int idMotorista)
{
    for (int i = 0; i < totalViagens; i++)
    {
        if (viagens[i].idMotorista == idMotorista &&
            strcmp(viagens[i].estado, "Terminada") != 0 &&
            strcmp(viagens[i].estado, "Cancelada") != 0)
        {
            return 1;
        }
    }

    return 0;
}
int publicarViagem(Viagem viagem)
{
    if (totalViagens >= MAX_VIAGENS)
    {
        printf("\nLimite de viagens atingido.\n");
        return 0;
    }

    viagens[totalViagens] = viagem;

    totalViagens++;
    guardarViagens();
    printf("\nViagem publicada com sucesso!\n");

    return 1;
}
void listarViagens()
{
    int i;

    if (totalViagens == 0)
    {
        printf("\nNenhuma viagem publicada.\n");
        return;
    }

    printf("\n=========== VIAGENS ===========\n");

    for (i = 0; i < totalViagens; i++)
    {
        printf("\nCódigo...........: %d", viagens[i].idViagem);

        printf("\nMotorista........: %d", viagens[i].idMotorista);

        printf("\nOrigem...........: %s", viagens[i].cidadeOrigem);

        printf("\nDestino..........: %s", viagens[i].cidadeDestino);

        printf("\nDistância........: %d km", viagens[i].distancia);

        printf("\nTempo............: %d minutos", viagens[i].tempoEstimado);

        printf("\nPreço............: %.2f kz", viagens[i].precoEstimado);

        printf("\nLugares..........: %d", viagens[i].lugaresDisponiveis);

        printf("\nEstado...........: %s", viagens[i].estado);

        printf("\n-----------------------------------------\n");
    }
}
void procurarViagem(Lista t[])
{
    char origem[MAX_NOME];
    char destino[MAX_NOME];

    int i;
    int encontrou = 0;

    printf("\n===========================================\n");
    printf("          PROCURAR VIAGEM\n");
    printf("===========================================\n");

    printf("Origem: ");
    scanf(" %49[^\n]", origem);

    printf("Destino: ");
    scanf(" %49[^\n]", destino);

    printf("\n========== RESULTADOS ==========\n");

    for (i = 0; i < totalViagens; i++)
    {
        if (strcmp(viagens[i].cidadeOrigem, origem) == 0 &&
            strcmp(viagens[i].cidadeDestino, destino) == 0)
        {
            encontrou = 1;

            printf("\nCódigo........: %d", viagens[i].idViagem);
            No *motorista = buscarUsuario(t, viagens[i].idMotorista);

            if (motorista != NULL)
            {
                printf("\nMotorista.....: %s", motorista->user.nome);
                printf("\nTelefone......: %s", motorista->user.telefone);
            }
            else
            {
                printf("\nMotorista.....: Não encontrado");
            }
            printf("\nOrigem........: %s", viagens[i].cidadeOrigem);
            printf("\nDestino.......: %s", viagens[i].cidadeDestino);
            printf("\nPreço.........: %.2f Kz", viagens[i].precoEstimado);
            printf("\nDistância.....: %d km", viagens[i].distancia);
            printf("\nTempo.........: %d minutos", viagens[i].tempoEstimado);
            printf("\nLugares.......: %d", viagens[i].lugaresDisponiveis);
            printf("\nEstado........: %s", viagens[i].estado);

            printf("\n------------------------------------------\n");
        }
    }

    if (!encontrou)
    {
        printf("\nNenhuma viagem encontrada.\n");
    }
}
Viagem *buscarViagem(int idViagem)
{
    int i;

    for (i = 0; i < totalViagens; i++)
    {
        if (viagens[i].idViagem == idViagem)
        {
            return &viagens[i];
        }
    }

    return NULL;
}
int reservarLugar(int idViagem, int idPassageiro)
{
    Viagem *viagem = buscarViagem(idViagem);

    if (viagem == NULL)
    {
        printf("\nViagem não encontrada.\n");
        return 0;
    }

    if (viagem->lugaresDisponiveis <= 0)
    {
        printf("\nEsta viagem encontra-se cheia.\n");
        return 0;
    }

    NoPassageiro *aux = viagem->listaPassageiros;

    while (aux != NULL)
    {
        if (aux->idPassageiro == idPassageiro)
        {
            printf("\nEste passageiro já possui uma reserva.\n");
            return 0;
        }

        aux = aux->prox;
    }

    NoPassageiro *novo =
        (NoPassageiro *)malloc(sizeof(NoPassageiro));

    if (novo == NULL)
    {
        printf("\nErro de memória.\n");
        return 0;
    }

    novo->idPassageiro = idPassageiro;

    novo->prox = NULL;

    if (viagem->listaPassageiros == NULL)
    {
        viagem->listaPassageiros = novo;
    }
    else
    {
        aux = viagem->listaPassageiros;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    viagem->lugaresDisponiveis--;
    guardarReservas();
    printf("\nReserva efectuada com sucesso!\n");
    guardarViagens();
    return 1;
}
int cancelarReserva(int idViagem, int idPassageiro)
{
    Viagem *viagem = buscarViagem(idViagem);

    if (viagem == NULL)
    {
        printf("\nViagem não encontrada.\n");
        return 0;
    }

    NoPassageiro *atual = viagem->listaPassageiros;
    NoPassageiro *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->idPassageiro == idPassageiro)
        {
            if (anterior == NULL)
            {
                viagem->listaPassageiros = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);

            viagem->lugaresDisponiveis++;
            guardarViagens();
            guardarReservas();
            printf("\nReserva cancelada com sucesso.\n");

            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("\nReserva não encontrada.\n");

    return 0;
}

void listarPassageiros(Lista t[], int idViagem)
{
    Viagem *viagem = buscarViagem(idViagem);

    if (viagem == NULL)
    {
        printf("\nViagem não encontrada.\n");
        return;
    }

    if (viagem->listaPassageiros == NULL)
    {
        printf("\nEsta viagem ainda não possui passageiros.\n");
        return;
    }

    NoPassageiro *aux = viagem->listaPassageiros;

    printf("\n");
    printf("═══════════════════════════════════════════════\n");
    printf("        PASSAGEIROS DA VIAGEM %d\n", idViagem);
    printf("═══════════════════════════════════════════════\n");

    while (aux != NULL)
    {
        No *u = buscarUsuario(t, aux->idPassageiro);

        if (u != NULL)
        {
            printf("ID.............: %d\n", u->user.id);
            printf("Nome...........: %s\n", u->user.nome);
            printf("Telefone.......: %s\n", u->user.telefone);
            printf("Email..........: %s\n", u->user.email);
            printf("----------------------------------------------\n");
        }

        aux = aux->prox;
    }
}
int iniciarViagem(int idViagem)
{
    Viagem *viagem = buscarViagem(idViagem);

    if (viagem == NULL)
    {
        printf("\nViagem não encontrada.\n");
        return 0;
    }

    if (strcmp(viagem->estado, "Em Curso") == 0)
    {
        printf("\nEsta viagem já foi iniciada.\n");
        return 0;
    }

    if (strcmp(viagem->estado, "Terminada") == 0)
    {
        printf("\nEsta viagem já terminou.\n");
        return 0;
    }

    strcpy(viagem->estado, "Em Curso");
    guardarViagens();
    printf("\nViagem iniciada com sucesso.\n");

    return 1;
}
int terminarViagem(int idViagem)
{
    Viagem *viagem = buscarViagem(idViagem);

    if (viagem == NULL)
    {
        printf("\nViagem não encontrada.\n");
        return 0;
    }

    if (strcmp(viagem->estado, "Terminada") == 0)
    {
        guardarViagens();
        printf("\nEsta viagem já foi terminada.\n");
        return 0;
    }

    strcpy(viagem->estado, "Terminada");

    printf("\nViagem terminada com sucesso!\n");

    return 1;
}
void listarMinhasViagens(int idMotorista)
{
    int encontrou = 0;

    printf("\n==============================================\n");
    printf("            MINHAS VIAGENS\n");
    printf("==============================================\n");

    for (int i = 0; i < totalViagens; i++)
    {
        if (viagens[i].idMotorista == idMotorista)
        {
            encontrou = 1;

            printf("\nID................: %d", viagens[i].idViagem);
            printf("\nOrigem...........: %s", viagens[i].cidadeOrigem);
            printf("\nDestino..........: %s", viagens[i].cidadeDestino);
            printf("\nPreço............: %.2f Kz", viagens[i].precoEstimado);
            printf("\nLugares..........: %d", viagens[i].lugaresDisponiveis);
            printf("\nEstado...........: %s", viagens[i].estado);

            printf("\n------------------------------------------\n");
        }
    }

    if (!encontrou)
    {
        printf("\nAinda não publicou nenhuma viagem.\n");
    }
}
int removerViagem(int idViagem)
{
    int i;

    for (i = 0; i < totalViagens; i++)
    {
        if (viagens[i].idViagem == idViagem)
        {
            for (int j = i; j < totalViagens - 1; j++)
            {
                viagens[j] = viagens[j + 1];
            }

            totalViagens--;
            guardarViagens();
            printf("\nViagem removida com sucesso.\n");

            return 1;
        }
    }

    printf("\nViagem não encontrada.\n");

    return 0;
}
