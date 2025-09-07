#include <stdio.h>
#include <locale.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Novato - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
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

// Tamanho do Tabuleiro
#define TAMANHO 10

//Tamanho da Área afetada pela Bomba
#define TAMANHO_HABILIDADE_BOMBA 5

// Navio Horizontal (linha fixa, colunas variam)
#define NAVIO_H_COL_INICIAL 2
#define NAVIO_H_COL_FINAL 4
#define NAVIO_H_LINHA 8

// Navio Vertical (linhas variam, coluna fixa)
#define NAVIO_V_LINHA_INICIAL 4
#define NAVIO_V_LINHA_FINAL 6
#define NAVIO_V_COLUNA 6

// Navio Diagonal Principal (↘)
#define NAVIO_DP_LINHA_INICIAL 0
#define NAVIO_DP_COL_INICIAL 0
#define NAVIO_DP_TAMANHO 3

// Navio Diagonal Secundária (↙)
#define NAVIO_DS_LINHA_INICIAL 0
#define NAVIO_DS_COL_INICIAL 9
#define NAVIO_DS_TAMANHO 3



void DEFINIR_TAMANHO_TABULEIRO(int array [TAMANHO][TAMANHO]) {

    for (int index_linha = 0; index_linha < TAMANHO; index_linha++) {

        for (int index_coluna = 0; index_coluna < TAMANHO; index_coluna++) {
            
            array[index_linha][index_coluna] = 0;

        }
        
    }

}

void DEFINIR_LOCAL_NAVIO(int array [TAMANHO][TAMANHO]) {

    // Navio na Horizontal
    for (int j = NAVIO_H_COL_INICIAL; j <= NAVIO_H_COL_FINAL; j++) {
        array[NAVIO_H_LINHA][j] = 3;
    }

    // Navio na Vertical
    for (int i = NAVIO_V_LINHA_INICIAL; i <= NAVIO_V_LINHA_FINAL; i++) {
        array[i][NAVIO_V_COLUNA] = 3;
    }

    // Navio na Diagonal Principal
    for (int k = 0; k < NAVIO_DP_TAMANHO; k++) {
        array[NAVIO_DP_LINHA_INICIAL + k][NAVIO_DP_COL_INICIAL + k] = 3;
    }

    // Navio na Diagonal Secundária
    for (int k = 0; k < NAVIO_DS_TAMANHO; k++) {
        array[NAVIO_DS_LINHA_INICIAL + k][NAVIO_DS_COL_INICIAL - k] = 3;
    }

}

void EXIBIR_TABULEIRO(int array [TAMANHO][TAMANHO]){

    printf(">---> === TABULEIRO BATALHA NAVAL === <---<\n");

    printf("\n");

    printf("   | A B C D E F G H I J\n");
    printf("---+---------------------\n");

    for (int i = 0; i < TAMANHO; i++) {

        printf("%2d | ", i + 1);
        
        for (int j = 0; j < TAMANHO; j++) {

            if (j <= 8)
            {
                printf("%d ", array[i][j]);
            } else if(j >= 9)
            {
                printf("%d", array[i][j]);
            }
            
            
        }

        printf("\n");
        
    }

    printf("\n");

    printf("--------------------------------------\n");

}

void BOMBA_CONE(int hab[3][TAMANHO_HABILIDADE_BOMBA]) {

    for (int i = 0; i < TAMANHO_HABILIDADE_BOMBA; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE_BOMBA; j++) {
            hab[i][j] = 0;
        }
    }

    int centro = 2; // coluna central
    for (int i = 0; i < 3; i++) { // altura do cone = 3 linhas
        for (int j = centro - i; j <= centro + i; j++) {
            hab[i][j] = 1;
        }
    }

}

void BOMBA_CRUZ(int hab[3][TAMANHO_HABILIDADE_BOMBA]) {

    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < TAMANHO_HABILIDADE_BOMBA; j++) {
        
            hab[i][j] = (i == 1 || j == 2) ? 1 : 0;
            
        }
        
    }

}

