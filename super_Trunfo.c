#include <stdio.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[50];
    char codigo[50];
    char data[50];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional, PIB per capita e Super Poder
void calcular_atributos(Carta *c){
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
    c->super_poder = c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita + (1.0 / c->densidade_populacional);
}

// Função para comparar dois atributos e imprimir o resultado
void comparar_e_imprimir(const char *atributo, float valor1, float valor2, int invertido){
    if (invertido) {
        printf("%s: %.2f vs %.2f -> %s\n", atributo, valor1, valor2, (valor1 < valor2) ? "Carta 1 vence" : "Carta 2 vence");
    } else {
        printf("%s: %.2f vs %.2f -> %s\n", atributo, valor1, valor2, (valor1 > valor2) ? "Carta 1 vence" : "Carta 2 vence");
    }
}

int main() {
    Carta carta1, carta2;
    
    // Entrada dos dados para a primeira carta
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: "); scanf("%49s", carta1.estado);
    printf("Código: "); scanf("%49s", carta1.codigo);
    printf("Nome: "); scanf("%49s", carta1.nome);
    printf("População: "); scanf("%lu", &carta1.populacao);
    printf("Área: "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &carta1.pontos_turisticos);
    
    calcular_atributos(&carta1);
    
    // Entrada dos dados para a segunda carta
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); scanf("%49s", carta2.estado);
    printf("Código: "); scanf("%49s", carta2.codigo);
    printf("Nome: "); scanf("%49s", carta2.nome);
    printf("População: "); scanf("%lu", &carta2.populacao);
    printf("Área: "); scanf("%f", &carta2.area);
    printf("PIB: "); scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &carta2.pontos_turisticos);
    
    calcular_atributos(&carta2);
    
    // Comparação dos atributos
    printf("\nComparação de Cartas:\n");
    comparar_e_imprimir("População", carta1.populacao, carta2.populacao, 0);
    comparar_e_imprimir("Área", carta1.area, carta2.area, 0);
    comparar_e_imprimir("PIB", carta1.pib, carta2.pib, 0);
    comparar_e_imprimir("Pontos Turísticos", carta1.pontos_turisticos, carta2.pontos_turisticos, 0);
    comparar_e_imprimir("Densidade Populacional", carta1.densidade_populacional, carta2.densidade_populacional, 1);
    comparar_e_imprimir("PIB per Capita", carta1.pib_per_capita, carta2.pib_per_capita, 0);
    comparar_e_imprimir("Super Poder", carta1.super_poder, carta2.super_poder, 0);

    return 0;
}
