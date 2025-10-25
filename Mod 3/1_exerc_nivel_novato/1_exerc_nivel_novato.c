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

    return 0;
}

