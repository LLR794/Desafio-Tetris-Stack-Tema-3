#ifndef FILA_H
#define FILA_H

#include "peca.h"

// Nó da lista encadeada que compõe a fila
typedef struct NoFila {
    Peca peca;
    struct NoFila* proximo;
} NoFila;

// Estrutura da Fila
typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

// Protótipos das operações da Fila
void inicializar_fila(Fila* f);
int fila_vazia(const Fila* f);
void enfileirar(Fila* f, Peca p);
Peca desenfileirar(Fila* f);
void imprimir_fila(const Fila* f);
void liberar_fila(Fila* f);

#endif // FILA_H
