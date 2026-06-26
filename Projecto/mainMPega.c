#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "grafo.h"
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

int main()
{

    // ainda estamos a testar as funções fora da main
    // antes de colocar aqui na main

    int op = 0;

    limparTela();
    printf("Por motivos maiores, estamos a configurar ainda\n");
    printf("\nas funções e juntando as partes de cada um\npor isso é possivel que veja a ausência\nde funcionalidades no sistem.\n\nMas se notar, algumas funções estão já criadas\nPois está a se fazer a união das partes\n");
    printf("\n\n\n");

    aguardarEnter();
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

        printf(CYAN "║" MAGENTA "  [1]" WHITE " Vizualizar menu Admin                                   " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [2]" WHITE " Vizualizar menu Condutor                                " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [3]" WHITE " Vizualizar menu Passageiro                              " CYAN "║\n" RESET);
        printf(CYAN "║" MAGENTA "  [0]" WHITE " Sair                                                    " CYAN "║\n" RESET);

        printf(CYAN);
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        printf(RESET);

        printf(MAGENTA "\n➜ Escolha uma opção: " RESET);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            menuADM();
            break;
        case 2:
            menuConduto();
            break;

        case 3:
            menuPassageir();
            break;
        default:
            break;
        }
        aguardarEnter();

    } while (op != 0);

    printf("\n\n\n");
    return 0;
}
