#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

void limparTela();

int main()
{
    /*Lista tabela[TAM];
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

    } while (op != 0);*/
    NoAvl *raiz = NULL;

    raiz = inserirNoAvl(raiz, 10);
    raiz = inserirNoAvl(raiz, 20);
    raiz = inserirNoAvl(raiz, 9);

    printf("\n\n");
    emOrdem(raiz);
    printf("\n\n");
    return 0;
}