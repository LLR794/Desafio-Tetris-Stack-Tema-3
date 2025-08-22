#include <stdio.h>
#include "jogo.h"

#define TAMANHO_INICIAL_FILA 5

void inicializar_jogo(Jogo* jogo) {
    inicializar_fila(&jogo->fila_de_pecas);
    inicializar_pilha(&jogo->pilha_de_reserva);
    
    // Preenche a fila com as peças iniciais
    for (int i = 0; i < TAMANHO_INICIAL_FILA; i++) {
        enfileirar(&jogo->fila_de_pecas, gerar_peca_aleatoria());
    }
    
    jogo->tem_peca_atual = 0;
    proxima_peca_do_jogo(jogo); // Pega a primeira peça
}

// Pega a próxima peça da fila e a torna a peça atual
void proxima_peca_do_jogo(Jogo* jogo) {
    if (!fila_vazia(&jogo->fila_de_pecas)) {
        jogo->peca_atual = desenfileirar(&jogo->fila_de_pecas);
        jogo->tem_peca_atual = 1;
        
        // Adiciona uma nova peça ao final da fila para manter o fluxo
        enfileirar(&jogo->fila_de_pecas, gerar_peca_aleatoria());
    } else {
        jogo->tem_peca_atual = 0;
        printf("Fim de jogo! Nao ha mais pecas na fila.\n");
    }
}

// Lógica de reservar a peça atual
void reservar_peca_atual(Jogo* jogo) {
    if (!jogo->tem_peca_atual) {
        printf("Nao ha peca atual para reservar.\n");
        return;
    }

    // Caso 1: Reserva está vazia. Move a peça atual para a reserva.
    if (pilha_vazia(&jogo->pilha_de_reserva)) {
        empilhar(&jogo->pilha_de_reserva, jogo->peca_atual);
        printf("Peca %s movida para a reserva.\n", formato_para_string(jogo->peca_atual.formato));
        proxima_peca_do_jogo(jogo); // Pega a próxima peça da fila
    } 
    // Caso 2: Reserva está cheia. Troca a peça atual com a da reserva.
    else {
        Peca peca_da_reserva = desempilhar(&jogo->pilha_de_reserva);
        Peca peca_para_reserva = jogo->peca_atual;

        empilhar(&jogo->pilha_de_reserva, peca_para_reserva);
        jogo->peca_atual = peca_da_reserva;
        
        printf("Pecas trocadas! Nova peca atual: %s | Nova peca na reserva: %s\n",
            formato_para_string(jogo->peca_atual.formato),
            formato_para_string(peca_para_reserva.formato));
    }
}

void imprimir_estado_jogo(const Jogo* jogo) {
    printf("\n+----------------------------------------+\n");
    if (jogo->tem_peca_atual) {
        printf("| PECA ATUAL: %-25s |\n", formato_para_string(jogo->peca_atual.formato));
    } else {
        printf("| Nenhuma peca em jogo.                  |\n");
    }
    printf("+----------------------------------------+\n");
    
    printf("| ");
    imprimir_pilha(&jogo->pilha_de_reserva);

    printf("| ");
    imprimir_fila(&jogo->fila_de_pecas);
    printf("+----------------------------------------+\n");
}

void encerrar_jogo(Jogo* jogo) {
    liberar_fila(&jogo->fila_de_pecas);
    printf("\nJogo encerrado. Memoria liberada.\n");
}
