//inclui bibliotecas necessárias
#include <stdio.h>

//função principal
int main() {

    //declaração de variáveis
    char c1_estado[2], c2_estado[2], c1_codigo[3], c2_codigo[3], c1_cidade[20], c2_cidade[20];
    int c1_populacao, c2_populacao, c1_ponto, c2_ponto;
    float c1_area, c2_area, c1_pib, c2_pib;

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

    //imprime os dados das cartas
    printf("Carta 1: \n");
    printf("Estado: %s\n", c1_estado);
    printf("Codigo: %s\n", c1_codigo);
    printf("Cidade: %s\n", c1_cidade);
    printf("Populacao: %d\n", c1_populacao);
    printf("Area: %.2f km2\n", c1_area);
    printf("PIB: %.2f bilhões de reais\n", c1_pib);
    printf("Ponto: %d\n", c1_ponto);

    printf("\n\n");

    printf("Carta 2: \n");
    printf("Estado: %s\n", c2_estado);
    printf("Codigo: %s\n", c2_codigo);
    printf("Cidade: %s\n", c2_cidade);
    printf("Populacao: %d\n", c2_populacao);
    printf("Area: %.2f km2\n", c2_area);
    printf("PIB: %.2f bilhões de reais\n", c2_pib);
    printf("Ponto: %d\n", c2_ponto);

    return 0;
}
