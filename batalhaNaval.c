#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    char linha [10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro [10][10];
    
    // 1. Inicializar tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            tabuleiro[i][j] = 0;
        }
        
    }

    // 2. vetores do navio
    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};

    // 3. coordenadas do navio
    int linhaH = 2;     int linhaV = 5;
    int colunaH = 4;    int colunaV = 7;

    // 4. validar o navio na horizontal
    int podeH = 1;

    if (colunaH + 3 > 10) {
        podeH = 0;
    }

    for (int i = 0; i < 3; i++) {
        
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            podeH = 0;
        }
        
    }
    
    // 5. inserir navio horizontal
      
    if (podeH) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    } else {
        printf("Navio horizontal fora do limite!\n");
    }
     
    // 6. validar navio na vertical
    int podeV = 1;

    if (linhaV + 3 > 10) {
        podeV = 0;
    }

    for (int i = 0; i < 3; i++) {
        
        if (tabuleiro[linhaV + i][colunaV] != 0){
            podeV = 0;
        }
        
    }
      
    // 7. inserir navio vertical

    if (podeV) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioV[i];
        }
    } else {
        printf("Navio vertical fora do limite!\n");
    }

    // 8. Imprimir topo (colunas)
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("%c  ", linha[i]);
    }
    printf("\n");

    // 9. Imprimir tabuleiro com numeração à esquerda
    for (int i = 0; i < 10; i++) {

    printf("%2d ", i + 1); // lado esquerdo

    for (int j = 0; j < 10; j++) {
        printf("%2d ", tabuleiro[i][j]);
    }

    printf("\n");
    }

    

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
