#ifndef JOGO_H
#define JOGO_H

#include "fila.h"
#include "pilha.h"

// Estrutura aninhada para gerenciar o estado do jogo
typedef struct {
    Fila fila_de_pecas;
    PilhaReserva pilha_de_reserva;
    Peca peca_atual;
    int tem_peca_atual;
} Jogo;

void inicializar_jogo(Jogo* jogo);
void proxima_peca_do_jogo(Jogo* jogo);
void reservar_peca_atual(Jogo* jogo);
void imprimir_estado_jogo(const Jogo* jogo);
void encerrar_jogo(Jogo* jogo);

#endif // JOGO_H
