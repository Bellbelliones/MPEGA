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
    default:
        printf("Não exite um menu do tipo que escolheu\n");
    }
}