void BOMBA_OCTAEDRO(int hab[][TAMANHO_HABILIDADE_BOMBA], int linhas, int colunas) {

    int centroLinha = linhas / 2;   // Linha central
    int centroColuna = colunas / 2; // Coluna central

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            // Condições para formar o octaedro
            if ((i == centroLinha - 1 && j == centroColuna) ||         // topo
                (i == centroLinha && (j >= centroColuna - 1 && j <= centroColuna + 1)) || // meio
                (i == centroLinha + 1 && j == centroColuna)) {        // base
                hab[i][j] = 1;
            } else {
                hab[i][j] = 0;
            }

        }
    }

}

void APLICAR_HABILIDADE(int tab[TAMANHO][TAMANHO], int hab[TAMANHO_HABILIDADE_BOMBA][TAMANHO_HABILIDADE_BOMBA], int origemLinha, int origemColuna) {

    int offset = 2; // Centralizar

    for (int i = 0; i < TAMANHO_HABILIDADE_BOMBA; i++) {
        
        for (int j = 0; j < TAMANHO_HABILIDADE_BOMBA; j++) {
        
            if (hab[i][j] == 1) {
                int linha = origemLinha + (i - offset);
                int coluna = origemColuna + (j - offset);

                if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
            
                    if (tab[linha][coluna] == 0) {
                        tab[linha][coluna] = 1;
                    } else if (tab[linha][coluna] == 3) {
                        tab[linha][coluna] = 5;
                    }
                    
                }  

            }
            
        }
        
    }

}

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");

    int tabuleiro [TAMANHO][TAMANHO];

    int cone[TAMANHO_HABILIDADE_BOMBA][TAMANHO_HABILIDADE_BOMBA],
        cruz[TAMANHO_HABILIDADE_BOMBA][TAMANHO_HABILIDADE_BOMBA],
        octaedro[TAMANHO_HABILIDADE_BOMBA][TAMANHO_HABILIDADE_BOMBA];
    
    DEFINIR_TAMANHO_TABULEIRO(tabuleiro); // Colocar o vator 0 para cada posição da matriz.
    DEFINIR_LOCAL_NAVIO(tabuleiro); // Colocar cada navio no tabuleiro.
    
    BOMBA_CONE(cone);
    BOMBA_CRUZ(cruz);
    BOMBA_OCTAEDRO(octaedro, TAMANHO_HABILIDADE_BOMBA, TAMANHO_HABILIDADE_BOMBA);

    // Aplicar Bombas em Diferentes Pontos
    APLICAR_HABILIDADE(tabuleiro, cone, 2, 2);
    APLICAR_HABILIDADE(tabuleiro, cruz, 5, 5);
    APLICAR_HABILIDADE(tabuleiro, octaedro, 7, 7);

    EXIBIR_TABULEIRO(tabuleiro); // Exibir o tabuleiro após a definição de cada local do tabuleiro.

    printf("\n");
    printf("0 - Água.\n");
    printf("3 - Navio.\n");
    printf("1 - Bomba na Água.\n");
    printf("5 - Navio atingido pela Bomba.\n");

    return 0;

}

/*

RESULTADO:

>---> === TABULEIRO BATALHA NAVAL === <---<

   | A B C D E F G H I J
---+---------------------
 1 | 3 0 1 0 0 0 0 0 0 3
 2 | 0 5 1 1 0 0 0 0 3 0
 3 | 1 1 5 1 1 0 0 3 0 0
 4 | 0 0 0 0 0 1 0 0 0 0
 5 | 0 0 0 1 1 1 5 1 0 0
 6 | 0 0 0 0 0 1 3 0 0 0
 7 | 0 0 0 0 0 0 3 1 0 0
 8 | 0 0 0 0 0 0 1 1 1 0
 9 | 0 0 3 3 3 0 0 1 0 0
10 | 0 0 0 0 0 0 0 0 0 0

--------------------------------------

0 - Água.
3 - Navio.
1 - Bomba na Água.
5 - Navio atingido pela Bomba.

*/
