#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "grafo.h"
#include "hash.h"
#include "dashboard.h"

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
    Lista tabela[TAM];
    inicializarTabela(tabela);

    sessao(tabela);
    return 0;
}
