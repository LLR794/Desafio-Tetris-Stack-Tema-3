#ifndef PECA_H
#define PECA_H

// Enum para os formatos das peças do Tetris
typedef enum {
    I, O, T, J, L, S, Z
} FormatoPeca;

// Struct que representa uma peça do jogo
typedef struct {
    FormatoPeca formato;
} Peca;

// Protótipos
Peca gerar_peca_aleatoria();
const char* formato_para_string(FormatoPeca formato);

#endif // PECA_H
