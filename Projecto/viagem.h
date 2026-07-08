#ifndef VIAGEM_H
#define VIAGEM_H

#include "tipos.h"
#include "hash.h"

#define MAX_VIAGENS 100

/*==============================
        VARIÁVEIS GLOBAIS
==============================*/

extern Viagem viagens[MAX_VIAGENS];
extern int totalViagens;

/*==============================
      GESTÃO DE VIAGENS
==============================*/

int publicarViagem(Viagem viagem);

void listarViagens();

void procurarViagem();

Viagem *buscarViagem(int idViagem);

int removerViagem(int idViagem);

void listarMinhasViagens(int idMotorista);

/*==============================
      PASSAGEIROS
==============================*/

int reservarLugar(int idViagem, int idPassageiro);

int cancelarReserva(int idViagem, int idPassageiro);

void listarPassageiros(Lista t[], int idViagem);

/*==============================
      ESTADO DA VIAGEM
==============================*/

int iniciarViagem(int idViagem);

int terminarViagem(int idViagem);

/*==============================
      FICHEIROS
==============================*/

void guardarViagens();

void carregarViagens();

#endif
