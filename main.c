#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

int main() {
    srand(time(NULL));
    Jogo meu_jogo;
    int opcao;

    inicializar_jogo(&meu_jogo);

    do {
        imprimir_estado_jogo(&meu_jogo);
        printf("\nEscolha sua jogada:\n");
        printf("1. Jogar Peca Atual (pega a proxima da fila)\n");
        printf("2. Reservar / Trocar Peca Atual\n");
        printf("0. Sair do Jogo\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nVoce jogou a peca %s.\n", formato_para_string(meu_jogo.peca_atual.formato));
                proxima_peca_do_jogo(&meu_jogo);
                break;
            case 2:
                reservar_peca_atual(&meu_jogo);
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0 && meu_jogo.tem_peca_atual);

    encerrar_jogo(&meu_jogo);

    return 0;
}
