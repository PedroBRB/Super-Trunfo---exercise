#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char code[4];               // Código da carta
    char name[50];             // Nome do país
    float population;          // População em milhões
    float area;               // Área em km²
    float gdp;                // PIB em trilhões de USD
    float density;            // Densidade demográfica hab/km²
    int tourist_spots;        // Quantidade de pontos turísticos
} Card;

// Função para exibir o menu de atributos
int displayAttributeMenu() {
    printf("\n=== CHOOSE AN ATTRIBUTE ===\n");
    printf("1. Population (millions of inhabitants)\n");
    printf("2. Area (km²)\n");
    printf("3. GDP (trillions USD)\n");
    printf("4. Population Density (inhabitants/km²)\n");
    printf("5. Tourist Spots\n");
    printf("Enter your choice (1-5): ");
    
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Função para obter o valor do atributo escolhido
float getAttributeValue(Card card, int attribute) {
    switch(attribute) {
        case 1: return card.population;
        case 2: return card.area;
        case 3: return card.gdp;
        case 4: return card.density;
        case 5: return (float)card.tourist_spots;
        default: return 0.0;
    }
}

// Função para obter o nome do atributo
const char* getAttributeName(int attribute) {
    switch(attribute) {
        case 1: return "Population";
        case 2: return "Area";
        case 3: return "GDP";
        case 4: return "Population Density";
        case 5: return "Tourist Spots";
        default: return "Invalid Attribute";
    }
}

// Função para obter a unidade do atributo
const char* getAttributeUnit(int attribute) {
    switch(attribute) {
        case 1: return "million inhabitants";
        case 2: return "km²";
        case 3: return "trillion USD";
        case 4: return "inhabitants/km²";
        case 5: return "spots";
        default: return "";
    }
}

// Função para comparar dois valores considerando a regra especial da densidade
int compareValues(float value1, float value2, int attribute) {
    // Para densidade demográfica, menor valor vence
    if (attribute == 4) {
        if (value1 < value2) return 1;      // Carta 1 vence
        else if (value1 > value2) return 2; // Carta 2 vence
        else return 0;                      // Empate
    }
    // Para outros atributos, maior valor vence
    else {
        if (value1 > value2) return 1;      // Carta 1 vence
        else if (value1 < value2) return 2; // Carta 2 vence
        else return 0;                      // Empate
    }
}

// Função para exibir informações detalhadas da comparação
void displayComparison(Card card1, Card card2, int attr1, int attr2) {
    printf("\n============================================================\n");
    printf("            CARD COMPARISON - SUPER TRUMP\n");
    printf("============================================================\n");
    
    // Informações das cartas
    printf("CARD 1: %s (%s)\n", card1.name, card1.code);
    printf("CARD 2: %s (%s)\n", card2.name, card2.code);
    
    printf("\n--- CHOSEN ATTRIBUTES ---\n");
    
    // Valores dos atributos escolhidos
    float value1_attr1 = getAttributeValue(card1, attr1);
    float value2_attr1 = getAttributeValue(card2, attr1);
    float value1_attr2 = getAttributeValue(card1, attr2);
    float value2_attr2 = getAttributeValue(card2, attr2);
    
    // Exibir comparação do primeiro atributo
    printf("\n1st ATTRIBUTE: %s\n", getAttributeName(attr1));
    printf("   %s: %.2f %s\n", card1.name, value1_attr1, getAttributeUnit(attr1));
    printf("   %s: %.2f %s\n", card2.name, value2_attr1, getAttributeUnit(attr1));
    
    int result1 = compareValues(value1_attr1, value2_attr1, attr1);
    printf("   Winner: %s\n", 
           result1 == 1 ? card1.name : 
           result1 == 2 ? card2.name : "TIE");
    
    // Exibir comparação do segundo atributo
    printf("\n2nd ATTRIBUTE: %s\n", getAttributeName(attr2));
    printf("   %s: %.2f %s\n", card1.name, value1_attr2, getAttributeUnit(attr2));
    printf("   %s: %.2f %s\n", card2.name, value2_attr2, getAttributeUnit(attr2));
    
    int result2 = compareValues(value1_attr2, value2_attr2, attr2);
    printf("   Winner: %s\n", 
           result2 == 1 ? card1.name : 
           result2 == 2 ? card2.name : "TIE");
    
    // Cálculo das somas
    float sum1 = value1_attr1 + value1_attr2;
    float sum2 = value2_attr1 + value2_attr2;
    
    printf("\n--- ATTRIBUTE SUM ---\n");
    printf("%s: %.2f + %.2f = %.2f\n", card1.name, value1_attr1, value1_attr2, sum1);
    printf("%s: %.2f + %.2f = %.2f\n", card2.name, value2_attr1, value2_attr2, sum2);
    
    // Resultado final
    printf("\n--- FINAL RESULT ---\n");
    if (sum1 > sum2) {
        printf("🏆 WINNER: %s!\n", card1.name);
        printf("Difference: %.2f points\n", sum1 - sum2);
    } else if (sum2 > sum1) {
        printf("🏆 WINNER: %s!\n", card2.name);
        printf("Difference: %.2f points\n", sum2 - sum1);
    } else {
        printf("🤝 TIE!\n");
        printf("Both cards scored %.2f points\n", sum1);
    }
    
    printf("============================================================\n");
}

// Função para validar escolha de atributo
int validateAttribute(int attribute) {
    return (attribute >= 1 && attribute <= 5);
}

int main() {
    // Cartas pré-cadastradas do Super Trunfo - Países
    Card cards[4] = {
        {"A01", "Brazil", 215.3, 8514.8, 2.61, 25.3, 12},
        {"A02", "United States", 331.9, 9833.5, 25.46, 33.7, 25},
        {"A03", "China", 1412.0, 9596.9, 17.73, 147.1, 18},
        {"A04", "Japan", 125.7, 377.9, 4.24, 332.6, 22}
    };
    
    printf("🌟 WELCOME TO SUPER TRUMP - ADVANCED COMPARISONS! 🌟\n");
    printf("Let's compare two cards using TWO different attributes!\n");
    
    // Exibir cartas disponíveis
    printf("\n--- AVAILABLE CARDS ---\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (%s)\n", i+1, cards[i].name, cards[i].code);
    }
    
    // Escolher as duas cartas
    int card1_idx, card2_idx;
    
    do {
        printf("\nChoose the first card (1-4): ");
        scanf("%d", &card1_idx);
        card1_idx--; // Ajustar para índice do array
        
        if (card1_idx < 0 || card1_idx > 3) {
            printf("❌ Invalid choice! Enter a number between 1 and 4.\n");
        }
    } while (card1_idx < 0 || card1_idx > 3);
    
    do {
        printf("Choose the second card (1-4): ");
        scanf("%d", &card2_idx);
        card2_idx--; // Ajustar para índice do array
        
        if (card2_idx < 0 || card2_idx > 3) {
            printf("❌ Invalid choice! Enter a number between 1 and 4.\n");
        } else if (card2_idx == card1_idx) {
            printf("❌ Choose a different card from the first one!\n");
            card2_idx = -1; // Forçar nova escolha
        }
    } while (card2_idx < 0 || card2_idx > 3);
    
    printf("\n✅ Selected cards:\n");
    printf("   Card 1: %s\n", cards[card1_idx].name);
    printf("   Card 2: %s\n", cards[card2_idx].name);
    
    // Escolher primeiro atributo
    int attribute1, attribute2;
    
    printf("\n🎯 Now choose the FIRST attribute for comparison:");
    do {
        attribute1 = displayAttributeMenu();
        if (!validateAttribute(attribute1)) {
            printf("❌ Invalid choice! Enter a number between 1 and 5.\n");
        }
    } while (!validateAttribute(attribute1));
    
    printf("✅ First attribute: %s\n", getAttributeName(attribute1));
    
    // Escolher segundo atributo (diferente do primeiro)
    printf("\n🎯 Now choose the SECOND attribute (must be different from the first):");
    do {
        attribute2 = displayAttributeMenu();
        if (!validateAttribute(attribute2)) {
            printf("❌ Invalid choice! Enter a number between 1 and 5.\n");
        } else if (attribute2 == attribute1) {
            printf("❌ Choose a different attribute from the first one!\n");
            attribute2 = 0; // Forçar nova escolha
        }
    } while (!validateAttribute(attribute2) || attribute2 == attribute1);
    
    printf("✅ Second attribute: %s\n", getAttributeName(attribute2));
    
    // Realizar e exibir a comparação
    displayComparison(cards[card1_idx], cards[card2_idx], attribute1, attribute2);
    
    // Opção de jogar novamente
    char play_again;
    printf("\nDo you want to make a new comparison? (y/n): ");
    scanf(" %c", &play_again);
    
    if (play_again == 'y' || play_again == 'Y') {
        printf("\n🔄 Restarting the game...\n\n");
        main(); // Recursão simples para reiniciar
    } else {
        printf("\n🎮 Thank you for playing Super Trump! See you next time! 🎮\n");
    }
    
    return 0;
}