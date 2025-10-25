#include <stdio.h>

int main(void) {
    // Torre — usa for: 5 casas para a direita
    printf("Torre\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }

    // Bispo — usa while: 5 casas na diagonal para cima e à direita
    printf("Bispo\n");
    int j = 0; // contador para o while
    while (j < 5) {
        printf("Cima Direita\n");
        j++;
    }

    // Rainha — usa do-while: 8 casas para a esquerda
    printf("Rainha\n");
    int k = 0; // contador para o do-while
    do {
        printf("Esquerda\n");
        k++;
    } while (k < 8);

    // Cavalo — usa loops aninhados: movimento em "L"
    // Move 2 casas para baixo e depois 1 casa para esquerda
    printf("\nCavalo\n");
    
    // Definição dos movimentos do Cavalo (2 baixo + 1 esquerda)
    int mov_vertical = 2;   // casas para baixo
    int mov_horizontal = 1; // casa para esquerda
    
    // Loop externo (for): controla o movimento vertical (2 casas para baixo)
    for (int i = 0; i < mov_vertical; i++) {
        printf("Baixo\n");
    }
    
    // Loop interno (while): controla o movimento horizontal (1 casa para esquerda)
    // Este loop executa após completar o movimento vertical, formando o "L"
    int m = 0;
    while (m < mov_horizontal) {
        printf("Esquerda\n");
        m++;
    }

    return 0;
}

