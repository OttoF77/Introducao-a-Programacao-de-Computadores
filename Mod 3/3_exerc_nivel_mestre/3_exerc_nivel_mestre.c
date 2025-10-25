// Simulação de movimentos de peças de xadrez (nível mestre)
// Requisitos atendidos:
// - Torre, Bispo, Rainha: implementadas com recursividade
// - Bispo: recursividade + loops aninhados (externo vertical, interno horizontal)
// - Cavalo: loops complexos com múltiplas variáveis e continue/break (2 cima, 1 direita)

#include <stdio.h>

// Função recursiva para mover a Torre
// Move horizontalmente para a direita
void mover_torre(int casas_restantes) {
    // Caso base: quando não há mais casas para mover
    if (casas_restantes == 0) {
        return;
    }
    
    // Imprime a direção do movimento
    printf("Direita\n");
    
    // Chamada recursiva: reduz o número de casas restantes
    mover_torre(casas_restantes - 1);
}

// Função recursiva para mover o Bispo
// Move na diagonal usando loops aninhados (vertical externo, horizontal interno)
void mover_bispo(int casas_restantes) {
    // Caso base: quando não há mais casas para mover
    if (casas_restantes == 0) {
        return;
    }
    
    // Loop externo: movimento vertical (1 casa para cima)
    for (int v = 0; v < 1; v++) {
        // Loop interno: movimento horizontal (1 casa para direita)
        for (int h = 0; h < 1; h++) {
            printf("Cima\n");
            printf("Direita\n");
        }
    }
    
    // Chamada recursiva: reduz o número de casas restantes
    mover_bispo(casas_restantes - 1);
}

// Função recursiva para mover a Rainha
// Move horizontalmente para a esquerda
void mover_rainha(int casas_restantes) {
    // Caso base: quando não há mais casas para mover
    if (casas_restantes == 0) {
        return;
    }
    
    // Imprime a direção do movimento
    printf("Esquerda\n");
    
    // Chamada recursiva: reduz o número de casas restantes
    mover_rainha(casas_restantes - 1);
}

int main(void) {
    // Torre — movimento recursivo: 5 casas para a direita
    printf("Torre\n");
    mover_torre(5);
    
    // Bispo — movimento recursivo com loops aninhados: 5 casas na diagonal (cima e direita)
    printf("\nBispo\n");
    mover_bispo(5);
    
    // Rainha — movimento recursivo: 8 casas para a esquerda
    printf("\nRainha\n");
    mover_rainha(8);
    
    // Cavalo — loops complexos: movimento em "L" (2 cima, 1 direita)
    // Usa múltiplas variáveis e controle de fluxo com continue/break
    printf("\nCavalo\n");
    
    // Definição dos movimentos do Cavalo em "L": 2 cima + 1 direita
    int mov_vertical = 2;   // casas para cima
    int mov_horizontal = 1; // casa para direita
    int total_movimentos = mov_vertical + mov_horizontal; // total de casas no movimento em L
    int movimento_atual = 0; // contador de movimentos realizados
    
    // Loop externo: controla todos os movimentos do Cavalo
    for (int i = 0; i < total_movimentos; i++) {
        movimento_atual++;
        
        // Condição complexa: verifica se ainda está na fase vertical (2 primeiros movimentos)
        if (movimento_atual <= mov_vertical) {
            printf("Cima\n");
            
            // Se completou o movimento vertical, continua para o próximo
            if (movimento_atual == mov_vertical) {
                continue;
            }
        } else {
            // Fase horizontal: movimento para a direita
            printf("Direita\n");
            
            // Break: encerra após completar o movimento horizontal
            if (movimento_atual >= total_movimentos) {
                break;
            }
        }
    }
    
    return 0;
}

