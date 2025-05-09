#include <stdio.h>

// ------------------- TORRE (Recursividade) -------------------
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);  // chamada recursiva
}

// ------------------- BISPO (Recursividade + Loops Aninhados) -------------------
void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casasRestantes - 1);  // chamada recursiva
}

void moverBispoComLoopsAninhados(int passosVerticais, int passosHorizontais) {
    printf("\nMovimento do Bispo com loops aninhados:\n");
    for (int i = 0; i < passosVerticais; i++) {
        for (int j = 0; j < passosHorizontais; j++) {
            printf("Cima Direita\n");
        }
    }
}

// ------------------- RAINHA (Recursividade) -------------------
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);  // chamada recursiva
}

// ------------------- CAVALO (Loops aninhados complexos) -------------------
void moverCavalo() {
    printf("\nMovimento do Cavalo:\n");
    
    int movimentos = 1; // número de movimentos em "L"
    
    for (int i = 0; i < movimentos; i++) {
        int passosVerticais = 0;
        
        // Duas casas para cima
        while (passosVerticais < 2) {
            if (passosVerticais == 1) {
                printf("Cima\n");
                passosVerticais++;
                continue; // força a próxima iteração
            }
            printf("Cima\n");
            passosVerticais++;
        }
        
        // Uma casa para a direita com verificação
        for (int j = 0; j < 1; j++) {
            if (j > 0) break; // apenas uma repetição
            printf("Direita\n");
        }
    }
}

// ------------------- MAIN -------------------
int main() {
    // ---------------- TORRE ----------------
    printf("Movimento da Torre:\n");
    moverTorre(5);

    // ---------------- BISPO ----------------
    printf("\nMovimento do Bispo (recursivo):\n");
    moverBispoRecursivo(5);

    moverBispoComLoopsAninhados(2, 1); // 2x movimentos verticais e 1x horizontais por iteração

    // ---------------- RAINHA ----------------
    printf("\nMovimento da Rainha:\n");
    moverRainha(8);

    // ---------------- CAVALO ----------------
    moverCavalo();

    return 0;
}
