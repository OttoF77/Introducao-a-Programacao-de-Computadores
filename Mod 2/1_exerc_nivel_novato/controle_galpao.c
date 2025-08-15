#include <stdio.h>

int main(){
    float temperatura, umidade;
    unsigned int estoque, estoque_minimo = 1000;

    printf("Informe a temperatura do galpão: \n");
    scanf("%f", &temperatura);

    printf("Informe a umidade do galpão: \n");
    scanf("%f", &umidade);

    printf("Informe o estoque do galpão: \n");
    scanf("%u", &estoque);

    if(temperatura >30){
        printf("Temperatura acima do normal. \n");
    } else {
        printf("Temperatura dentro do normal. \n");
    }

    if(umidade > 50){
        printf("Umidade acima do normal. \n");
    } else {
        printf("Umidade dentro do normal. \n");
    }

    if(estoque < estoque_minimo){
        printf("Estoque abaixo do mínimo. \n");
    } else {
        printf("Estoque dentro do normal. \n");
    }
    
    return 0;

    
}