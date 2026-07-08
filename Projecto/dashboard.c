#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "viagem.h"
#include "grafo.h"

// Definindo as cores
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
// ================== INTERFACE DO USUARIO ========================

int menuPassageiro(Usuario u)
{
    int op;

    do
    {
        limparTela();

        printf(CYAN);
        printf("Usuario: %s\n", u.nome);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                              MPEGA                           ║\n");
        printf("║            Sistema Inteligente de Partilha de Viagens        ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf(RESET);

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Procurar Viagens                                       " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Reservar Lugar                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [3]" WHITE " Cancelar Reserva                                       " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                   " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                     PROCURAR VIAGENS                        ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            procurarViagem();

            aguardarEnter();
            break;
        }

        case 2:
        {
            int idViagem;

            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                         RESERVAR LUGAR                       ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            listarViagens();

            printf("\nID da Viagem: ");
            scanf("%d", &idViagem);

            reservarLugar(idViagem, u.id);

            aguardarEnter();
            break;
        }

        case 3:
        {
            int idViagem;

            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                    CANCELAR RESERVA                         ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            listarViagens();

            printf("\nID da Viagem: ");
            scanf("%d", &idViagem);

            cancelarReserva(idViagem, u.id);

            aguardarEnter();
            break;
        }

        case 0:
        {
            printf("\nA sair...\n");
            break;
        }

        default:
        {
            printf("\nOpção inválida!\n");
            aguardarEnter();
        }
        }

    } while (op != 0);

    return 0;
}
int menuCondutor(Lista t[], Usuario u)
{
    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main
    int op = 0;
    do
    {
        limparTela();
        printf(CYAN);
        printf("Usuario: %s\n", u.nome);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                              MPEGA                           ║\n");
        printf("║            Sistema Inteligente de Partilha de Viagens        ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf(RESET);
        printf(CYAN "║" MAGENTA "  [1]" WHITE " Publicar Nova Viagem                                   " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Listar Minhas Viagens                                  " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [3]" WHITE " Ver Passageiros de uma Viagem                          " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [4]" WHITE " Iniciar Viagem                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [5]" WHITE " Terminar Viagem                                        " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [6]" WHITE " Cancelar / Remover Viagem                              " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [7]" WHITE " Consultar Melhor Rota                                  " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                   " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            Viagem v;

            limparTela();

            printf("=========== PUBLICAR VIAGEM ===========\n\n");

            printf("ID da Viagem: ");
            scanf("%d", &v.idViagem);

            v.idMotorista = u.id;

            printf("ID do Veículo: ");
            scanf("%d", &v.idVeiculo);

            printf("Cidade de Origem: ");
            scanf(" %49[^\n]", v.cidadeOrigem);

            printf("Cidade de Destino: ");
            scanf(" %49[^\n]", v.cidadeDestino);

            printf("Distância: ");
            scanf("%d", &v.distancia);

            printf("Tempo Estimado: ");
            scanf("%d", &v.tempoEstimado);

            printf("Preço: ");
            scanf("%f", &v.precoEstimado);

            printf("Lugares Disponíveis: ");
            scanf("%d", &v.lugaresDisponiveis);

            strcpy(v.estado, "Disponível");

            v.listaPassageiros = NULL;

            publicarViagem(v);

            aguardarEnter();

            break;
        }
        case 2:

            listarMinhasViagens(u.id);

            aguardarEnter();

            break;
        case 3:
        {
            int idViagem;

            listarMinhasViagens(u.id);

            printf("\nID da Viagem: ");
            scanf("%d", &idViagem);

            listarPassageiros(t, idViagem);

            aguardarEnter();

            break;
        }
        case 4:
        {
            int id;

            listarMinhasViagens(u.id);

            printf("\nID da Viagem: ");
            scanf("%d", &id);

            iniciarViagem(id);

            aguardarEnter();

            break;
        }
        case 5:
        {
            int id;

            listarMinhasViagens(u.id);

            printf("\nID da Viagem: ");
            scanf("%d", &id);

            terminarViagem(id);

            aguardarEnter();

            break;
        }
        case 6:
        {
            int id;

            listarMinhasViagens(u.id);

            printf("\nID da Viagem: ");
            scanf("%d", &id);

            removerViagem(id);

            aguardarEnter();

            break;
        }
        case 7:
        {
            char origem[MAX_NOME];
            char destino[MAX_NOME];

            printf("\nOrigem: ");
            scanf(" %49[^\n]", origem);

            printf("Destino: ");
            scanf(" %49[^\n]", destino);

            dijkstra(origem, destino);

            aguardarEnter();

            break;
        }
        case 0:
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                           Saindo...                          ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            break;
        }
    } while (op != 0);

    printf("\n\n\n");
    return 0;
}

