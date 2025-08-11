//Exercício do módudo de introdução a programação com C.
//Programa que lê 3 notas de um aluno e calcula a média.
//Treinando conversão de tipos e operações aritméticas.

#include <stdio.h>

int main(){

int nota1, nota2, nota3;
float media;

printf("*** Programa de Cálculo de Média ***\n");
printf("Digite a primeira nota: \n");
scanf("%d", &nota1);

printf("Digite a segunda nota: \n");
scanf("%d", &nota2);

printf("Digite a terceira nota: \n");
scanf("%d", &nota3);

media = (float)(nota1 + nota2 + nota3) / 3;

printf("A média é: %.1f \n", media);

}