#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constantes para os atributos de comparação
#define POPULACAO 1
#define AREA 2
#define PIB 3
#define PONTOS_TURISTICOS 4
#define DENSIDADE 5

// Estrutura da carta
typedef struct {
    char pais[50];
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu de opções
int exibir_menu() {
    int opcao;
    
    printf("\n\n===== SUPER TRUNFO - COMPARAR CARTAS =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("----------------------------------------\n");
    printf("Digite sua escolha (1-5): ");
    
    while(scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 5) {
        limpar_buffer();
        printf("Opcao invalida! Digite um numero entre 1 e 5: ");
    }
    
    return opcao;
}

int main() {
    // Cadastro das duas cartas (dados de países)
    Carta carta1 = {"Brasil", "BRA", 213000000, 8515767.0, 1840.0, 50, 0};
    Carta carta2 = {"Argentina", "ARG", 45100000, 2780400.0, 445.0, 40, 0};

    // Calcular densidade demográfica
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    // Exibir informações das cartas
    printf("===== CARTAS DO JOGO =====\n");
    printf("Carta 1: %s (%s)\n", carta1.pais, carta1.codigo);
    printf("  Populacao: %d habitantes\n", carta1.populacao);
    printf("  Area: %.2f km²\n", carta1.area);
    printf("  PIB: US$ %.2f bilhoes\n", carta1.pib);
    printf("  Pontos Turisticos: %d\n", carta1.pontos_turisticos);
    printf("  Densidade: %.2f hab/km²\n", carta1.densidade);
    
    printf("\nCarta 2: %s (%s)\n", carta2.pais, carta2.codigo);
    printf("  Populacao: %d habitantes\n", carta2.populacao);
    printf("  Area: %.2f km²\n", carta2.area);
    printf("  PIB: US$ %.2f bilhoes\n", carta2.pib);
    printf("  Pontos Turisticos: %d\n", carta2.pontos_turisticos);
    printf("  Densidade: %.2f hab/km²\n", carta2.densidade);

    // Menu interativo
    int atributo = exibir_menu();
    const char* atributo_nome = "";
    float valor1 = 0, valor2 = 0;
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2

    // Determinar qual atributo será comparado
    switch(atributo) {
        case POPULACAO:
            atributo_nome = "Populacao";
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            if (valor1 > valor2) vencedor = 1;
            else if (valor2 > valor1) vencedor = 2;
            break;
            
        case AREA:
            atributo_nome = "Area";
            valor1 = carta1.area;
            valor2 = carta2.area;
            if (valor1 > valor2) vencedor = 1;
            else if (valor2 > valor1) vencedor = 2;
            break;
            
        case PIB:
            atributo_nome = "PIB";
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            if (valor1 > valor2) vencedor = 1;
            else if (valor2 > valor1) vencedor = 2;
            break;
            
        case PONTOS_TURISTICOS:
            atributo_nome = "Pontos Turisticos";
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            if (valor1 > valor2) vencedor = 1;
            else if (valor2 > valor1) vencedor = 2;
            break;
            
        case DENSIDADE:
            atributo_nome = "Densidade Demografica";
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            // Regra especial: menor valor vence
            if (valor1 < valor2) vencedor = 1;
            else if (valor2 < valor1) vencedor = 2;
            break;
    }

    // Exibir resultado da comparação
    printf("\n\n===== RESULTADO DA COMPARACAO =====\n");
    printf("Atributo: %s\n", atributo_nome);
    printf("----------------------------------------\n");
    printf("%s: ", carta1.pais);
    
    // Formatação especial para diferentes tipos de dados
    if (atributo == POPULACAO) 
        printf("%d habitantes\n", (int)valor1);
    else if (atributo == PONTOS_TURISTICOS)
        printf("%d pontos\n", (int)valor1);
    else if (atributo == AREA)
        printf("%.2f km²\n", valor1);
    else if (atributo == PIB)
        printf("US$ %.2f bilhões\n", valor1);
    else
        printf("%.2f hab/km²\n", valor1);
        
    printf("%s: ", carta2.pais);
    if (atributo == POPULACAO) 
        printf("%d habitantes\n", (int)valor2);
    else if (atributo == PONTOS_TURISTICOS)
        printf("%d pontos\n", (int)valor2);
    else if (atributo == AREA)
        printf("%.2f km²\n", valor2);
    else if (atributo == PIB)
        printf("US$ %.2f bilhões\n", valor2);
    else
        printf("%.2f hab/km²\n", valor2);
    
    printf("----------------------------------------\n");
    
    if (vencedor == 1) {
        printf("Vencedor: %s!\n", carta1.pais);
    } else if (vencedor == 2) {
        printf("Vencedor: %s!\n", carta2.pais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}