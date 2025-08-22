// ### Jogo de Adivinhação ###
// Programa para o usuário tentar adivinhar o número escolhido pelo computador.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    //Gerar número aleatório
    srand(time(0));
    numeroComputador = rand() % 100 + 1; // número entre 1 e 100

    //Início do jogo
    printf("Bem-vindo ao jogo Maior, Menor ou Igual!\n");
    printf("Você deve escolher um número e o tipo de comparação.\n");
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("I. Igual\n");

    printf("Escolha a comparação (M/N/I): ");
    scanf(" %c", &tipoComparacao);

    printf("Digite um número entre 1 e 100: ");
    scanf("%d", &numeroJogador);

    switch (tipoComparacao)
    {
    case 'M':
    case 'm':
        printf("Você escolheu a opção 'Maior'.\n");
        resultado = numeroJogador > numeroComputador ? 1 : 0;
        break;
    case 'N':
    case 'n':
        printf("Você escolheu a opção 'Menor'.\n");
        resultado = numeroJogador < numeroComputador ? 1 : 0;
        break;
    case 'I':
    case 'i':
        printf("Você escolheu a opção 'Igual'.\n");
        resultado = numeroJogador == numeroComputador ? 1 : 0;
        break;
    
    default:
        printf("Opção inválida. Por favor, escolha M, N ou I.\n");
        break;
    }

    printf("O número escolhido pelo computador é: %d e o do jogador é: %d\n", numeroComputador, numeroJogador);

    //Exibir o resultado
    if(resultado == 1){
        printf("Parabéns! Você acertou!\n");
    }else{
        printf("Que pena! Você errou!\n");
    }

    return 0;
}
