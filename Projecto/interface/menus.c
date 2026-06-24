#include <stdio.h>
#include "../include/mpega.h"
void menu(int tipo)
{
    switch (tipo)
    {
    case 1:
        printf("Aqui fica o menu principal\n");
        break;
    case 2:
        printf("outro menu\n");
        break;
    case 3:
        printf("╔══════════════════════════════════════════════════════════════╗\n");
        printf("║                          MPEGA                               ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║                                                              ║\n");
        printf("║                  USE O MELHOR JEITO                          ║\n");
        printf("║            DE SE DESLOCAR SEM COMPLICAÇÕES                   ║\n");
        printf("║              DE FORMA RÁPIDA E EFICIENTE                     ║\n");
        printf("║                                                              ║\n");
        printf("╠══════════════════════════════════════════════════════════════╣\n");
        printf("║ [1] Carro mais próximo                                       ║\n");
        printf("║ [2] Melhor preço                                             ║\n");
        printf("║ [3] Menor distância                                          ║\n");
        printf("║ [0] Sair                                                     ║\n");
        printf("╚══════════════════════════════════════════════════════════════╝\n");
        break;
    default:
        printf("Não exite um menu do tipo que escolheu\n");
    }
}