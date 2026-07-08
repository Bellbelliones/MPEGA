#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "hash.h"
#include "dashboard.h"
#include "ficheiros.h"

int main()
{
    Lista tabela[TAM];

    inicializarTabela(tabela);

    inicializarGrafo();

    carregarUsuarios(tabela);

    carregarCidades();

    carregarRotas();

    carregarViagens();
    carregarReservas();

    sessao(tabela);
    return 0;
}
