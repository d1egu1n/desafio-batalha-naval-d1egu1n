#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// 1. criar habilidades do cone
void criarcone(int cone[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
            
        }
        
    }
    
}

// 2. criar habilidades do cruz
void criarcruz(int cruz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
            
        }
        
    }
    
}

// 3. criar habilidades do octaedo
void criaroctaedo(int octaedo[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedo[i][j] = 1;
            } else {
                octaedo[i][j] = 0;
            }
            
        }
        
    }
    
}

// 4. aplicando as habilidades
void aplicarHabilidade(
    int tabuleiro[10][10],
    int habilidade[][5],
    int linhas, int colunas,
    int origemL, int origemC,
    int centroL, int centroC
) {

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            if (habilidade[i][j] == 1) {

                int linha = origemL + i - centroL;
                int coluna = origemC + j - centroC;

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {

                        tabuleiro[linha][coluna] = 5;
                    
                }
            }
        }
    }
}

int main() {

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
   
    char linha [10]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro [10][10];
    
    int cone[3][5];
    int cruz[5][5];
    int octaedo[5][5];

    criarcone(cone);
    criarcruz(cruz);
    criaroctaedo(octaedo);

    // 5. Inicializar tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            tabuleiro[i][j] = 0;
        }
        
    }

    // 6. vetores do navio
    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};
    int naviodiagonal1[3] = {3, 3, 3};
    int naviodiagonal2[3] = {3, 3, 3};

    // 7. coordenadas do navio
    int linhaH = 2;     int linhaV = 5;     int diagonal1_1 = 0;    int diagonal2_1 = 0;
    int colunaH = 4;    int colunaV = 7;    int diagonal1_2 = 0;    int diagonal2_2 = 9;

    // 8. validar o navio na horizontal
    int podeH = 1;

    if (colunaH + 3 > 10) {
        podeH = 0;
    }

    for (int i = 0; i < 3; i++) {
        
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            podeH = 0;
        }
        
    }
    
    // 9. inserir navio horizontal
      
    if (podeH) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    } else {
        printf("Navio horizontal fora do limite!\n");
    }
     
    // 10. validar navio na vertical
    int podeV = 1;

    if (linhaV + 3 > 10) {
        podeV = 0;
    }

    for (int i = 0; i < 3; i++) {
        
        if (tabuleiro[linhaV + i][colunaV] != 0){
            podeV = 0;
        }
        
    }
      
    // 11. inserir navio vertical

    if (podeV) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioV[i];
        }
    } else {
        printf("Navio vertical fora do limite!\n");
    }

    // 12. valida o navio na diagonal
    int podeG1 = 1;

    // 13. validar limete
    if (diagonal1_1 + 3 > 10 || diagonal1_2 + 3 > 10) {
        podeG1 = 0;
    }

    // 14. validar sobreposição
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[diagonal1_1 + i][diagonal1_2 + i] != 0) {
            podeG1 = 0;
        }
        
    }

    // 15. inserir navio na diagonal
    if (podeG1) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[diagonal1_1 + i][diagonal1_2 + i] = 3;
        }
    } else {
        printf("Navio diagonal fora do limite!\n");
    }

    // 16. valida o navio na diagonal secundario
    int podeG2 = 1;

    if (diagonal2_1 + 3 > 10 || diagonal2_2 - 2 < 0) {
        podeG2 = 0;
    }
    
    // 17. validar sobreposição
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[diagonal2_1 + i][diagonal2_2 - i] != 0){
            podeG2 = 0;
        }
    }

    // 18. inserir navio diagonal secundario
    if (podeG2) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[diagonal2_1 + i][diagonal2_2 - i] = 3;
        }
    } else {
        printf("Navio diagonal secundario fora do limite!\n");
    }
    
    
    // 19. aplicando habilidade no tabuleiro

    aplicarHabilidade(tabuleiro, cone, 3, 5, 6, 2, 1, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5, 5, 5, 2, 2);
    aplicarHabilidade(tabuleiro, octaedo, 5, 5, 8, 8, 2, 2);

    // 20. Imprimir topo (colunas)
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("%c  ", linha[i]);
    }
    printf("\n");

    // 21. Imprimir tabuleiro com numeração à esquerda
    for (int i = 0; i < 10; i++) {

    printf("%2d ", i + 1); // lado esquerdo

    for (int j = 0; j < 10; j++) {
        printf("%2d ", tabuleiro[i][j]);
    }

    printf("\n");
    }

    // 22. mostra o tabuleiro das habilidades
    // Nota: utilizei o valor 5 para representar habilidades no tabuleiro principal,
    // e faço a conversão para 1 na exibição separada, conforme solicitado no enunciado.
    
    printf("\nTabuleiro de Habilidades:\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            if (tabuleiro[i][j] == 5)
                printf(" 1 ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }    

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
