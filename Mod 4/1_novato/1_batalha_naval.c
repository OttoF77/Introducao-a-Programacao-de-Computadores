// Batalha Naval - Nível Novato
// Programa que posiciona dois navios em um tabuleiro 10x10
// Um navio horizontal e um navio vertical, cada um com 3 posições

#include <stdio.h>

// Constantes do jogo
#define TAMANHO_TABULEIRO 10  // Tabuleiro 10x10
#define TAMANHO_NAVIO 3       // Cada navio ocupa 3 posições
#define AGUA 0                // Valor que representa água
#define NAVIO 3               // Valor que representa parte do navio

// Função para inicializar o tabuleiro com água (0)
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Percorre todas as linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Percorre todas as colunas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Inicializa com água
        }
    }
}

// Função para validar se a posição está dentro dos limites do tabuleiro
int validar_limites(int linha, int coluna, int tamanho, int horizontal) {
    // Se for horizontal, verifica se cabe na linha
    if (horizontal) {
        if (coluna + tamanho > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
    } else {
        // Se for vertical, verifica se cabe na coluna
        if (linha + tamanho > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
    }
    return 1; // Dentro dos limites
}

// Função para verificar se há sobreposição de navios
int verificar_sobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                           int linha, int coluna, int tamanho, int horizontal) {
    // Se for horizontal, verifica as posições na linha
    if (horizontal) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) {
                return 1; // Há sobreposição
            }
        }
    } else {
        // Se for vertical, verifica as posições na coluna
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) {
                return 1; // Há sobreposição
            }
        }
    }
    return 0; // Não há sobreposição
}

// Função para posicionar um navio no tabuleiro
int posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int navio[TAMANHO_NAVIO], int linha, int coluna, int horizontal) {
    // Valida se o navio cabe no tabuleiro
    if (!validar_limites(linha, coluna, TAMANHO_NAVIO, horizontal)) {
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
        return 0;
    }
    
    // Verifica se há sobreposição com outro navio
    if (verificar_sobreposicao(tabuleiro, linha, coluna, TAMANHO_NAVIO, horizontal)) {
        printf("Erro: Navios sobrepostos!\n");
        return 0;
    }
    
    // Posiciona o navio copiando o valor de cada posição do vetor para a matriz
    if (horizontal) {
        // Posicionamento horizontal: mesma linha, colunas consecutivas
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = navio[i];
        }
    } else {
        // Posicionamento vertical: mesma coluna, linhas consecutivas
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = navio[i];
        }
    }
    
    return 1; // Sucesso
}

// Função para exibir o tabuleiro no console
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    
    // Exibe os números das colunas (0-9)
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    
    // Exibe uma linha separadora
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("---");
    }
    printf("\n");
    
    // Percorre todas as linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Exibe o número da linha
        printf("%d |", i);
        
        // Percorre todas as colunas da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    // Declaração da matriz do tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Declaração dos vetores que representam os navios
    // Cada posição do navio tem valor 3
    int navio1[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Navio horizontal
    int navio2[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Navio vertical
    
    // Inicializa o tabuleiro com água (0)
    inicializar_tabuleiro(tabuleiro);
    
    printf("=== BATALHA NAVAL - NIVEL NOVATO ===\n");
    printf("Posicionando navios no tabuleiro...\n\n");
    
    // Coordenadas e orientação do primeiro navio (HORIZONTAL)
    // Posiciona na linha 2, começando na coluna 3
    int navio1_linha = 2;
    int navio1_coluna = 3;
    int navio1_horizontal = 1; // 1 = horizontal, 0 = vertical
    
    printf("Navio 1 (Horizontal):\n");
    printf("  Posicao inicial: Linha %d, Coluna %d\n", navio1_linha, navio1_coluna);
    printf("  Tamanho: %d posicoes\n", TAMANHO_NAVIO);
    
    if (posicionar_navio(tabuleiro, navio1, navio1_linha, navio1_coluna, navio1_horizontal)) {
        printf("  Status: Posicionado com sucesso!\n\n");
    } else {
        printf("  Status: Falha ao posicionar!\n\n");
        return 1;
    }
    
    // Coordenadas e orientação do segundo navio (VERTICAL)
    // Posiciona na linha 5, coluna 7
    int navio2_linha = 5;
    int navio2_coluna = 7;
    int navio2_horizontal = 0; // 1 = horizontal, 0 = vertical
    
    printf("Navio 2 (Vertical):\n");
    printf("  Posicao inicial: Linha %d, Coluna %d\n", navio2_linha, navio2_coluna);
    printf("  Tamanho: %d posicoes\n", TAMANHO_NAVIO);
    
    if (posicionar_navio(tabuleiro, navio2, navio2_linha, navio2_coluna, navio2_horizontal)) {
        printf("  Status: Posicionado com sucesso!\n\n");
    } else {
        printf("  Status: Falha ao posicionar!\n\n");
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibir_tabuleiro(tabuleiro);
    
    printf("Legenda:\n");
    printf("  0 = Agua\n");
    printf("  3 = Navio\n\n");
    
    return 0;
}
