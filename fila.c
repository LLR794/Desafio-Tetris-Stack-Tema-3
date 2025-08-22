#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializar_fila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int fila_vazia(const Fila* f) {
    return f->inicio == NULL;
}

void enfileirar(Fila* f, Peca p) {
    NoFila* novo_no = (NoFila*) malloc(sizeof(NoFila));
    if (!novo_no) {
        printf("Erro de alocacao de memoria na fila!\n");
        exit(1);
    }
    novo_no->peca = p;
    novo_no->proximo = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo_no;
    } else {
        f->fim->proximo = novo_no;
    }
    f->fim = novo_no;
}

Peca desenfileirar(Fila* f) {
    if (fila_vazia(f)) {
        printf("Erro: Fila de pecas vazia!\n");
        // Retorna uma peça "padrão" em caso de erro
        return gerar_peca_aleatoria();
    }
    NoFila* no_removido = f->inicio;
    Peca peca_removida = no_removido->peca;
    
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL; // A fila ficou vazia
    }
    
    free(no_removido);
    return peca_removida;
}

void imprimir_fila(const Fila* f) {
    NoFila* atual = f->inicio;
    printf("Proximas Pecas -> [ ");
    while (atual != NULL) {
        printf("%s ", formato_para_string(atual->peca.formato));
        atual = atual->proximo;
    }
    printf("]\n");
}

void liberar_fila(Fila* f) {
    while (!fila_vazia(f)) {
        desenfileirar(f);
    }
}
