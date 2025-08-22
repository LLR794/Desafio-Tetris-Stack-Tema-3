#include <stdlib.h>
#include "peca.h"

// Gera uma peça com um formato aleatório
Peca gerar_peca_aleatoria() {
    Peca p;
    p.formato = (FormatoPeca)(rand() % 7); // Sorteia um formato entre os 7 possíveis
    return p;
}

// Converte o enum do formato para uma string para exibição
const char* formato_para_string(FormatoPeca formato) {
    switch (formato) {
        case I: return "I (____)";
        case O: return "O (##)";
        case T: return "T (-'-)";
        case J: return "J (__')";
        case L: return "L ('__)";
        case S: return "S (_'')";
        case Z: return "Z (''-)";
        default: return "?";
    }
}
