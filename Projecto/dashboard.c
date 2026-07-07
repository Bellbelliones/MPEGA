#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "grafo.h"
#include "avl.h"

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

int menuCondutor(Usuario u)
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

int menuAdmin(Lista t[], Usuario u)
{
    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main

    char n[30], e[30], tel[15], s[30];
    int id = 0, acesso = 0;

    int op = 0;
    int escolha = 0;
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