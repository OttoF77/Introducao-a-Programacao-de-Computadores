#include <stdio.h>

int main(){
    //Declaração de variaveis
    char mov_acima[10] = "cima";
    char mov_abaixo[10] = "baixo"; 
    char mov_esquerda[10] = "esquerda";
    char mov_direita[10] = "direita";
    int num_mov;
    int opcao;
    int status = 1;
    char menu[300] = "Digite a peça que deseja movimentar:\n 1 - Torre\n 2 - Bispo\n 3 - Rainha\n 4 - Cavalo\n 5 - Sair do jogo\n";
    char mov_vertical[10], mov_horizontal[10];

    //Exibição do menu e leitura da opção
    while(status == 1){
        printf("%s", menu);
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Você escolheu a torre\n");
                printf("Movimento da torre:\n");
                num_mov = 5;
                for(int i = 1; i <= num_mov; i++){
                    printf("Passo %d: 1 casa para direita\n", i);
                }
                break;
                
            case 2:
                printf("Você escolheu o bispo\n");
                printf("Movimento diagonal:\n");
                num_mov = 5;
                for(int i = 1; i <= num_mov; i++){
                    printf("Passo %d: movimento na diagonal 1 casa para cima e 1 casa para direita\n", i);
                }
                break;

            case 3:
                printf("Você escolheu a rainha\n");
                printf("Movimento diagonal:\n");
                num_mov = 8;
                for(int i = 1; i <= num_mov; i++){
                    printf("Passo %d: 1 casa para esquerda\n", i);
                }
                break;
            case 4:
                
                printf("Você escolheu o cavalo\n");
                printf("Movimento do cavalo:\n");
                num_mov = 3;
                for(int i = 1; i <= num_mov; i++){
                    for(int j = 1; j <= 1; j++){
                        if(i <= 2)
                            printf("Passo %d: 1 casa para baixo\n", i);
                        else
                            printf("Passo %d: 1 casa para esquerda\n", i);
                    }
                }
                break;
                                
            case 5:
                printf("Saindo do jogo...\n");
                status = 0;
                break;

            default:
                printf("Opção inválida, tente novamente.\n");
        }
    }

    return 0;
}

