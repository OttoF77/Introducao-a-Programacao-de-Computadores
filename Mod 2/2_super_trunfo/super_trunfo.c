//inclui bibliotecas necessárias
#include <stdio.h>

//função principal
int main() {

    //declaração de variáveis
    char c1_estado[3], c2_estado[3], c1_codigo[4], c2_codigo[4], c1_cidade[50], c2_cidade[50];
    int c1_ponto, c2_ponto;
    unsigned long int c1_populacao, c2_populacao;
    float c1_area, c2_area, c1_pib, c2_pib, c1_densidade, c2_densidade, c1_pib_per_capita, c2_pib_per_capita;

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

    printf("PIB (Bilhoes de US$):\n");
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

    printf("PIB (Bilhoes de US$):\n");
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

    //Comparar um atributo das duas cartas
    //Atributo escolhido: PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita): \n");
    
    printf("Carta 1 - %s (%s): %.f \n", c1_cidade, c1_estado, c1_pib_per_capita);

    printf("Carta 2 - %s (%s): %.f \n", c2_cidade, c2_estado, c2_pib_per_capita);

    if (c1_pib_per_capita > c2_pib_per_capita){
        printf("Carta 1 vence!\n");
    } else if (c1_pib_per_capita < c2_pib_per_capita){
        printf("Carta 2 vence!\n");
    } else {
        printf("Empate!\n");
    }
    
    return 0;
}
