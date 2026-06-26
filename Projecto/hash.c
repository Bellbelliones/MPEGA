#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// Definicao de cores

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

// ======= FUNÇÂO AUXILIAR ==============================
// Função auxiliar para limpar a tela de forma multiplataforma
void limparTela()
{
    system("cls");
    system("clear");
}

// Função auxiliar para pausar a tela e dar feedback ao utilizador
void aguardarEnter()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

//================ HASH TABLE =============================
void inicializarTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        inicializar(&t[i]);
    }
}

int funcaoHash(int id)
{
    return id % TAM;
}

void inserir_usuario(Lista t[], Usuario u)
{
    int pos = funcaoHash(u.id);
    inserir_Lista(&t[pos], u);
}

No *buscarUsuario(Lista t[], int id)
{
    int pos = funcaoHash(id);
    return buscar(&t[pos], id);
}

int remover(Lista t[], int id)
{
    int pos = funcaoHash(id);
    return remover_Lista(&t[pos], id);
}

void imprimirTabela(Lista t[])
{
    limparTela();
    printf("==========================================\n");
    printf("         ESTADO DA TABELA HASH            \n");
    printf("==========================================\n");
    for (int i = 0; i < TAM; i++)
    {
        if (t[i].tam > 0)
        { // Mostra apenas as posições ocupadas para não poluir o terminal
            printf(" Posicao [%03d]: ", i);
            imprimir(&t[i]);
        }
    }
    printf("==========================================\n");
    aguardarEnter();
}

// ================== FUNCÕES DO USUARIO ========================
void cadastrar_usuario(Lista t[])
{
    Usuario u;
    limparTela();
    printf("==========================================\n");
    printf("          CADASTRO DE NOVO USUARIO        \n");
    printf("==========================================\n");

    printf(" ID do Usuario: ");
    scanf("%d", &u.id);

    printf(" Nome Completo: ");
    scanf("\n%49[^\n]", u.nome);

    printf(" Email de Acesso: ");
    scanf("\n%99[^\n]", u.email);

    printf(" Numero de telefone: ");
    scanf("\n%19s", u.telefone);

    printf(" Senha Segura: ");
    scanf("\n%29[^\n]", u.senha);

    printf(" Tipo (1-Passageiro | 2-Condutor | 3-Admin): ");
    scanf("%d", &u.tipo);

    inserir_usuario(t, u);

    printf("\n==========================================\n");
    printf(" >>> USUARIO CADASTRADO COM SUCESSO! <<<\n");
    printf("==========================================\n");
    aguardarEnter();
}

