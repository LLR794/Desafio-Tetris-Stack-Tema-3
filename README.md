# Desafio Tetris Stack – Tema 3

## Sobre o Desafio

`Tetris Stack` é um projeto em linguagem C desenvolvido para a ByteBros, uma empresa focada em jogos que ensinam lógica de programação. O objetivo deste desafio foi implementar o sistema central de gerenciamento de peças do jogo, utilizando as estruturas de dados **Fila (Queue)** e **Pilha (Stack)** como mecânicas de gameplay.

O jogador interage com um fluxo de peças de Tetris, podendo jogá-las, reservá-las para uso posterior ou trocá-las, aplicando diretamente os conceitos de FIFO (First-In, First-Out) e LIFO (Last-In, First-Out).

## Estrutura do Projeto

O código-fonte foi modularizado para garantir a separação de responsabilidades e a clareza, seguindo boas práticas de engenharia de software.

-   `main.c`: O ponto de entrada da aplicação. Contém o loop principal do jogo e a interface de texto para interação com o jogador.
-   `peca.h` / `.c`: Define a `struct Peca` e funções auxiliares para gerar e representar as diferentes peças do Tetris (I, O, T, J, L, S, Z).
-   `fila.h` / `.c`: Implementa a estrutura de dados **Fila** usando uma lista encadeada. É responsável por gerenciar a sequência de peças futuras que entrarão no jogo.
-   `pilha.h` / `.c`: Implementa a estrutura de dados **Pilha**. Para simular a mecânica de "hold" do Tetris, a pilha foi projetada para armazenar apenas um item, funcionando como um slot de reserva.
-   `jogo.h` / `.c`: O módulo central que integra a Fila e a Pilha. Ele gerencia o estado completo do jogo, incluindo a peça atual, a fila de próximas peças e a peça na reserva.

## Estruturas de Dados e Mecânicas Implementadas

### Fila (Queue) - Próximas Peças

-   **Conceito:** A fila segue a lógica **FIFO (First-In, First-Out)**. A primeira peça que entra na fila é a primeira a sair.
-   **Aplicação no Jogo:** Simula a esteira de "próximas peças". Quando o jogador usa a peça atual, a próxima a entrar em jogo é a que está no início da fila. Novas peças geradas aleatoriamente são adicionadas ao final da fila.
-   **Implementação:** Foi utilizada uma lista encadeada para permitir um tamanho dinâmico e eficiente para a fila de peças.

### Pilha (Stack) - Peça Reservada

-   **Conceito:** A pilha segue a lógica **LIFO (Last-In, First-Out)**. O último elemento a ser inserido é o primeiro a ser removido.
-   **Aplicação no Jogo:** Funciona como o sistema de "reserva" ou "hold". O jogador pode mover a peça atual para a reserva para usá-la em um momento mais estratégico.
-   **Implementação:** Foi modelada como uma estrutura simples com capacidade para um único item, refletindo fielmente a mecânica encontrada nos jogos de Tetris.

### Sistema Integrado

A principal funcionalidade do projeto é a **comunicação entre a Fila e a Pilha**:

1.  **Jogar Peça:** A peça atual é "usada", e a próxima peça é retirada do **início da Fila**.
2.  **Reservar Peça (Reserva Vazia):** A peça atual é enviada para a **Pilha**, e a próxima peça é retirada do **início da Fila**.
3.  **Trocar Peça (Reserva Ocupada):** A peça atual e a peça na **Pilha** trocam de lugar. A peça que estava na reserva se torna a peça atual, e a que estava em jogo vai para a reserva.

## Como Compilar e Executar

Para compilar o projeto, utilize um compilador C como o GCC. Abra um terminal na pasta onde os arquivos foram salvos e execute o comando:

```bash
gcc main.c peca.c fila.c pilha.c jogo.c -o tetris_stack
