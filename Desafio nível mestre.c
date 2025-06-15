#include <stdio.h>

// Definição dos atributos
#define POPULACAO 0
#define AREA 1
#define PIB 2
#define PONTOS 3
#define DENSIDADE 4

// Estrutura da carta
typedef struct {
    char nome[20];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
} Carta;

int main() {
    // Cartas pré-cadastradas
    Carta brasil = {"Brasil", 213000000, 8515767.0, 1840.0, 50};
    Carta argentina = {"Argentina", 45100000, 2780400.0, 445.0, 40};
    
    // Cálculo da densidade
    brasil.densidade = brasil.populacao / brasil.area;
    argentina.densidade = argentina.populacao / argentina.area;

    // Nomes dos atributos
    char* atributos[] = {"Populacao", "Area", "PIB", "Pontos Turisticos", "Densidade"};
    
    // Variáveis para armazenar escolhas
    int attr1, attr2;
    
    // Menu de seleção
    printf("SUPER TRUNFO - NIVEL MESTRE\n\n");
    printf("Escolha dois atributos diferentes:\n");
    for(int i = 0; i < 5; i++)
        printf("%d. %s\n", i+1, atributos[i]);
    
    // Primeira escolha
    printf("\nPrimeiro atributo (1-5): ");
    scanf("%d", &attr1);
    attr1--; // Ajusta para índice 0-4
    
    // Segunda escolha
    printf("Segundo atributo (1-5, diferente de %d): ", attr1+1);
    scanf("%d", &attr2);
    attr2--; // Ajusta para índice 0-4
    
    // Obtém valores
    float brasil_val1 = 0, argentina_val1 = 0;
    float brasil_val2 = 0, argentina_val2 = 0;
    
    switch(attr1) {
        case POPULACAO: 
            brasil_val1 = brasil.populacao;
            argentina_val1 = argentina.populacao;
            break;
        case AREA: 
            brasil_val1 = brasil.area;
            argentina_val1 = argentina.area;
            break;
        case PIB: 
            brasil_val1 = brasil.pib;
            argentina_val1 = argentina.pib;
            break;
        case PONTOS: 
            brasil_val1 = brasil.pontos;
            argentina_val1 = argentina.pontos;
            break;
        case DENSIDADE: 
            brasil_val1 = brasil.densidade;
            argentina_val1 = argentina.densidade;
            break;
    }
    
    switch(attr2) {
        case POPULACAO: 
            brasil_val2 = brasil.populacao;
            argentina_val2 = argentina.populacao;
            break;
        case AREA: 
            brasil_val2 = brasil.area;
            argentina_val2 = argentina.area;
            break;
        case PIB: 
            brasil_val2 = brasil.pib;
            argentina_val2 = argentina.pib;
            break;
        case PONTOS: 
            brasil_val2 = brasil.pontos;
            argentina_val2 = argentina.pontos;
            break;
        case DENSIDADE: 
            brasil_val2 = brasil.densidade;
            argentina_val2 = argentina.densidade;
            break;
    }
    
    // Calcula somas
    float soma_brasil = brasil_val1 + brasil_val2;
    float soma_argentina = argentina_val1 + argentina_val2;
    
    // Exibe resultados
    printf("\nRESULTADOS:\n");
    printf("-------------\n");
    printf("%s: %s = %.2f, %s = %.2f\n", 
           brasil.nome, atributos[attr1], brasil_val1, atributos[attr2], brasil_val2);
    printf("%s: %s = %.2f, %s = %.2f\n", 
           argentina.nome, atributos[attr1], argentina_val1, atributos[attr2], argentina_val2);
    printf("-------------\n");
    printf("Soma %s: %.2f\n", brasil.nome, soma_brasil);
    printf("Soma %s: %.2f\n", argentina.nome, soma_argentina);
    printf("-------------\n");
    
    // Determina vencedor
    if(soma_brasil > soma_argentina) 
        printf("VENCEDOR: %s!\n", brasil.nome);
    else if(soma_argentina > soma_brasil) 
        printf("VENCEDOR: %s!\n", argentina.nome);
    else 
        printf("EMPATE!\n");

    return 0;
}