#ifndef SISTEMA_TIPOS_H
#define SISTEMA_TIPOS_H

#define MAX_NOME 50
#define MAX_TELEFONE 20
#define MAX_BI 20
#define MAX_MATRICULA 20
#define MAX_MODELO 30
#define MAX_ESTADO 200
#define MAX_CIDADES 100
#define MAX_ROTAS 3000

typedef struct {
    int idCidade;
    char nome[MAX_NOME];
} Cidade;

typedef struct {
    int idRota;
    int origem;
    int destino;
    int distancia;
    int tempoEstimado;
    char estadoVia[MAX_ESTADO];
} Rota;

typedef struct {
    int idVeiculo;
    char matricula[MAX_MATRICULA];
    char modelo[MAX_MODELO];
    int capacidade;
    int lugaresDisponiveis;
    char estado[MAX_ESTADO];
} Veiculo;

typedef struct {
    int idMotorista;
    char nome[MAX_NOME];
    char BI[MAX_BI];
    char telefone[MAX_TELEFONE];
    int cidadeOrigem;
    int cidadeDestino;
    int idVeiculo;
} Motorista;

typedef struct {
    int idPassageiro;
    char nome[MAX_NOME];
    char BI[MAX_BI];
    char telefone[MAX_TELEFONE];
    int cidadeOrigem;
    int cidadeDestino;
} Passageiro;

typedef struct {
    int idViagem;
    int idMotorista;
    int idVeiculo;
    int cidadeOrigem;
    int cidadeDestino;
    int distancia;
    int tempoEstimado;
    float precoEstimado;
    int lugaresDisponiveis;
    char estado[MAX_ESTADO];
} Viagem;

typedef struct {
    int idAdministrador;
    char nome[MAX_NOME];
    char BI[MAX_BI];
    char telefone[MAX_TELEFONE];
} Administrador;

#endif