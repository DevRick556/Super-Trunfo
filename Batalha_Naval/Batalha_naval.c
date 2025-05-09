#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se uma posição está dentro do tabuleiro
int dentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB;
}

// Coloca um navio com validação simples
void posicionarNavio(int tabuleiro[TAM_TAB][TAM_TAB], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < 3; i++) {
        int l = linha, c = coluna;
        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == 2) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            l += i;
        } else {
            c += i;
        }
        if (dentroDosLimites(l, c) && tabuleiro[l][c] == AGUA) {
            tabuleiro[l][c] = NAVIO;
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("\nTABULEIRO:\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Cria área de cone (5x5), apontando para baixo
void criarCone(int area[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= j - 2 && i + j >= 2 && i <= 2) {
                area[i][j] = 1;
            } else if (i == 3 && (j == 1 || j == 2 || j == 3)) {
                area[i][j] = 1;
            } else if (i == 4 && j == 2) {
                area[i][j] = 1;
            } else {
                area[i][j] = 0;
            }
        }
    }
}

// Cria área de cruz (5x5)
void criarCruz(int area[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == 2 || j == 2) {
                area[i][j] = 1;
            } else {
                area[i][j] = 0;
            }
        }
    }
}

// Cria área de octaedro (losango 5x5)
void criarOctaedro(int area[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                area[i][j] = 1;
            } else {
                area[i][j] = 0;
            }
        }
    }
}

// Aplica a área de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int area[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int l = origem_linha - TAM_HAB / 2 + i;
            int c = origem_coluna - TAM_HAB / 2 + j;
            if (dentroDosLimites(l, c) && area[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                tabuleiro[l][c] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    inicializarTabuleiro(tabuleiro);

    // Posiciona dois navios diagonais (diagonal = 1 ou 2)
    posicionarNavio(tabuleiro, 0, 0, 0, 1);  // Diagonal principal
    posicionarNavio(tabuleiro, 0, 9, 0, 2);  // Diagonal secundária

    // Posiciona dois navios horizontais ou verticais (direcao = 0 vertical, 1 horizontal)
    posicionarNavio(tabuleiro, 5, 0, 1, 0);  // Horizontal
    posicionarNavio(tabuleiro, 2, 5, 0, 0);  // Vertical

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades em pontos fixos do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
