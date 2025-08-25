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
    int escolhido1, escolhido2, escolhido3, escolhido4, escolhido5, contador = 0;
    float c1_resultado = 0;
    float c2_resultado = 0;
    char menu[300] = "Escolha o atributo para comparar as cartas:\n"
                     "1 - População\n"
                     "2 - Área\n"
                     "3 - PIB\n"
                     "4 - Número de Pontos Turísticos\n"
                     "5 - Densidade Demográfica\n"
                     "6 - Sair do jogo\n";
    
    menu_loop:
    printf("%s", menu);

    scanf("%d", &opcao);
    
    switch (opcao)
    {
        case 1:
            if (escolhido1 == 0){
                c1_populacao > c2_populacao ? printf("Estado: %s vence!\n", c1_estado) : printf("Estado: %s vence!\n", c2_estado);
                c1_resultado += c1_populacao;
                c2_resultado += c2_populacao;
                escolhido1 = 1;
                contador++;
            } else {
                printf("Atributo já escolhido, escolha outro!\n");
            }
            
            if(contador == 2) {
                break;
            } else {
                goto menu_loop;
            }

        case 2:
            if (escolhido2 == 0){
                c1_area > c2_area ? printf("Estado: %s vence!\n", c1_estado) : printf("Estado: %s vence!\n", c2_estado);
                c1_resultado += c1_area;
                c2_resultado += c2_area;
                escolhido2 = 1;
                contador++;
            } else {
                printf("Atributo já escolhido, escolha outro!\n");
            }
            
            if(contador == 2) {
                break;
            } else {
                goto menu_loop;
            }
            
        case 3:
            if (escolhido3 == 0){
                c1_pib > c2_pib ? printf("Estado: %s vence!\n", c1_estado) : printf("Estado: %s vence!\n", c2_estado);
                c1_resultado += c1_pib;
                c2_resultado += c2_pib;
                escolhido3 = 1;
                contador++;
            } else {
                printf("Atributo já escolhido, escolha outro!\n");
            }
            
            if(contador == 2) {
                break;
            } else {
                goto menu_loop;
            }
            
        case 4:
            if(escolhido4 == 0){
                c1_ponto > c2_ponto ? printf("Estado: %s vence!\n", c1_estado) : printf("Estado: %s vence!\n", c2_estado);
                c1_resultado += c1_ponto;
                c2_resultado += c2_ponto;
                escolhido4 = 1;
                contador++;
            } else {
                printf("Atributo já escolhido, escolha outro!\n");
            }
            
            if(contador == 2) {
                break;
            } else {
                goto menu_loop;
            }

        case 5:
            if (escolhido5 == 0){
                c1_inv_densidade > c2_inv_densidade ? printf("Estado: %s vence!\n", c1_estado) : printf("Estado: %s vence!\n", c2_estado);
                c1_resultado += c1_inv_densidade;
                c2_resultado += c2_inv_densidade;
                escolhido5 = 1;
                contador++;
            } else {
                printf("Atributo já escolhido, escolha outro!\n");
            }
            if (contador == 2) {
                break;
            } else {
                goto menu_loop;
            }
            
        case 6:
            printf("Saindo do jogo...\n");
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
    }

    if(c1_resultado > c2_resultado){
        printf("O vencedor é o estado: %s com %.2f pontos!\n", c1_estado, c1_resultado);
    } else if (c2_resultado > c1_resultado){
        printf("O vencedor é o estado: %s com %.2f pontos!\n", c2_estado, c2_resultado);
    } else {
        printf("Empate! Ambos os estados têm %.2f pontos!\n", c1_resultado);
    }
    
    return 0;
}
