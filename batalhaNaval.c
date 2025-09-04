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

void DEFINIR_TAMANHO_TABULEIRO(int array [10][10]) {

    for (int index_linha = 0; index_linha < 10; index_linha++) {

        for (int index_coluna = 0; index_coluna < 10; index_coluna++) {
            
            array[index_linha][index_coluna] = 0;

        }
        
    }

}

void DEFINIR_LOCAL_NAVIO(int array [10][10]) {

    for (int j = 3; j <= 5; j++) {
        array[2][j] = 3;
    }

    for (int i = 5; i <= 7; i++) {
        array[i][7] = 3;
    }
}

void EXIBIR_TABULEIRO(int array [10][10]){

    printf(">---> === TABULEIRO BATALHA NAVAL === <---<\n");

    printf("\n");

    printf("   | A B C D E F G H I J\n");
    printf("---+---------------------\n");

    for (int i = 0; i < 10; i++) {

        printf("%2d | ", i + 1);
        
        for (int j = 0; j < 10; j++) {

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

int main() {
    
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int tabuleiro [10][10];

    DEFINIR_TAMANHO_TABULEIRO(tabuleiro);
    DEFINIR_LOCAL_NAVIO(tabuleiro);
    EXIBIR_TABULEIRO(tabuleiro);

    return 0;
}
