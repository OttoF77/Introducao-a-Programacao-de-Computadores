//inclui bibliotecas necessárias
#include <stdio.h>

//função principal
int main() {

    //declaração de variáveis
    char c1_estado[3], c2_estado[3], c1_codigo[4], c2_codigo[4], c1_cidade[50], c2_cidade[50];
    int c1_ponto, c2_ponto;
    unsigned long int c1_populacao, c2_populacao;
    float c1_area, c2_area, c1_pib, c2_pib, c1_densidade, c2_densidade, c1_pib_per_capita, c2_pib_per_capita, c1_inv_densidade, c2_inv_densidade;

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

    //Cria o menu de comparação
    int opcao;
    
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    scanf("%d", &opcao);
    
    switch (opcao)
    {
    case 1:
        if (c1_populacao > c2_populacao){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando População...\n");
            printf("Estado: %s - População: %lu X Estado: %s - População: %lu\n", c1_estado, c1_populacao, c2_estado, c2_populacao);
            printf("Estado: %s vence!\n", c1_estado);
        } else if (c1_populacao < c2_populacao){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando População...\n");
            printf("Estado: %s - População: %lu X Estado: %s - População: %lu\n", c1_estado, c1_populacao, c2_estado, c2_populacao);
            printf("Estado: %s vence!\n", c2_estado);
        } else {
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando População...\n");
            printf("Estado: %s - População: %lu X Estado: %s - População: %lu\n", c1_estado, c1_populacao, c2_estado, c2_populacao);
            printf("Partida empatada!\n");
        }
        break;

    case 2:
        if (c1_area > c2_area){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Área...\n");
            printf("Estado: %s - Área: %.2f km² X Estado: %s - Área: %.2f km²\n", c1_estado, c1_area, c2_estado, c2_area);
            printf("Estado: %s vence!\n", c1_estado);
        } else if (c1_area < c2_area){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Área...\n");
            printf("Estado: %s - Área: %.2f km² X Estado: %s - Área: %.2f km²\n", c1_estado, c1_area, c2_estado, c2_area);
            printf("Estado: %s vence!\n", c2_estado);
        } else {
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Área...\n");
            printf("Estado: %s - Área: %.2f km² X Estado: %s - Área: %.2f km²\n", c1_estado, c1_area, c2_estado, c2_area);
            printf("Partida empatada!\n");
        }
        break;

    case 3:
        if (c1_pib > c2_pib){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando PIB...\n");
            printf("Estado: %s - PIB: %.2f bilhões de US$ X Estado: %s - PIB: %.2f bilhões de US$\n", c1_estado, c1_pib, c2_estado, c2_pib);
            printf("Estado: %s vence!\n", c1_estado);
        } else if (c1_pib < c2_pib){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando PIB...\n");
            printf("Estado: %s - PIB: %.2f bilhões de US$ X Estado: %s - PIB: %.2f bilhões de US$\n", c1_estado, c1_pib, c2_estado, c2_pib);
            printf("Estado: %s vence!\n", c2_estado);
        } else {
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando PIB...\n");
            printf("Estado: %s - PIB: %.2f bilhões de US$ X Estado: %s - PIB: %.2f bilhões de US$\n", c1_estado, c1_pib, c2_estado, c2_pib);
            printf("Partida empatada!\n");
        }
        break;

    case 4:
        if (c1_ponto > c2_ponto){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Número de Pontos Turísticos...\n");
            printf("Estado: %s - Pontos Turísticos: %d X Estado: %s - Pontos Turísticos: %d\n", c1_estado, c1_ponto, c2_estado, c2_ponto);
            printf("Estado: %s vence!\n", c1_estado);
        } else if (c1_ponto < c2_ponto){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Número de Pontos Turísticos...\n");
            printf("Estado: %s - Pontos Turísticos: %d X Estado: %s - Pontos Turísticos: %d\n", c1_estado, c1_ponto, c2_estado, c2_ponto);
            printf("Estado: %s vence!\n", c2_estado);
        } else {
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Número de Pontos Turísticos...\n");
            printf("Estado: %s - Pontos Turísticos: %d X Estado: %s - Pontos Turísticos: %d\n", c1_estado, c1_ponto, c2_estado, c2_ponto);
            printf("Partida empatada!\n");
        }
        break;

    case 5:
        if (c1_inv_densidade > c2_inv_densidade){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Densidade Demográfica...\n");
            printf("Estado: %s - Área/hab: %.4f km²/hab X Estado: %s - Área/hab: %.4f km²/hab\n", c1_estado, c1_inv_densidade, c2_estado, c2_inv_densidade);
            printf("Estado: %s vence!\n", c1_estado);
        } else if (c1_inv_densidade < c2_inv_densidade){
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Densidade Demográfica...\n");
            printf("Estado: %s - Área/hab: %.4f km²/hab² X Estado: %s - Área/hab: %.4f hab/km²\n", c1_estado, c1_inv_densidade, c2_estado, c2_inv_densidade);
            printf("Estado: %s vence!\n", c2_estado);
        } else {
            printf("*** Estado: %s X Estado: %s ***\n", c1_estado, c2_estado);
            printf("Comparando Densidade Demográfica...\n");
            printf("Estado: %s - Área/hab: %.4f hab/km² X Estado: %s - Área/hab: %.4f hab/km²\n", c1_estado, c1_inv_densidade, c2_estado, c2_inv_densidade);
            printf("Partida empatada!\n");
        }
        break;
    
    default:
        printf("Opção inválida!\n");
        break;
    }
    
    return 0;
}