int menuAdmin(Lista t[], Usuario u)
{

    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main

    char n[30], e[30], tel[15], s[30];
    int id = 0, acesso = 0;

    char origem[50];
    char destino[50];
    char estado[30];
    int op = 0;
    int escolha = 0;
    int decisao = 0;
    do
    {
        limparTela();
        printf(CYAN);
        printf("Usuario: %s\n", u.nome);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                              MPEGA                           ║\n");
        printf("║            Sistema Inteligente de Partilha de Viagens        ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf(RESET);

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Gestão de Utilizadores                                  " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Gestão de Rotas & Vias                                  " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                    " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            do
            {
                limparTela();
                printf(CYAN);
                printf("╔══════════════════════════════════════════════════════════════╗\n");
                printf("║                     Gestão de Utilizadores                   ║\n");
                printf("╠══════════════════════════════════════════════════════════════╣\n");
                printf(RESET);

                printf(CYAN "║" MAGENTA "  [1]" WHITE " Registar                                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [2]" WHITE " Procurar                                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [3]" WHITE " Mostrar                                                 " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [4]" WHITE " Atualizar                                               " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [5]" WHITE " Bloquear / Desbloquear                                  " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [6]" WHITE " Remover                                                 " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                    " CYAN "║\n" RESET);

                printf(CYAN);
                printf("╚══════════════════════════════════════════════════════════════╝\n");
                printf(RESET);

                printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                      Registo de Utilizador                   ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    cadastrar_usuario(t);
                    break;

                case 2:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                      Procura de Utilizador                   ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    printf("Por favor digite o id de usuário: ");
                    scanf("%d", &id);
                    if (id >= 0)
                    {
                        exibirUsuario(t, id);
                    }
                    else
                        printf("Não existe um usuário com o id que você digitou\n");
                    break;
                case 3:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                       Mostrar Utilizadores                   ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    imprimirTabela(t);
                    break;
                case 4:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                     Atualização de Utilizador                ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    printf("Digite o id do usuário: ");
                    scanf("%d", &id);
                    if (buscarUsuario(t, id))
                    {
                        printf("Digite o novo nome: ");
                        scanf("\n%[^\n]", n);
                        printf("Digite o novo e-mail: ");
                        scanf("\n%[^\n]", e);
                        printf("Digite o novo numero de telefone: ");
                        scanf("\n%[^\n]", tel);
                        printf("Digite a nova senha: ");
                        scanf("\n%[^\n]", s);
                        while (acesso < 1 || acesso > 3)
                        {
                            printf("Selecione o novo acesso\n1 - Passageiro\n2 - Condutor\n3 - Administrador\nR: ");
                            scanf("%d", &acesso);
                            switch (acesso)
                            {
                            case 1:
                                printf("Nivel Passageiro Selecionado\n");
                                break;
                            case 2:
                                printf("Nivel Condutor SelecionCondutorado\n");
                                break;
                            case 3:
                                printf("Nivel Administrador Selecionado\n");
                                break;

                            default:
                                printf("Por favor selecione um nivel condizente\n");
                            }
                        }
                        if (atualizarUsuario(t, id, n, tel, e, s, acesso) == -1)
                            printf("Erro ao atualizar o usuario\n");
                        else
                            printf("Atualização bem sucessedida\n");
                    }
                    else
                    {
                        printf("Usuario Não encontrado\n");
                    }
                    break;
                case 5:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                  Bloquear / Desbloquear Utilizador           ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    printf("Digite o id do usuario: ");
                    scanf("%d", &id);
                    if (id >= 0)
                    {
                        int index = bloquearDesbloquearUsuario(t, id);
                        if (index == -1)
                            printf("O usuario não foi encontrado\n");
                        else if (index == 1)
                            printf("O usuario foi desbloquado");
                        else if (index == 2)
                            printf("O usuario foi bloquado");
                    }
                    else
                    {
                        printf("O id nunca pode ser menor que 0\n");
                    }
                    break;
                case 6:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                         Remover Utilizador                   ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    printf("Digite o id do usuário: ");
                    scanf("%d", &id);
                    int index = removerUsuario(t, id);
                    if (index == 0)
                        printf("Usuario não encontrado\n");
                    else if (index == 1)
                        printf("Usuario removido com sucesso\n");

                    break;
                case 0:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                          Voltando...                         ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                }
                aguardarEnter();
            } while (escolha != 0);
            break;
        case 2:

            do
            {
                printf(CYAN);
                printf("╔══════════════════════════════════════════════════════════════╗\n");
                printf("║                     Gestão de Rotas/Cidades                  ║\n");
                printf("╠══════════════════════════════════════════════════════════════╣\n");
                printf(RESET);

                printf(CYAN "║" MAGENTA "  [1]" WHITE " Registar                                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [2]" WHITE " Vizualizar                                              " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [3]" WHITE " Atualizar Estado Da Rota                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [4]" WHITE " Consultar Melhor Caminho                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [5]" WHITE " Remover                                                 " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [0]" WHITE " Voltar                                                  " CYAN "║\n" RESET);

                printf(CYAN);
                printf("╚══════════════════════════════════════════════════════════════╝\n");
                printf(RESET);

                printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1:
                    do
                    {
                        printf(CYAN);
                        printf("╔══════════════════════════════════════════════════════════════╗\n");
                        printf("║                  Resgistar de Rotas/Cidades                  ║\n");
                        printf("╠══════════════════════════════════════════════════════════════╣\n");
                        printf(RESET);

                        printf(CYAN "║" MAGENTA "  [1]" WHITE " Cidade                                                  " CYAN "║\n" RESET);
                        printf(CYAN "║" MAGENTA "  [2]" WHITE " Rotas                                                   " CYAN "║\n" RESET);
                        printf(CYAN "║" MAGENTA "  [0]" WHITE " Voltar                                                  " CYAN "║\n" RESET);

                        printf(CYAN);
                        printf("╚══════════════════════════════════════════════════════════════╝\n");
                        printf(RESET);
                        printf("R: ");
                        scanf("%d", &decisao);
                        switch (decisao)
                        {
                        case 1:
                            Cidade c;

                            limparTela();

                            printf(CYAN);
                            printf("╔══════════════════════════════════════════════════════════════╗\n");
                            printf("║                  REGISTO DE CIDADE                          ║\n");
                            printf("╚══════════════════════════════════════════════════════════════╝\n");
                            printf(RESET);

                            printf("\nCódigo da Cidade: ");
                            scanf("%d", &c.idCidade);

                            getchar(); // limpa o ENTER do scanf

                            printf("Nome da Cidade: ");
                            scanf("\n%49[^\n]", c.nome);

                            if (adicionarCidade(c))
                                printf(GREEN "\nCidade registada com sucesso!\n" RESET);
                            else
                                printf(RED "\nNão foi possível registar a cidade.\n" RESET);

                            break;

                        case 2:
                            Rota r;

                            printf(CYAN);
                            printf("╔══════════════════════════════════════════════════════════════╗\n");
                            printf("║                    REGISTO DE ROTAS                          ║\n");
                            printf("╚══════════════════════════════════════════════════════════════╝\n");
                            printf(RESET);
                            printf("ID Rota: ");
                            scanf("\n%[^\n]", r.idRota);

                            printf("Origem: ");
                            scanf("\n%[^\n]", r.origem);

                            printf("Destino: ");
                            scanf("\n%[^\n]", r.destino);

                            printf("Distancia: ");
                            scanf("%d", &r.distancia);

                            printf("Tempo: ");
                            scanf("%d", &r.tempoEstimado);

                            printf("Estado: ( Boa, Razoável, Má, Interditada): ");
                            scanf(" \n%[^\n]", r.estadoVia);

                            adicionarRota(r);
                            break;

                        case 0:

                            printf("VOTANDO...\n");
                            break;

                        default:
                            printf("Rota registada com sucesso!!!\n");
                        }
                    } while (decisao != 0);
                    break;

                case 2:
                    do
                    {
                        printf(CYAN);
                        printf("╔══════════════════════════════════════════════════════════════╗\n");
                        printf("║                         Vizualização                         ║\n");
                        printf("╠══════════════════════════════════════════════════════════════╣\n");
                        printf(RESET);

                        printf(CYAN "║" MAGENTA "  [1]" WHITE " Cidade                                                  " CYAN "║\n" RESET);
                        printf(CYAN "║" MAGENTA "  [2]" WHITE " Rotas                                                   " CYAN "║\n" RESET);
                        printf(CYAN "║" MAGENTA "  [0]" WHITE " Voltar                                                  " CYAN "║\n" RESET);

                        printf(CYAN);
                        printf("╚══════════════════════════════════════════════════════════════╝\n");
                        printf(RESET);
                        printf("\n\n");
                        scanf("%d", &decisao);
                        switch (decisao)
                        {
                        case 1:

                            printf(CYAN);
                            printf("╔══════════════════════════════════════════════════════════════╗\n");
                            printf("║                    LISTAGEM DE CIDADE                        ║\n");
                            printf("╚══════════════════════════════════════════════════════════════╝\n");
                            printf(RESET);
                            listarCidades();
                            break;
                        case 2:

                            printf(CYAN);
                            printf("╔══════════════════════════════════════════════════════════════╗\n");
                            printf("║                    LISTAGEM DE ROTA                          ║\n");
                            printf("╚══════════════════════════════════════════════════════════════╝\n");
                            printf(RESET);
                            listarRotas();
                            break;

                        default:
                            break;
                        }
                    } while (decisao != 0);
                    break;
                case 3:

                    limparTela();

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                 ATUALIZAR ESTADO DA VIA                     ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);

                    listarRotas();

                    printf("\nOrigem: ");
                    scanf("\n%49[^\n]", origem);

                    printf("Destino: ");
                    scanf("\n%49[^\n]", destino);

                    printf("\nEstados disponíveis:\n");
                    printf(" - Boa\n");
                    printf(" - Razoável\n");
                    printf(" - Má\n");
                    printf(" - Interditada\n");

                    printf("\nNovo Estado: ");
                    scanf("\n%29[^\n]", estado);

                    atualizarEstadoVia(origem, destino, estado);
                    break;
                case 4:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                         MELHOR CAMINHO                       ║\n");
                    printf("╠══════════════════════════════════════════════════════════════╣\n");
                    printf("Cidade de Origem: ");
                    scanf(" %49[^\n]", origem);

                    printf("Cidade de Destino: ");
                    scanf(" %49[^\n]", destino);

                    dijkstra(origem, destino);

                    break;
                    break;
                case 5:
                    do
                    {
                        printf(CYAN);
                        printf("╔══════════════════════════════════════════════════════════════╗\n");
                        printf("║                          REMOÇÂO                             ║\n");
                        printf("╠══════════════════════════════════════════════════════════════╣\n");
                        printf(RESET);

                        printf(CYAN "║" MAGENTA "  [1]" WHITE " Cidade                                                  " CYAN "║\n" RESET);
                        printf(CYAN "║" MAGENTA "  [2]" WHITE " Rotas                                                   " CYAN "║\n" RESET);
                        printf(CYAN "║" MAGENTA "  [0]" WHITE " Voltar                                                  " CYAN "║\n" RESET);

                        printf(CYAN);
                        printf("╚══════════════════════════════════════════════════════════════╝\n");
                        printf(RESET);
                        printf("\n\n");
                        scanf("%d", &decisao);
                        switch (decisao)
                        {
                        case 1:

                            int idCidade;

                            limparTela();

                            printf(CYAN);
                            printf("╔══════════════════════════════════════════════╗\n");
                            printf("║             REMOVER CIDADE                   ║\n");
                            printf("╚══════════════════════════════════════════════╝\n");
                            printf(RESET);

                            listarCidades();

                            printf("\nCódigo da Cidade: ");
                            scanf("%d", &idCidade);

                            if (removerCidade(idCidade))
                                ;
                            else
                                printf(RED "\nNão foi possível remover a cidade.\n" RESET);

                            break;
                        case 2:

                            limparTela();

                            printf(CYAN);
                            printf("╔══════════════════════════════════════════════╗\n");
                            printf("║              REMOVER ROTA                    ║\n");
                            printf("╚══════════════════════════════════════════════╝\n");
                            printf(RESET);

                            listarRotas();

                            printf("\nOrigem: ");
                            scanf("\n%49[^\n]", origem);

                            printf("Destino: ");
                            scanf("\n%49[^\n]", destino);

                            if (removerRota(origem, destino))
                                printf(GREEN "\nRota removida com sucesso!\n" RESET);
                            else
                                printf(RED "\nRota não encontrada.\n" RESET);
                            break;

                        default:
                            break;
                        }
                    } while (decisao != 0);
                    break;
                case 0:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                          Voltando...                         ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                }
                aguardarEnter();
            } while (escolha != 0);
            break;
        case 0:
            printf("Saindo do sistema");
            break;
        default:
            printf("Opcao selecionada invalida\n");
        }
    } while (op != 0);

    aguardarEnter();
    printf("\n\n\n");
    return 0;
}
