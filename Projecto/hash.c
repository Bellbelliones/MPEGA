#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
// ======= FUNÇÂO AUXILIAR ==============================
// Função auxiliar para limpar a tela de forma multiplataforma 
void limparTela() {
        system("cls");
    system("clear");

}

// Função auxiliar para pausar a tela e dar feedback ao utilizador
void aguardarEnter() {
    printf("\nPressione ENTER para continuar...");
    getchar(); 
    getchar(); 
}


//================ HASH TABLE =============================
void inicializarTabela(Lista t[]){
    for(int i = 0; i < TAM; i++){
        inicializar(&t[i]);
    }
}

int funcaoHash(int id){
    return id % TAM;
}

void inserir_usuario(Lista t[], Usuario u){
    int pos = funcaoHash(u.id);
    inserir_Lista(&t[pos], u);
}

No* buscarUsuario(Lista t[], int id){
    int pos = funcaoHash(id);
    return buscar(&t[pos], id);
}

int remover(Lista t[], int id){
    int pos = funcaoHash(id);
    return remover_Lista(&t[pos], id);
}

void imprimirTabela(Lista t[]){
    limparTela();
    printf("==========================================\n");
    printf("         ESTADO DA TABELA HASH            \n");
    printf("==========================================\n");
    for(int i = 0; i < TAM; i++){
        if(t[i].tam > 0) { // Mostra apenas as posições ocupadas para não poluir o terminal
            printf(" Posicao [%03d]: ", i);
            imprimir(&t[i]);
        }
    }
    printf("==========================================\n");
    aguardarEnter();
}



// ================== FUNCÕES DO USUARIO ========================
void cadastrar_usuario(Lista t[]) {
    Usuario u;
    limparTela();
    printf("==========================================\n");
    printf("          CADASTRO DE NOVO USUARIO        \n");
    printf("==========================================\n");

    printf(" ID do Usuario: ");
    scanf("%d", &u.id);

    printf(" Nome Completo: ");
    scanf("%49s", u.nome);

    printf(" Email de Acesso: ");
    scanf("%99s", u.email);

    printf(" Telefone de Contacto: ");
    scanf("%19s", u.telefone); 

    printf(" Senha Segura: ");
    scanf("%29s", u.senha);

    printf(" Tipo (1-Passageiro | 2-Condutor | 3-Admin): ");
    scanf("%d", &u.tipo);

    inserir_usuario(t, u);
    
    printf("\n==========================================\n");
    printf(" >>> USUARIO CADASTRADO COM SUCESSO! <<<\n");
    printf("==========================================\n");
    aguardarEnter();
}



void menuPassageiro(Usuario u){
    int op;
    do {
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

        if(op != 0 && op != 1 && op != 2 && op != 3) {
            printf("\n Opcao Invalida! Tente novamente.");
            aguardarEnter();
        } else if (op != 0) {
            printf("\n Entrando na funcionalidade %d... (Funcionalidade em desenvolvimento)", op);
            aguardarEnter();
        }
    } while(op != 0);
    
    printf("\n Efetuando logout da conta de Passageiro...\n");
    aguardarEnter();
}



void menuCondutor(Usuario u){
    int op;
    do {
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

        if(op != 0 && op != 1 && op != 2 && op != 3) {
            printf("\n Opcao Invalida! Tente novamente.");
            aguardarEnter();
        } else if (op != 0) {
            printf("\n Entrando na funcionalidade %d... (Funcionalidade em desenvolvimento)", op);
            aguardarEnter();
        }
    } while(op != 0);

    printf("\n Efetuando logout da conta de Condutor...\n");
    aguardarEnter();
}


void menuAdmin(Usuario u){
    int op;
    do {
        limparTela();
        printf("==========================================\n");
        printf("     PAINEL DE ADMINISTRACAO - MPEGA       \n");
        printf("==========================================\n");
        printf(" Modo Administrador: %s\n\n", u.nome);
        printf(" [1] Gerir Utilizadores Cadastrados\n");
        printf(" [2] Remover Utilizador do Sistema\n");
        printf(" [3] Gerir Rotas e Destinos\n");
        printf(" [0] Fazer Logout (Sair)\n");
        printf("------------------------------------------\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &op);

        if(op != 0 && op != 1 && op != 2 && op != 3) {
            printf("\n Opcao Invalida! Tente novamente.");
            aguardarEnter();
        } else if (op != 0) {
            printf("\n Entrando na funcionalidade %d... (Funcionalidade em desenvolvimento)", op);
            aguardarEnter();
        }
    } while(op != 0);

    printf("\n Efetuando logout do Modo Administrador...\n");
    aguardarEnter();
}

Usuario* login(Lista t[], char email[], char senha[]){
    for(int i = 0; i < TAM; i++){
        No *aux = t[i].inicio;
        while(aux){
            if(strcmp(aux->user.email, email) == 0 &&
               strcmp(aux->user.senha, senha) == 0){
                return &aux->user; 
            }
            aux = aux->prox;
        }
    }
    return NULL;
}


void fazerLogin(Lista t[]){
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

    if(u == NULL){
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

    switch(u->tipo){
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