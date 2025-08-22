#ifndef PILHA_H
#define PILHA_H

#include "peca.h"

// Estrutura da Pilha de Reserva (capacidade de 1 item)
typedef struct {
    Peca peca;
    int ocupado; // Flag para indicar se a reserva tem uma peça
} PilhaReserva;

// Protótipos das operações da Pilha
void inicializar_pilha(PilhaReserva* p);
int pilha_cheia(const PilhaReserva* p);
int pilha_vazia(const PilhaReserva* p);
int empilhar(PilhaReserva* p, Peca peca); // Push
Peca desempilhar(PilhaReserva* p);      // Pop
void imprimir_pilha(const PilhaReserva* p);

#endif // PILHA_H
