#include <stdio.h>
#include <string.h>

#define POPULACAO 1
#define AREA 2
#define PIB 3
#define DENSIDADE 4
#define PIB_PER_CAPITA 5

#define ATRIBUTO_COMPARACAO POPULACAO

typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

int main() {
    Carta carta1 = {
        "SP", "SP01", "Sao Paulo", 
        12300000, 1521.11, 1000000.0, 100
    };
    
    Carta carta2 = {
        "RJ", "RJ01", "Rio de Janeiro", 
        6748000, 1200.27, 750000.0, 80
    };

    // Cálculo dos campos derivados
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Determinação do vencedor
    int vencedor = 0;
    const char* atributo_nome = "";
    float valor1 = 0, valor2 = 0;

    switch(ATRIBUTO_COMPARACAO) {
        case POPULACAO:
            atributo_nome = "Populacao";
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            vencedor = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            break;
            
        case AREA:
            atributo_nome = "Area";
            valor1 = carta1.area;
            valor2 = carta2.area;
            vencedor = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            break;
            
        case PIB:
            atributo_nome = "PIB";
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            vencedor = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            break;
            
        case DENSIDADE:
            atributo_nome = "Densidade Populacional";
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            // Regra especial: menor valor vence
            vencedor = (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
            break;
            
        case PIB_PER_CAPITA:
            atributo_nome = "PIB per capita";
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            vencedor = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            break;
    }

    // Exibição dos resultados
    printf("\nDados das Cartas:\n");
    printf("----------------------------------------\n");
    printf("Carta 1 - %s (%s):\n", carta1.cidade, carta1.estado);
    printf("  Populacao: %d\n", carta1.populacao);
    printf("  Area: %.2f km²\n", carta1.area);
    printf("  PIB: R$ %.2f\n", carta1.pib);
    printf("  Pontos Turisticos: %d\n", carta1.pontos_turisticos);
    printf("  Densidade: %.2f hab/km²\n", carta1.densidade);
    printf("  PIB per capita: R$ %.6f\n", carta1.pib_per_capita);
    
    printf("\nCarta 2 - %s (%s):\n", carta2.cidade, carta2.estado);
    printf("  Populacao: %d\n", carta2.populacao);
    printf("  Area: %.2f km²\n", carta2.area);
    printf("  PIB: R$ %.2f\n", carta2.pib);
    printf("  Pontos Turisticos: %d\n", carta2.pontos_turisticos);
    printf("  Densidade: %.2f hab/km²\n", carta2.densidade);
    printf("  PIB per capita: R$ %.6f\n", carta2.pib_per_capita);
    
    printf("\nComparacao de cartas (Atributo: %s):\n", atributo_nome);
    printf("----------------------------------------\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor2);
    
    if (vencedor == 1) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (vencedor == 2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}