void menuPassageiro(Usuario u)
{
    int op;
    do
    {
        limparTela();
        printf("==========================================\n");
        printf("   PAINEL DO PASSAGEIRO - MPEGA           \n");
        printf("==========================================\n");
        printf(" Olá, %s! Seja bem-vindo de volta.\n\n", u.nome);
        printf(" [1] Procurar Viagens Disponiveis\n");
        printf(" [2] Reservar uma Nova Viagem\n");
        printf(" [3] Visualizar Minhas Reservas\n");
        printf(" [0] Fazer Logout (Sair)\n");
        printf("------------------------------------------\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &op);

        if (op != 0 && op != 1 && op != 2 && op != 3)
        {
            printf("\n Opcao Invalida! Tente novamente.");
            aguardarEnter();
        }
        else if (op != 0)
        {
            printf("\n Entrando na funcionalidade %d... (Funcionalidade em desenvolvimento)", op);
            aguardarEnter();
        }
    } while (op != 0);

    printf("\n Efetuando logout da conta de Passageiro...\n");
    aguardarEnter();
}

void menuCondutor(Usuario u)
{
    int op;
    do
    {
        limparTela();
        printf("==========================================\n");
        printf("    PAINEL DO CONDUTOR - MPEGA            \n");
        printf("==========================================\n");
        printf(" Olá, Condutor %s!\n\n", u.nome);
        printf(" [1] Publicar Nova Oferta de Viagem\n");
        printf(" [2] Visualizar Lista de Passageiros\n");
        printf(" [3] Cancelar Viagem Publicada\n");
        printf(" [0] Fazer Logout (Sair)\n");
        printf("------------------------------------------\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &op);

        if (op != 0 && op != 1 && op != 2 && op != 3)
        {
            printf("\n Opcao Invalida! Tente novamente.");
            aguardarEnter();
        }
        else if (op != 0)
        {
            printf("\n Entrando na funcionalidade %d... (Funcionalidade em desenvolvimento)", op);
            aguardarEnter();
        }
    } while (op != 0);

    printf("\n Efetuando logout da conta de Condutor...\n");
    aguardarEnter();
}

void menuAdmin(Usuario u)
{
    int op = 0;
    int escolha = 0;
    do
    {
        limparTela();
        printf("Usuario: %s\n\n", u.nome);
        printf(CYAN);
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                     SISTEMA DE VIAGENS                       ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                 Desenvolvido por: GRUPO 13                   ║\n");
        printf(RESET);

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Gestão de Utilizadores                                  " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Gestão de Veículos                                      " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [3]" WHITE " Gestão de Rotas                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [4]" WHITE " Publicar Viagem                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [5]" WHITE " Procurar Viagem                                         " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [6]" WHITE " Reservar Lugar                                          " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [7]" WHITE " Aprovar Passageiros                                     " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [8]" WHITE " Consultar Melhor Rota                                   " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [9]" WHITE " Relatórios                                              " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                    " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);
        switch (op)
        {
        case 1:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                     Gestão de Utilizadores                       ║\n");
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
                printf("║                            Atualizar                         ║\n");
                printf("╚══════════════════════════════════════════════════════════════╝\n");
                printf(RESET);
                printf("\n\n");
                break;
            case 4:

                printf(CYAN);
                printf("╔══════════════════════════════════════════════════════════════╗\n");
                printf("║                      Bloquear / Desbloquear                  ║\n");
                printf("╚══════════════════════════════════════════════════════════════╝\n");
                printf(RESET);
                printf("\n\n");
                break;
            case 5:

                printf(CYAN);
                printf("╔══════════════════════════════════════════════════════════════╗\n");
                printf("║                             Remover                          ║\n");
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
            break;
        case 2:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                        Gestão de Veiculos                    ║\n");
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
            break;
        case 3:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                        Gestão de Rotas                       ║\n");
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
            break;
        case 4:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                        Publicar Viagens                      ║\n");
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
            break;
        case 5:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                       Procurar Viagens                       ║\n");
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
            break;
        case 6:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                        Reservar Lugar                        ║\n");
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
            break;
        case 7:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                     Aprovar Passageiros                      ║\n");
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
            break;
        case 8:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                     Consultar Melhor Rota                    ║\n");
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
            break;
        case 9:

            printf("Usuario: %s\n\n", u.nome);
            printf(CYAN);
            printf("╔══════════════════════════════════════════════════════════════╗\n");
            printf("║                           Relatórios                         ║\n");
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
            break;
        case 0:
            printf("Saindo do sistema");
            break;
        default:
            printf("Opcao selecionada invalida\n");
        }
    } while (op != 0);

    aguardarEnter();
}

Usuario *login(Lista t[], char email[], char senha[])
{
    for (int i = 0; i < TAM; i++)
    {
        No *aux = t[i].inicio;
        while (aux)
        {
            if (strcmp(aux->user.email, email) == 0 &&
                strcmp(aux->user.senha, senha) == 0)
            {
                return &aux->user;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}

void fazerLogin(Lista t[])
{
    char email[100];
    char senha[30];

    limparTela();
    printf("==========================================\n");
    printf("         AUTENTICACAO DE USUARIO          \n");
    printf("==========================================\n");

    printf(" Digite seu Email: ");
    scanf("%99s", email);

    printf(" Digite sua Senha: ");
    scanf("%29s", senha);

    Usuario *u = login(t, email, senha);

    if (u == NULL)
    {
        printf("\n==========================================\n");
        printf(" [ERRO] Login invalido! Email ou Senha incorretos.\n");
        printf("==========================================\n");
        aguardarEnter();
        return;
    }

    printf("\n==========================================\n");
    printf(" >>> LOGIN EFETUADO COM SUCESSO! <<<\n");
    printf(" Redirecionando para o menu...\n");
    printf("==========================================\n");
    aguardarEnter();

    switch (u->tipo)
    {
    case 1:
        menuPassageiro(*u);
        break;
    case 2:
        menuCondutor(*u);
        break;
    case 3:
        menuAdmin(*u);
        break;
    default:
        printf("Erro crítico: Tipo de usuario nao reconhecido!\n");
        aguardarEnter();
        break;
    }
}
void sessao()
{
    Lista tabela[TAM];
    inicializarTabela(tabela);

    int op;

    do
    {
        limparTela();
        printf("==========================================\n");
        printf("          SISTEMA DE VIAGENS MPEGA        \n");
        printf("==========================================\n");
        printf(" [1] Criar Nova Conta (Cadastrar)\n");
        printf(" [2] Entrar no Sistema (Login)\n");
        printf(" [0] Fechar Aplicativo (Sair)\n");
        printf("------------------------------------------\n");
        printf(" Escolha uma opcao: ");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrar_usuario(tabela);
            break;
        case 2:
            fazerLogin(tabela);
            break;
        case 0:
            limparTela();
            printf("==========================================\n");
            printf("  Obrigado por usar o MPEGA. Ate a proxima! \n");
            printf("==========================================\n");
            break;
        default:
            printf("\nOpcao invalida! Pressione qualquer tecla para tentar...");
            getchar();
            getchar();
            break;
        }

    } while (op != 0);
}