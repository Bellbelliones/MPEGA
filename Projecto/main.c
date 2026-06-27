#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"      // 👈 OBRIGATÓRIO
#include "ficheiros.h"
#include "hash.h"


/* protótipos */
void limparTela();
void cadastrar_usuario(Lista tabela[]);
void fazerLogin(Lista tabela[]);
void inicializarTabela(Lista tabela[]);
void menuGrafos();

int main()
{
    Lista tabela[TAM];
    inicializarTabela(tabela);


    int op;

    do {
        limparTela();

        printf("==========================================\n");
        printf("          SISTEMA DE VIAGENS MPEGA        \n");
        printf("==========================================\n");

        printf(" [1] Criar Nova Conta (Cadastrar)\n");
        printf(" [2] Entrar no Sistema (Login)\n");
        printf(" [3] Gestao de Cidades e Rotas\n");
        printf(" [0] Fechar Aplicativo (Sair)\n");

        printf("------------------------------------------\n");
        printf(" Escolha uma opcao: ");

        scanf("%d", &op);

        switch(op)
        {
            case 1:
                cadastrar_usuario(tabela);
                break;

            case 2:
                fazerLogin(tabela);
                break;

            case 3:
                menuGrafos();
                break;

            case 0:
                limparTela();
                printf("Obrigado por usar o MPEGA!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                getchar(); getchar();
                break;
        }

    } while(op != 0);

    return 0;
}

/* ================= MENU GRAFOS ================= */

void menuGrafos()
{
    int op;

    do
    {
        printf("\n========== GRAFOS ==========\n");
        printf("1 - Adicionar Cidade\n");
        printf("2 - Listar Cidades\n");
        printf("3 - Adicionar Rota\n");
        printf("4 - Listar Rotas\n");
        printf("5 - Dijkstra\n");
        printf("0 - Voltar\n");

        scanf("%d", &op);

        switch(op)
        {
            case 1:
            {
                Cidade c;

                printf("ID: ");
                scanf("%d", &c.idCidade);

                printf("Nome: ");
                scanf(" %[^\n]", c.nome);

                adicionarCidade(c);
                break;
            }

            case 2:
                listarCidades();
                break;

            case 3:
            {
                Rota r;

                printf("ID Rota: ");
                scanf("%d", &r.idRota);

                printf("Origem: ");
                scanf("%d", &r.origem);

                printf("Destino: ");
                scanf("%d", &r.destino);

                printf("Distancia: ");
                scanf("%d", &r.distancia);

                printf("Tempo: ");
                scanf("%d", &r.tempoEstimado);

                printf("Estado: ");
                scanf(" %[^\n]", r.estadoVia);

                adicionarRota(r);
                break;
            }

            case 4:
                listarRotas();
                break;

            case 5:
            {
                int o, d;

                printf("Origem: ");
                scanf("%d", &o);

                printf("Destino: ");
                scanf("%d", &d);

                dijkstra(o, d);
                break;
            }
        }

    } while(op != 0);
}