#ifndef FICHEIROS_H
#define FICHEIROS_H

#include "tipos.h"
#include "hash.h"

/* Utilizadores */
void guardarUsuarios(Lista t[]);
void carregarUsuarios(Lista t[]);

/* Cidades */
void guardarCidades();
void carregarCidades();

/* Rotas */
void guardarRotas();
void carregarRotas();

/* Viagens */
void guardarViagens();
void carregarViagens();

/*Reserva de viagens*/
void guardarReservas();
void carregarReservas();

#endif