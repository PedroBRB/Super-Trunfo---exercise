#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado;
    char codigo[4];
    char nome_pais[50];
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
                        (float)carta->pontos_turisticos + carta->pib_per_capita + 
                        (carta->densidade_populacional > 0 ? (1.0f / carta->densidade_populacional) : 0);
}

// Função para exibir informações da carta
void exibir_carta(Carta carta, int numero) {
    printf("=== CARTA %d ===\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("País: %s\n", carta.nome_pais);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
    printf("=====================================\n\n");
}

// Função para exibir o menu de opções
void exibir_menu() {
    printf("\n🃏 ========== SUPER TRUNFO ========== 🃏\n");
    printf("       ESCOLHA O ATRIBUTO PARA COMPARAÇÃO\n");
    printf("=========================================\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("8. Comparação Completa (todos os atributos)\n");
    printf("0. Sair do jogo\n");
    printf("=========================================\n");
    printf("Digite sua opção: ");
}

// Função para comparar dois valores e determinar o vencedor
int determinar_vencedor(float valor1, float valor2, int regra_inversa) {
    if (valor1 == valor2) {
        return 0; // Empate
    } else if (regra_inversa) {
        // Para densidade populacional: menor valor vence
        return (valor1 < valor2) ? 1 : 2;
    } else {
        // Para outros atributos: maior valor vence
        return (valor1 > valor2) ? 1 : 2;
    }
}

// Função para realizar comparação por atributo específico
void comparar_por_atributo(Carta carta1, Carta carta2, int opcao) {
    float valor1, valor2;
    char nome_atributo[30];
    int regra_inversa = 0; // 0 = maior vence, 1 = menor vence
    
    printf("\n🔥 ========== BATALHA ========== 🔥\n");
    printf("%s (Carta 1) VS %s (Carta 2)\n", carta1.nome_pais, carta2.nome_pais);
    printf("===================================\n");
    
    // Switch para determinar qual atributo comparar
    switch (opcao) {
        case 1: // População
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            strcpy(nome_atributo, "População");
            printf("Atributo: %s\n", nome_atributo);
            printf("%s: %.0f habitantes\n", carta1.nome_pais, valor1);
            printf("%s: %.0f habitantes\n", carta2.nome_pais, valor2);
            break;
            
        case 2: // Área
            valor1 = carta1.area;
            valor2 = carta2.area;
            strcpy(nome_atributo, "Área");
            printf("Atributo: %s\n", nome_atributo);
            printf("%s: %.2f km²\n", carta1.nome_pais, valor1);
            printf("%s: %.2f km²\n", carta2.nome_pais, valor2);
            break;
            
        case 3: // PIB
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            strcpy(nome_atributo, "PIB");
            printf("Atributo: %s\n", nome_atributo);
            printf("%s: %.2f bilhões de reais\n", carta1.nome_pais, valor1);
            printf("%s: %.2f bilhões de reais\n", carta2.nome_pais, valor2);
            break;
            
        case 4: // Pontos Turísticos
            valor1 = (float)carta1.pontos_turisticos;
            valor2 = (float)carta2.pontos_turisticos;
            strcpy(nome_atributo, "Pontos Turísticos");
            printf("Atributo: %s\n", nome_atributo);
            printf("%s: %.0f pontos\n", carta1.nome_pais, valor1);
            printf("%s: %.0f pontos\n", carta2.nome_pais, valor2);
            break;
            
        case 5: // Densidade Populacional (regra inversa)
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            strcpy(nome_atributo, "Densidade Populacional");
            regra_inversa = 1; // Menor valor vence
            printf("Atributo: %s (menor valor vence)\n", nome_atributo);
            printf("%s: %.2f hab/km²\n", carta1.nome_pais, valor1);
            printf("%s: %.2f hab/km²\n", carta2.nome_pais, valor2);
            break;
            
        case 6: // PIB per capita
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            strcpy(nome_atributo, "PIB per Capita");
            printf("Atributo: %s\n", nome_atributo);
            printf("%s: %.2f reais\n", carta1.nome_pais, valor1);
            printf("%s: %.2f reais\n", carta2.nome_pais, valor2);
            break;
            
        case 7: // Super Poder
            valor1 = carta1.super_poder;
            valor2 = carta2.super_poder;
            strcpy(nome_atributo, "Super Poder");
            printf("Atributo: %s\n", nome_atributo);
            printf("%s: %.2f pontos\n", carta1.nome_pais, valor1);
            printf("%s: %.2f pontos\n", carta2.nome_pais, valor2);
            break;
            
        default:
            printf("❌ Opção inválida!\n");
            return;
    }
    
    // Determinar o vencedor usando lógica aninhada
    int resultado = determinar_vencedor(valor1, valor2, regra_inversa);
    
    printf("-----------------------------------\n");
    
    // Estruturas de decisão aninhadas para exibir o resultado
    if (resultado == 0) {
        printf("🤝 RESULTADO: EMPATE!\n");
        printf("Ambos os países têm o mesmo valor para %s\n", nome_atributo);
    } else {
        if (resultado == 1) {
            printf("🏆 VENCEDOR: %s (Carta 1)\n", carta1.nome_pais);
            if (regra_inversa) {
                printf("Motivo: Menor %s (%.2f < %.2f)\n", nome_atributo, valor1, valor2);
            } else {
                printf("Motivo: Maior %s (%.2f > %.2f)\n", nome_atributo, valor1, valor2);
            }
        } else {
            printf("🏆 VENCEDOR: %s (Carta 2)\n", carta2.nome_pais);
            if (regra_inversa) {
                printf("Motivo: Menor %s (%.2f < %.2f)\n", nome_atributo, valor2, valor1);
            } else {
                printf("Motivo: Maior %s (%.2f > %.2f)\n", nome_atributo, valor2, valor1);
            }
        }
    }
    printf("===================================\n");
}

// Função para comparação completa (todos os atributos)
void comparacao_completa(Carta carta1, Carta carta2) {
    int vitorias_carta1 = 0, vitorias_carta2 = 0, empates = 0;
    
    printf("\n🔥 ===== COMPARAÇÃO COMPLETA ===== 🔥\n");
    printf("%s VS %s\n", carta1.nome_pais, carta2.nome_pais);
    printf("=====================================\n");
    
    // Array de atributos e valores para facilitar a comparação
    float valores1[] = {
        (float)carta1.populacao,
        carta1.area,
        carta1.pib,
        (float)carta1.pontos_turisticos,
        carta1.densidade_populacional,
        carta1.pib_per_capita,
        carta1.super_poder
    };
    
    float valores2[] = {
        (float)carta2.populacao,
        carta2.area,
        carta2.pib,
        (float)carta2.pontos_turisticos,
        carta2.densidade_populacional,
        carta2.pib_per_capita,
        carta2.super_poder
    };
    
    char* nomes_atributos[] = {
        "População",
        "Área",
        "PIB",
        "Pontos Turísticos",
        "Densidade Populacional",
        "PIB per Capita",
        "Super Poder"
    };
    
    // Comparar cada atributo
    for (int i = 0; i < 7; i++) {
        int regra_inversa = (i == 4) ? 1 : 0; // Densidade populacional tem regra inversa
        int resultado = determinar_vencedor(valores1[i], valores2[i], regra_inversa);
        
        printf("%s: ", nomes_atributos[i]);
        
        if (resultado == 0) {
            printf("Empate\n");
            empates++;
        } else if (resultado == 1) {
            printf("%s venceu\n", carta1.nome_pais);
            vitorias_carta1++;
        } else {
            printf("%s venceu\n", carta2.nome_pais);
            vitorias_carta2++;
        }
    }
    
    // Resultado final
    printf("=====================================\n");
    printf("PLACAR FINAL:\n");
    printf("%s: %d vitórias\n", carta1.nome_pais, vitorias_carta1);
    printf("%s: %d vitórias\n", carta2.nome_pais, vitorias_carta2);
    printf("Empates: %d\n", empates);
    printf("=====================================\n");
    
    // Determinar campeão geral
    if (vitorias_carta1 > vitorias_carta2) {
        printf("🏆 CAMPEÃO GERAL: %s\n", carta1.nome_pais);
    } else if (vitorias_carta2 > vitorias_carta1) {
        printf("🏆 CAMPEÃO GERAL: %s\n", carta2.nome_pais);
    } else {
        printf("🤝 RESULTADO GERAL: EMPATE!\n");
    }
    printf("=====================================\n");
}

// Função para cadastrar uma carta
void cadastrar_carta(Carta *carta, int numero) {
    printf("\n=== CADASTRO DA CARTA %d ===\n", numero);
    
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", carta->nome_pais);
    
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calcular valores derivados
    calcular_valores_derivados(carta);
    
    printf("✅ Carta cadastrada com sucesso!\n");
}

int main() {
    Carta carta1, carta2;
    int opcao;
    int cartas_cadastradas = 0;
    
    printf("🃏 ===== BEM-VINDO AO SUPER TRUNFO ===== 🃏\n");
    printf("Vamos começar cadastrando duas cartas!\n");
    printf("=======================================\n");
    
    // Cadastro das cartas
    cadastrar_carta(&carta1, 1);
    cartas_cadastradas++;
    
    cadastrar_carta(&carta2, 2);
    cartas_cadastradas++;
    
    // Exibir cartas cadastradas
    printf("\n📋 ===== CARTAS CADASTRADAS ===== 📋\n");
    exibir_carta(carta1, 1);
    exibir_carta(carta2, 2);
    
    // Loop principal do jogo
    do {
        exibir_menu();
        
        // Validação de entrada
        if (scanf("%d", &opcao) != 1) {
            printf("❌ Entrada inválida! Digite apenas números.\n");
            // Limpar buffer de entrada
            while (getchar() != '\n');
            continue;
        }
        
        // Switch principal para as opções do menu
        switch (opcao) {
            case 1: // População
            case 2: // Área
            case 3: // PIB
            case 4: // Pontos Turísticos
            case 5: // Densidade Populacional
            case 6: // PIB per Capita
            case 7: // Super Poder
                comparar_por_atributo(carta1, carta2, opcao);
                break;
                
            case 8: // Comparação Completa
                comparacao_completa(carta1, carta2);
                break;
                
            case 0: // Sair
                printf("\n👋 Obrigado por jogar Super Trunfo!\n");
                printf("Até a próxima batalha! 🃏\n");
                break;
                
            default: // Opção inválida
                printf("\n❌ Opção inválida! Escolha uma opção entre 0 e 8.\n");
                printf("Tente novamente.\n");
                break;
        }
        
        // Pausa para o usuário ver o resultado
        if (opcao >= 1 && opcao <= 8) {
            printf("\nPressione ENTER para continuar...");
            getchar(); // Consumir o \n do scanf anterior
            getchar(); // Esperar o usuário pressionar ENTER
        }
        
    } while (opcao != 0);
    
    return 0;
}