#ifndef ficheiros_h
#define ficheiros_h

#include "tipos.h"
void menuGrafos();

/* MOTORISTAS */
int guardarMotorista(Motorista motorista);
int existeMotorista(int idMotorista);

/* VEICULOS */
int guardarVeiculo(Veiculo veiculo);
int existeMatricula(char matricula[]);
void atualizarEstadoVeiculo(Veiculo *veiculo);

/* CIDADES */
int guardarCidade(Cidade cidade);
int existeCidadeFicheiro(int idCidade);

/* ROTAS */
int guardarRota(Rota rota);
int existeRotaFicheiro(int idRota);

/* VIAGENS */
int guardarViagem(Viagem viagem);

#endif