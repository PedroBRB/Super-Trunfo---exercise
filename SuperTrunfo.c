#include <stdio.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1;
    char codigo1[4];        // Array para armazenar código como "A01"
    char cidade1[50];       // Array para nome da cidade
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade_populacional1;  // Densidade populacional calculada
    float pib_per_capita1;         // PIB per capita calculado
    
    // Declaração das variáveis para a segunda carta
    char estado2;
    char codigo2[4];        // Array para armazenar código como "B02"
    char cidade2[50];       // Array para nome da cidade
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade_populacional2;  // Densidade populacional calculada
    float pib_per_capita2;         // PIB per capita calculado
    
    // === CADASTRO DA PRIMEIRA CARTA ===
    printf("=== CADASTRO DA CARTA 1 ===\n");
    
    printf("Digite o estado (A-H): ");
    scanf_s(" %c", &estado1);  // Espaço antes de %c para ignorar quebras de linha
    
    printf("Digite o código da carta (ex: A01): ");
    scanf_s("%s", codigo1, sizeof(codigo1));
    
    printf("Digite o nome da cidade: ");
    scanf_s(" %[^\n]", cidade1, sizeof(cidade1));  // %[^\n] lê linha completa incluindo espaços
    
    printf("Digite a população: ");
    scanf_s("%d", &populacao1);
    
    printf("Digite a área (km²): ");
    scanf_s("%f", &area1);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf_s("%f", &pib1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf_s("%d", &pontos_turisticos1);
    
    printf("\n"); // Linha em branco para separar
    
    // === CÁLCULOS PARA A PRIMEIRA CARTA ===
    densidade_populacional1 = populacao1 / area1;  // Habitantes por km²
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;  // PIB em reais dividido pela população
    
    // === CADASTRO DA SEGUNDA CARTA ===
    printf("=== CADASTRO DA CARTA 2 ===\n");
    
    printf("Digite o estado (A-H): ");
    scanf_s(" %c", &estado2);
    
    printf("Digite o código da carta (ex: B02): ");
    scanf_s("%s", codigo2, sizeof(codigo2));
    
    printf("Digite o nome da cidade: ");
    scanf_s(" %[^\n]", cidade2, sizeof(cidade2));
    
    printf("Digite a população: ");
    scanf_s("%d", &populacao2);
    
    printf("Digite a área (km²): ");
    scanf_s("%f", &area2);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf_s("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf_s("%d", &pontos_turisticos2);
    
    printf("\n"); // Linha em branco para separar
    
    // === CÁLCULOS PARA A SEGUNDA CARTA ===
    densidade_populacional2 = populacao2 / area2;  // Habitantes por km²
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;  // PIB em reais dividido pela população
    
    // === EXIBIÇÃO DAS CARTAS CADASTRADAS ===
    printf("===================================\n");
    printf("       CARTAS CADASTRADAS\n");
    printf("===================================\n\n");
    
    // Exibição da primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    
    printf("\n"); // Linha em branco entre as cartas
    
    // Exibição da segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    
    printf("\n===================================\n");
    printf("Cadastro concluído com sucesso!\n");
    
    return 0;
}