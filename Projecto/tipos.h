#ifndef TIPOS_H
#define TIPOS_H

/* =========================================
               CONSTANTES
========================================= */
#define MAX_NOME 50
#define MAX_TELEFONE 20
#define MAX_BI 20
#define MAX_MATRICULA 20
#define MAX_MODELO 30
#define MAX_ESTADO 200
#define MAX_CIDADES 100
#define MAX_ROTAS 3000
#define MAX_ID 20

/* =========================================
                 ESTRUTURAS
========================================= */

/* ==========================
           CIDADE
   ========================== */
typedef struct
{
    int idCidade;
    char nome[MAX_NOME];
} Cidade;

/* ==========================
            ROTA
   ========================== */
typedef struct
{
    char idRota[MAX_ID];    // Alterado para String (Código único)
    char origem[MAX_NOME];  // CORRIGIDO: String para armazenar o nome da cidade de origem
    char destino[MAX_NOME]; // CORRIGIDO: String para armazenar o nome da cidade de destino
    int distancia;
    int tempoEstimado;
    char estadoVia[MAX_ESTADO]; // Estado: "Boa", "Razoável", "Má" ou "Interditada"[cite: 1]
} Rota;

/* ==========================
          VEÍCULO
   ========================== */
typedef struct
{
    int idVeiculo;
    char matricula[MAX_MATRICULA];
    char modelo[MAX_MODELO];
    int capacidade;
    int lugaresDisponiveis;
    char estado[MAX_ESTADO]; // Estado: "Vazio", "Disponível", "Quase Lotado", "Cheio"[cite: 1]
} Veiculo;

/* ==========================
         VIAGEM
   ========================== */

typedef struct NoPassageiro
{
    int idPassageiro;
    struct NoPassageiro *prox;

} NoPassageiro;
typedef struct
{
    int idViagem;

    int idMotorista;

    int idVeiculo;

    char cidadeOrigem[MAX_NOME];

    char cidadeDestino[MAX_NOME];

    int distancia;

    int tempoEstimado;

    float precoEstimado;

    int lugaresDisponiveis;

    char estado[MAX_ESTADO];
    NoPassageiro *listaPassageiros;
} Viagem;

#endif
