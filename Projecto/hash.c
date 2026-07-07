#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dashboard.h"
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

int atualizarUsuario(Lista t[], int id, char *nome, char *telemovel, char *email, char *senha, int acesso)
{
    No *encontrado = buscarUsuario(t, id);

    if (!encontrado)
        return -1; // Negativo significa falha

    strcpy(encontrado->user.nome, nome);
    strcpy(encontrado->user.telefone, telemovel);
    strcpy(encontrado->user.email, email);
    strcpy(encontrado->user.senha, senha);
    encontrado->user.tipo = acesso;

    return 0; // Significa sucesso
}
int removerUsuario(Lista t[], int id)
{
    int pos = funcaoHash(id);
    return remover_Lista(&t[pos], id);
}
int bloquearDesbloquearUsuario(Lista t[], int id)
{
    No *encontrado = buscarUsuario(t, id);

    if (!encontrado)
        return -1; // Negativo significa falha

    if (encontrado->user.estado == 0)
    {
        encontrado->user.estado = 1;
        return 1; // foi desbloquado
    }
    else
    {
        encontrado->user.estado = 0;
        return 2; // foi bloquado
    }
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

    u.estado = 1; // por padrão ele guarda o estado como 1 que simboliza que está ativo
    inserir_usuario(t, u);

    printf("\n==========================================\n");
    printf(" >>> USUARIO CADASTRADO COM SUCESSO! <<<\n");
    printf("==========================================\n");
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
        menuAdmin(t, *u);
        break;
    default:
        printf("Erro crítico: Tipo de usuario nao reconhecido!\n");
        aguardarEnter();
        break;
    }
}
void sessao(Lista t[])
{

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
            cadastrar_usuario(t);
            break;
        case 2:
            fazerLogin(t);
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
void exibirUsuario(Lista t[], int id)
{
    No *getUsuario = buscarUsuario(t, id);
    printf("\n\n");

    printf("══════════════════════════════════════════════════════════════\n");
    printf("Nome: %s\n", getUsuario->user.nome);
    printf("══════════════════════════════════════════════════════════════\n");
    printf("Telefone: %s\n", getUsuario->user.telefone);
    printf("══════════════════════════════════════════════════════════════\n");
    printf("E-mail: %s\n", getUsuario->user.email);
    printf("══════════════════════════════════════════════════════════════\n");
    printf("Nivel de Acesso: ");
    switch (getUsuario->user.tipo)
    {
    case 1:
        printf("Passageiro\n");
        break;
    case 2:
        printf("Condutor\n");
        break;
    case 3:
        printf("Administrador\n");
        break;
    }
    printf("══════════════════════════════════════════════════════════════\n");
    printf("Estado: ");
    switch (getUsuario->user.estado)
    {
    case 1:
        printf("Ativo\n");
        break;
    case 0:
        printf("Inativo\n");
        break;
    default:
        printf("Erro irreconhecivel\n");
        break;
    }
    printf("══════════════════════════════════════════════════════════════\n\n");
}
