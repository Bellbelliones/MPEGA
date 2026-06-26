#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "menu.h"

// Definindo as cores
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

int menuADM()
{

    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main
    int op = 0;
    int escolha = 0;
    do
    {
        limparTela();
        printf(CYAN);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                              MPEGA                           ║\n");
        printf("║            Sistema Inteligente de Partilha de Viagens        ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf(RESET);

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Gestão de Utilizadores                                  " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Gestão de Rotas                                         " CYAN "║\n" RESET);
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
                printf(CYAN);
                printf("╔══════════════════════════════════════════════════════════════╗\n");
                printf("║                     Gestão de Utilizadores                   ║\n");
                printf("╠══════════════════════════════════════════════════════════════╣\n");
                printf(RESET);

                printf(CYAN "║" MAGENTA "  [1]" WHITE " Registar                                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [2]" WHITE " Procurar                                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [3]" WHITE " Atualizar                                               " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [4]" WHITE " Bloquear / Desbloquear                                  " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [5]" WHITE " Remover                                                 " CYAN "║\n" RESET);
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
                    break;

                case 2:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                      Procura de Utilizador                   ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                case 3:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                     Atualização de Utilizador                ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                case 4:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                  Bloquear / Desbloquear Utilizador           ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                case 5:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                         Remover Utilizador                   ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
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
                printf("║                         Gestão de Rotas                      ║\n");
                printf("╠══════════════════════════════════════════════════════════════╣\n");
                printf(RESET);

                printf(CYAN "║" MAGENTA "  [1]" WHITE " Registar                                                " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [2]" WHITE " Vizualizar Rotas                                        " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [3]" WHITE " Atualizar / Editar                                      " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [4]" WHITE " Consultar Melhor Rota                                   " CYAN "║\n" RESET);
                printf(CYAN "║" MAGENTA "  [5]" WHITE " Remover                                                 " CYAN "║\n" RESET);
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
                    printf("║                          Registo de Rotas                    ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;

                case 2:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                     Vizualização de Rotas                    ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                case 3:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                  Atualização / Edição de Rotas               ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                case 4:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                       Consultar Melhor Rota                  ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
                    break;
                case 5:

                    printf(CYAN);
                    printf("╔══════════════════════════════════════════════════════════════╗\n");
                    printf("║                          Remoção de Rotas                    ║\n");
                    printf("╚══════════════════════════════════════════════════════════════╝\n");
                    printf(RESET);
                    printf("\n\n");
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

int menuConduto()
{

    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main
    int op = 0;
    do
    {
        limparTela();
        printf(CYAN);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                              MPEGA                           ║\n");
        printf("║            Sistema Inteligente de Partilha de Viagens        ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf(RESET);

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Publicar Viagem                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Cancelar Viavem                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [3]" WHITE " Consultar Melhor Rota para o Destino                    " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                    " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                         Publicar Viagem                      ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            aguardarEnter();
            break;
        case 2:
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                         Cancelar Viagem                      ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            aguardarEnter();
            break;
        case 3:
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║            Consultar Melhor Rota para o Destino              ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            aguardarEnter();
            break;
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

int menuPassageir()
{

    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main
    int op = 0;
    do
    {
        limparTela();
        printf(CYAN);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                              MPEGA                           ║\n");
        printf("║            Sistema Inteligente de Partilha de Viagens        ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf(RESET);

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Procurar Viajens                                        " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Cancelar Viagem                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                    " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                         Procurar Viajens                      ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            aguardarEnter();
            break;
        case 2:
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                         Cancelar Viagem                      ║\n");
            printf("╚══════════════════════════════════════════════════════════════╝\n");
            printf(RESET);

            aguardarEnter();
            break;
        case 0:
            printf("Saindo do sistema");
            break;
        default:
            printf("Opcao selecionada invalida\n");
        }
    } while (op != 0);

    printf("\n\n\n");
    return 0;
}