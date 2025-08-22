#include <stdio.h>
#include "pilha.h"

void inicializar_pilha(PilhaReserva* p) {
    p->ocupado = 0;
}

int pilha_cheia(const PilhaReserva* p) {
    return p->ocupado;
}

int pilha_vazia(const PilhaReserva* p) {
    return !p->ocupado;
}

int empilhar(PilhaReserva* p, Peca peca) {
    if (pilha_cheia(p)) {
        return 0; // Falha, pilha cheia
    }
    p->peca = peca;
    p->ocupado = 1;
    return 1; // Sucesso
}

Peca desempilhar(PilhaReserva* p) {
    if (pilha_vazia(p)) {
        printf("Erro: Pilha de reserva vazia!\n");
        return gerar_peca_aleatoria(); // Retorna peça padrão em caso de erro
    }
    p->ocupado = 0;
    return p->peca;
}

void imprimir_pilha(const PilhaReserva* p) {
    printf("Peca Reservada -> [ ");
    if (pilha_vazia(p)) {
        printf("Vazio");
    } else {
        printf("%s", formato_para_string(p->peca.formato));
    }
    printf(" ]\n");
}
