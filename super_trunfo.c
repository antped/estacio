#include <stdio.h>
#include <string.h>

// Função para limpar o buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    // Estrutura de dados das cartas
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;

    // ==== CADASTRO CARTA 1 ====
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Digite o Nome da Cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';

    printf("Digite a Populacao: ");
    scanf("%lu", &populacao1);

    printf("Digite a Area (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de pontos turisticos: ");
    scanf("%d", &pontos1);
    limparBuffer();

    // ==== CADASTRO CARTA 2 ====
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Digite o Nome da Cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);

    printf("Digite a Area (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de pontos turisticos: ");
    scanf("%d", &pontos2);
    limparBuffer();

    // ==== CALCULA DERIVADOS ====
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = pib1 * 1000000000.0 / populacao1;
    float pibPerCapita2 = pib2 * 1000000000.0 / populacao2;

    // ==== MENU DE ATRIBUTOS ====
    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma1, soma2;

    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);

    // Segundo menu dinâmico
    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i == atributo1) continue; // não mostra o já escolhido
            switch (i) {
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
        printf("Opcao: ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("ERRO: Voce deve escolher atributos diferentes!\n");
        }
    } while (atributo2 == atributo1);

    // ==== ASSOCIA OS ATRIBUTOS ====
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontos1; valor1_c2 = pontos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
        case 6: valor1_c1 = pibPerCapita1; valor1_c2 = pibPerCapita2; break;
        default: printf("Opcao invalida!\n"); return 0;
    }

    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontos1; valor2_c2 = pontos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
        case 6: valor2_c1 = pibPerCapita1; valor2_c2 = pibPerCapita2; break;
        default: printf("Opcao invalida!\n"); return 0;
    }

    // ==== COMPARA ATRIBUTOS ====
    soma1 = soma2 = 0;

    // Primeiro atributo
    soma1 += (atributo1 == 5) ? -valor1_c1 : valor1_c1; // densidade: menor é melhor
    soma2 += (atributo1 == 5) ? -valor1_c2 : valor1_c2;

    // Segundo atributo
    soma1 += (atributo2 == 5) ? -valor2_c1 : valor2_c1;
    soma2 += (atributo2 == 5) ? -valor2_c2 : valor2_c2;

    // ==== RESULTADOS ====
    printf("\n==== RESULTADO ====\n");
    printf("%s:\n", nomeCidade1);
    printf("Atributo %d = %.2f\n", atributo1, valor1_c1);
    printf("Atributo %d = %.2f\n", atributo2, valor2_c1);
    printf("Soma Final = %.2f\n\n", soma1);

    printf("%s:\n", nomeCidade2);
    printf("Atributo %d = %.2f\n", atributo1, valor1_c2);
    printf("Atributo %d = %.2f\n", atributo2, valor2_c2);
    printf("Soma Final = %.2f\n\n", soma2);

    if (soma1 > soma2) {
        printf(">>> Vencedor: %s\n", nomeCidade1);
    } else if (soma2 > soma1) {
        printf(">>> Vencedor: %s\n", nomeCidade2);
    } else {
        printf(">>> Empate!\n");
    }

    return 0;
}
