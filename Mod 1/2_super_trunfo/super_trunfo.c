//inclui bibliotecas necessárias
#include <stdio.h>

//função principal
int main() {

    //declaração de variáveis
    char c1_estado[3], c2_estado[3], c1_codigo[4], c2_codigo[4], c1_cidade[50], c2_cidade[50];
    int c1_ponto, c2_ponto;
    unsigned long int c1_populacao, c2_populacao;
    float c1_area, c2_area, c1_pib, c2_pib, c1_densidade, c2_densidade, c1_pib_per_capita, c2_pib_per_capita, c1_superpoder, c2_superpoder, c1_inv_densidade, c2_inv_densidade;

    //solicita e recebe os dados inseridos pelo usuário
    printf("insira os dados da primeira carta: \n");

    printf("Estado:\n");
    scanf(" %s", c1_estado);

    printf("Codigo:\n");
    scanf("%s", c1_codigo);

    printf("Cidade:\n");
    scanf("%s", c1_cidade);

    printf("Populacao:\n");
    scanf("%d", &c1_populacao);

    printf("Area:\n");
    scanf("%f", &c1_area);

    printf("PIB:\n");
    scanf("%f", &c1_pib);

    printf("Ponto:\n");
    scanf("%d", &c1_ponto); 

    printf("\n\n");

    //solicita e recebe os dados da segunda carta
    printf("insira os dados da segunda carta:\n");

    printf("Estado:\n");
    scanf(" %s", c2_estado);

    printf("Codigo:\n");
    scanf("%s", c2_codigo);

    printf("Cidade:\n");
    scanf("%s", c2_cidade);

    printf("Populacao:\n");
    scanf("%d", &c2_populacao);

    printf("Area:\n");
    scanf("%f", &c2_area);

    printf("PIB:\n");
    scanf("%f", &c2_pib);

    printf("Ponto:\n");
    scanf("%d", &c2_ponto);

    printf("\n\n");

    //cálculo da densidade populacional e PIB per capita
    if (c1_area != 0) {
        c1_densidade = (float) c1_populacao / c1_area;
    } else {
        c1_densidade = 0;
    }
    
    if (c2_area != 0) {
        c2_densidade = (float) c2_populacao / c2_area;
    } else {
        c2_densidade = 0;
    }
    
    if (c1_populacao != 0) {
        c1_pib_per_capita = (float) c1_pib * 1000000000 / c1_populacao;
    } else {
        c1_pib_per_capita = 0;
    }
    
    if (c2_populacao != 0) {
        c2_pib_per_capita = (float) c2_pib * 1000000000 / c2_populacao;
    } else {
        c2_pib_per_capita = 0;
    }

    //cálculo do inverso da densidade
    if (c1_densidade != 0) {
        c1_inv_densidade = 1 / c1_densidade;
    } else {
        c1_inv_densidade = 0;
    }

    if (c2_densidade != 0) {
        c2_inv_densidade = 1 / c2_densidade;
    } else {
        c2_inv_densidade = 0;
    }

    //Calcular superpoder
    
    c1_superpoder = (float)(c1_populacao + c1_area + c1_pib + c1_ponto + c1_inv_densidade + c1_pib_per_capita);
    c2_superpoder = (float)(c2_populacao + c2_area + c2_pib + c2_ponto + c2_inv_densidade + c2_pib_per_capita);    
    
    //imprime os dados das cartas
    printf("Carta 1: \n");
    printf("Estado: %s\n", c1_estado);
    printf("Codigo: %s\n", c1_codigo);
    printf("Cidade: %s\n", c1_cidade);
    printf("Populacao: %d\n", c1_populacao);
    printf("Area: %.2f km2\n", c1_area);
    printf("PIB: %.2f bilhões de reais\n", c1_pib);
    printf("Ponto: %d\n", c1_ponto);
    printf("Densidade: %.2f hab/km2\n", c1_densidade);
    printf("PIB per capita: %.2f reais\n", c1_pib_per_capita);

    printf("\n\n");

    printf("Carta 2: \n");
    printf("Estado: %s\n", c2_estado);
    printf("Codigo: %s\n", c2_codigo);
    printf("Cidade: %s\n", c2_cidade);
    printf("Populacao: %d\n", c2_populacao);
    printf("Area: %.2f km2\n", c2_area);
    printf("PIB: %.2f bilhões de reais\n", c2_pib);
    printf("Ponto: %d\n", c2_ponto);
    printf("Densidade: %.2f hab/km2\n", c2_densidade);
    printf("PIB per capita: %.2f reais\n", c2_pib_per_capita);

    //Comparar resultado das duas cartas
    printf("\nComparacao de Cartas:\n\n");
    
    int pop_result = c1_populacao > c2_populacao;
    printf("Populacao: Carta %d venceu (%d)\n\n", pop_result ? 1 : 2, pop_result);
    
    int area_result = c1_area > c2_area;
    printf("Area: Carta %d venceu (%d)\n\n", area_result ? 1 : 2, area_result);
    
    int pib_result = c1_pib > c2_pib;
    printf("PIB: Carta %d venceu (%d)\n\n", pib_result ? 1 : 2, pib_result);
    
    int ponto_result = c1_ponto > c2_ponto;
    printf("Pontos Turisticos: Carta %d venceu (%d)\n\n", ponto_result ? 1 : 2, ponto_result);
    
    int densidade_result = c1_densidade > c2_densidade;
    printf("Densidade Populacional: Carta %d venceu (%d)\n\n", densidade_result ? 1 : 2, densidade_result);
    
    int pib_pc_result = c1_pib_per_capita > c2_pib_per_capita;
    printf("PIB per Capita: Carta %d venceu (%d)\n\n", pib_pc_result ? 1 : 2, pib_pc_result);
    
    int super_result = c1_superpoder > c2_superpoder;
    printf("Super Poder: Carta %d venceu (%d)\n\n", super_result ? 1 : 2, super_result);

    return 0;
}
