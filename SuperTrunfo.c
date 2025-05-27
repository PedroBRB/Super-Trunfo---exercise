#include <stdio.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1;
    char codigo1[4];        // Array para armazenar código como "A01"
    char cidade1[50];       // Array para nome da cidade
    unsigned long int populacao1;  // Mudança para unsigned long int
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade_populacional1;  // Densidade populacional calculada
    float pib_per_capita1;         // PIB per capita calculado
    float super_poder1;            // Super poder calculado
    
    // Declaração das variáveis para a segunda carta
    char estado2;
    char codigo2[4];        // Array para armazenar código como "B02"
    char cidade2[50];       // Array para nome da cidade
    unsigned long int populacao2;  // Mudança para unsigned long int
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade_populacional2;  // Densidade populacional calculada
    float pib_per_capita2;         // PIB per capita calculado
    float super_poder2;            // Super poder calculado
    
    // === CADASTRO DA PRIMEIRA CARTA ===
    printf("=== CADASTRO DA CARTA 1 ===\n");
    
    printf("Digite o estado (A-H): ");
    scanf_s(" %c", &estado1);  // Espaço antes de %c para ignorar quebras de linha
    
    printf("Digite o código da carta (ex: A01): ");
    scanf_s("%s", codigo1, sizeof(codigo1));
    
    printf("Digite o nome da cidade: ");
    scanf_s(" %[^\n]", cidade1, sizeof(cidade1));  // %[^\n] lê linha completa incluindo espaços
    
    printf("Digite a população: ");
    scanf_s("%lu", &populacao1);  // %lu para unsigned long int
    
    printf("Digite a área (km²): ");
    scanf_s("%f", &area1);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf_s("%f", &pib1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf_s("%d", &pontos_turisticos1);
    
    printf("\n"); // Linha em branco para separar
    
    // === CÁLCULOS PARA A PRIMEIRA CARTA ===
    densidade_populacional1 = (float)populacao1 / area1;  // Conversão explícita para float
    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;  // Conversões para float
    
    // Cálculo do Super Poder: soma todos os atributos + inverso da densidade populacional
    super_poder1 = (float)populacao1 + area1 + (pib1 * 1000000000.0f) + 
                   (float)pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade_populacional1);
    
    // === CADASTRO DA SEGUNDA CARTA ===
    printf("=== CADASTRO DA CARTA 2 ===\n");
    
    printf("Digite o estado (A-H): ");
    scanf_s(" %c", &estado2);
    
    printf("Digite o código da carta (ex: B02): ");
    scanf_s("%s", codigo2, sizeof(codigo2));
    
    printf("Digite o nome da cidade: ");
    scanf_s(" %[^\n]", cidade2, sizeof(cidade2));
    
    printf("Digite a população: ");
    scanf_s("%lu", &populacao2);  // %lu para unsigned long int
    
    printf("Digite a área (km²): ");
    scanf_s("%f", &area2);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf_s("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf_s("%d", &pontos_turisticos2);
    
    printf("\n"); // Linha em branco para separar
    
    // === CÁLCULOS PARA A SEGUNDA CARTA ===
    densidade_populacional2 = (float)populacao2 / area2;  // Conversão explícita para float
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;  // Conversões para float
    
    // Cálculo do Super Poder: soma todos os atributos + inverso da densidade populacional
    super_poder2 = (float)populacao2 + area2 + (pib2 * 1000000000.0f) + 
                   (float)pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade_populacional2);
    
    // === EXIBIÇÃO DAS CARTAS CADASTRADAS ===
    printf("===================================\n");
    printf("       CARTAS CADASTRADAS\n");
    printf("===================================\n\n");
    
    // Exibição da primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);  // %lu para unsigned long int
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);
    
    printf("\n"); // Linha em branco entre as cartas
    
    // Exibição da segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);  // %lu para unsigned long int
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);
    
    printf("\n===================================\n");
    printf("       BATALHA DE CARTAS\n");
    printf("===================================\n\n");
    
    // === COMPARAÇÃO DAS CARTAS ===
    printf("Comparação de Cartas:\n");
    
    // População (maior vence)
    printf("População: ");
    if (populacao1 > populacao2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    // Área (maior vence)
    printf("Área: ");
    if (area1 > area2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    // PIB (maior vence)
    printf("PIB: ");
    if (pib1 > pib2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    // Pontos Turísticos (maior vence)
    printf("Pontos Turísticos: ");
    if (pontos_turisticos1 > pontos_turisticos2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    // Densidade Populacional (MENOR vence - regra especial)
    printf("Densidade Populacional: ");
    if (densidade_populacional1 < densidade_populacional2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    // PIB per Capita (maior vence)
    printf("PIB per Capita: ");
    if (pib_per_capita1 > pib_per_capita2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    // Super Poder (maior vence)
    printf("Super Poder: ");
    if (super_poder1 > super_poder2) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
    }
    
    printf("\n===================================\n");
    printf("Batalha concluída!\n");
    
    return 0;
}