#include <stdio.h>
#include <string.h>


typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular valores derivados 
void calcular_valores_derivados(Carta *carta) {
    // Densidade populacional = população / área
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
    
    // PIB per capita = PIB (convertido para reais) / população
    if (carta->populacao > 0) {
        carta->pib_per_capita = (carta->pib * 1000000000.0f) / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
    
    // Cálculo do Super Poder 
    carta->super_poder = (float)carta->populacao + carta->area + (carta->pib * 1000000000.0f) + 
                        (float)carta->pontos_turisticos + carta->pib_per_capita + (1.0f / carta->densidade_populacional);
}

// Função para exibir informações da carta 
void exibir_carta(Carta carta) {
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.cidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
    printf("----------------------------------------\n");
}

// Função para comparar cartas por um atributo específico
void comparar_cartas(Carta carta1, Carta carta2, int atributo) {
    printf("=== COMPARAÇÃO DE CARTAS ===\n\n");
    
    printf("CARTA 1:\n");
    exibir_carta(carta1);
    
    printf("CARTA 2:\n");
    exibir_carta(carta2);
    
    printf("=== RESULTADO DA COMPARAÇÃO ===\n");
    
    // Variáveis para armazenar os valores comparados e o nome do atributo
    float valor1, valor2;
    char nome_atributo[30];
    int carta1_vence = 0; // Flag para indicar se carta1 vence
    
    // Switch para escolher o atributo a ser comparado
    switch (atributo) {
        case 1: // População
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            strcpy(nome_atributo, "População");
            // Para população, maior valor vence
            if (valor1 > valor2) {
                carta1_vence = 1;
            }
            break;
            
        case 2: // Área
            valor1 = carta1.area;
            valor2 = carta2.area;
            strcpy(nome_atributo, "Área");
            // Para área, maior valor vence
            if (valor1 > valor2) {
                carta1_vence = 1;
            }
            break;
            
        case 3: // PIB
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            strcpy(nome_atributo, "PIB");
            // Para PIB, maior valor vence
            if (valor1 > valor2) {
                carta1_vence = 1;
            }
            break;
            
        case 4: // Pontos Turísticos
            valor1 = (float)carta1.pontos_turisticos;
            valor2 = (float)carta2.pontos_turisticos;
            strcpy(nome_atributo, "Pontos Turísticos");
            // Para pontos turísticos, maior valor vence
            if (valor1 > valor2) {
                carta1_vence = 1;
            }
            break;
            
        case 5: // Densidade Populacional
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            strcpy(nome_atributo, "Densidade Populacional");
            // Para densidade populacional, MENOR valor vence (menos densidade = melhor)
            if (valor1 < valor2) {
                carta1_vence = 1;
            }
            break;
            
        case 7: // Super Poder
            valor1 = carta1.super_poder;
            valor2 = carta2.super_poder;
            strcpy(nome_atributo, "Super Poder");
            // Para super poder, maior valor vence
            if (valor1 > valor2) {
                carta1_vence = 1;
            }
            break;
            
        default:
            printf("Atributo inválido!\n");
            return;
    }
    
    // Exibir os valores comparados
    printf("Atributo comparado: %s\n", nome_atributo);
    printf("%s (%c - %s): %.2f\n", carta1.cidade, carta1.estado, carta1.codigo, valor1);
    printf("%s (%c - %s): %.2f\n", carta2.cidade, carta2.estado, carta2.codigo, valor2);
    printf("\n");
    
    // Determinar e exibir o vencedor
    if (valor1 == valor2) {
        printf("🤝 EMPATE! Ambas as cartas têm o mesmo valor para %s.\n", nome_atributo);
    } else if (carta1_vence == 1) {
        printf("🏆 VENCEDORA: %s (%c - %s)\n", carta1.cidade, carta1.estado, carta1.codigo);
        if (atributo == 5) { // Caso especial da densidade populacional
            printf("Motivo: Menor densidade populacional (%.2f < %.2f)\n", valor1, valor2);
        } else {
            printf("Motivo: Maior %s (%.2f > %.2f)\n", nome_atributo, valor1, valor2);
        }
    } else {
        printf("🏆 VENCEDORA: %s (%c - %s)\n", carta2.cidade, carta2.estado, carta2.codigo);
        if (atributo == 5) { // Caso especial da densidade populacional
            printf("Motivo: Menor densidade populacional (%.2f < %.2f)\n", valor2, valor1);
        } else {
            printf("Motivo: Maior %s (%.2f > %.2f)\n", nome_atributo, valor2, valor1);
        }
    }
}

int main() {
    // Declaração das cartas 
    Carta carta1, carta2;
    
    // === CADASTRO DA PRIMEIRA CARTA ===
    printf("=== CADASTRO DA CARTA 1 ===\n");
    
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta1.estado);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade);
    
    printf("Digite a população: ");
    scanf("%lu", &carta1.populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta1.area);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf("%f", &carta1.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    
    printf("\n"); 
    
    // === CADASTRO DA SEGUNDA CARTA ===
    printf("=== CADASTRO DA CARTA 2 ===\n");
    
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta2.estado);
    
    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade);
    
    printf("Digite a população: ");
    scanf("%lu", &carta2.populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta2.area);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf("%f", &carta2.pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    
    printf("\n"); 
    
    // Calcular valores derivados para ambas as cartas
    calcular_valores_derivados(&carta1);
    calcular_valores_derivados(&carta2);
    
    // === EXIBIÇÃO DAS CARTAS CADASTRADAS ===
    printf("===================================\n");
    printf("       CARTAS CADASTRADAS\n");
    printf("===================================\n\n");
    
    printf("CARTA 1:\n");
    exibir_carta(carta1);
    
    printf("CARTA 2:\n");
    exibir_carta(carta2);
    
    printf("🃏 SUPER TRUNFO - COMPARAÇÃO DETALHADA 🃏\n");
    printf("==========================================\n\n");
    
    // Definir qual atributo será comparado (você pode alterar este valor)
    // 1 = População, 2 = Área, 3 = PIB, 4 = Pontos Turísticos, 5 = Densidade Populacional, 6 = PIB per capita, 7 = Super Poder
    int atributo_escolhido = 3; // Exemplo: comparando por PIB
    
    printf("Atributo selecionado para comparação: ");
    switch (atributo_escolhido) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Populacional\n"); break;
        case 6: printf("PIB per capita\n"); break;
        case 7: printf("Super Poder\n"); break;
    }
    printf("\n");
    
    // Realizar a comparação principal
    comparar_cartas(carta1, carta2, atributo_escolhido);
    
    printf("\n===================================\n");
    printf("    COMPARAÇÃO COMPLETA (BONUS)\n");
    printf("===================================\n");
    printf("Resultado de todas as comparações:\n\n");
    
    // === COMPARAÇÃO COMPLETA  ===
    
    // População (maior vence)
    printf("População: ");
    if (carta1.populacao > carta2.populacao) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    // Área (maior vence)
    printf("Área: ");
    if (carta1.area > carta2.area) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.area > carta1.area) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    // PIB (maior vence)
    printf("PIB: ");
    if (carta1.pib > carta2.pib) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.pib > carta1.pib) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    // Pontos Turísticos (maior vence)
    printf("Pontos Turísticos: ");
    if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    // Densidade Populacional (MENOR vence - regra especial)
    printf("Densidade Populacional: ");
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    // PIB per Capita (maior vence)
    printf("PIB per Capita: ");
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    // Super Poder (maior vence)
    printf("Super Poder: ");
    if (carta1.super_poder > carta2.super_poder) {
        printf("Carta 1 venceu (%s)\n", carta1.cidade);
    } else if (carta2.super_poder > carta1.super_poder) {
        printf("Carta 2 venceu (%s)\n", carta2.cidade);
    } else {
        printf("Empate\n");
    }
    
    printf("\n===================================\n");
    printf("Batalha concluída!\n");
    
    return 0;
}