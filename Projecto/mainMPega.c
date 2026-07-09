#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "hash.h"
#include "dashboard.h"
#include "ficheiros.h"

int main()
{
    Lista tabela[TAM];
    totalCidades = 0;
    totalRotas = 0;
    inicializarTabela(tabela);

    inicializarGrafo();

    carregarUsuarios(tabela);

    carregarCidades();

    carregarRotas();

    carregarViagens();
    carregarReservas();

    aguardarEnter();
    sessao(tabela);
    return 0;
}
