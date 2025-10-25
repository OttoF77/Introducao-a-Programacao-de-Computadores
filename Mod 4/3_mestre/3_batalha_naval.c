// Batalha Naval - Nível Mestre
// Programa que posiciona quatro navios em um tabuleiro 10x10 e implementa
// habilidades especiais com áreas de efeito (Cone, Cruz e Octaedro)

#include <stdio.h>

// Constantes do jogo
#define TAMANHO_TABULEIRO 10  // Tabuleiro 10x10
#define TAMANHO_NAVIO 3       // Cada navio ocupa 3 posições
#define TAMANHO_HABILIDADE 5  // Matrizes de habilidades 5x5
#define AGUA 0                // Valor que representa água
#define NAVIO 3               // Valor que representa parte do navio
#define HABILIDADE 5          // Valor que representa área afetada pela habilidade

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
// Parâmetro diagonal: 1 = diagonal crescente, -1 = diagonal decrescente, 0 = horizontal/vertical
int validar_limites(int linha, int coluna, int tamanho, int horizontal, int diagonal) {
    // Se for diagonal
    if (diagonal != 0) {
        // Diagonal crescente (linha e coluna aumentam juntas)
        if (diagonal == 1) {
            if (linha + tamanho > TAMANHO_TABULEIRO || coluna + tamanho > TAMANHO_TABULEIRO) {
                return 0; // Fora dos limites
            }
        }
        // Diagonal decrescente (linha aumenta, coluna diminui)
        else if (diagonal == -1) {
            if (linha + tamanho > TAMANHO_TABULEIRO || coluna - tamanho + 1 < 0) {
                return 0; // Fora dos limites
            }
        }
    }
    // Se for horizontal, verifica se cabe na linha
    else if (horizontal) {
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
// Parâmetro diagonal: 1 = diagonal crescente, -1 = diagonal decrescente, 0 = horizontal/vertical
int verificar_sobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                           int linha, int coluna, int tamanho, int horizontal, int diagonal) {
    // Se for diagonal
    if (diagonal != 0) {
        for (int i = 0; i < tamanho; i++) {
            int lin, col;
            if (diagonal == 1) {
                // Diagonal crescente: linha e coluna aumentam
                lin = linha + i;
                col = coluna + i;
            } else {
                // Diagonal decrescente: linha aumenta, coluna diminui
                lin = linha + i;
                col = coluna - i;
            }
            if (tabuleiro[lin][col] != AGUA) {
                return 1; // Há sobreposição
            }
        }
    }
    // Se for horizontal, verifica as posições na linha
    else if (horizontal) {
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
// Parâmetro diagonal: 1 = diagonal crescente, -1 = diagonal decrescente, 0 = horizontal/vertical
int posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int navio[TAMANHO_NAVIO], int linha, int coluna, int horizontal, int diagonal) {
    // Valida se o navio cabe no tabuleiro
    if (!validar_limites(linha, coluna, TAMANHO_NAVIO, horizontal, diagonal)) {
        printf("Erro: Navio fora dos limites do tabuleiro!\n");
        return 0;
    }
    
    // Verifica se há sobreposição com outro navio
    if (verificar_sobreposicao(tabuleiro, linha, coluna, TAMANHO_NAVIO, horizontal, diagonal)) {
        printf("Erro: Navios sobrepostos!\n");
        return 0;
    }
    
    // Posiciona o navio copiando o valor de cada posição do vetor para a matriz
    if (diagonal != 0) {
        // Posicionamento diagonal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (diagonal == 1) {
                // Diagonal crescente: linha e coluna aumentam simultaneamente
                tabuleiro[linha + i][coluna + i] = navio[i];
            } else {
                // Diagonal decrescente: linha aumenta, coluna diminui
                tabuleiro[linha + i][coluna - i] = navio[i];
            }
        }
    } else if (horizontal) {
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

// Função para criar a matriz de habilidade CONE
// Cone: ponto no topo, expandindo para baixo (formato triangular)
void criar_habilidade_cone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa toda a matriz com 0
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }
    
    // Cria o formato de cone usando condicionais
    // Centro do cone (linha 0, coluna central)
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A área afetada expande conforme desce
            // Linha 0: apenas o centro
            // Linha 1: centro ± 1
            // Linha 2: centro ± 2, etc.
            if (j >= centro - i && j <= centro + i) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para criar a matriz de habilidade CRUZ
// Cruz: linhas horizontal e vertical cruzando no centro
void criar_habilidade_cruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa toda a matriz com 0
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }
    
    // Cria o formato de cruz usando condicionais
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Linha horizontal (centro da matriz) ou vertical (coluna central)
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para criar a matriz de habilidade OCTAEDRO
// Octaedro: formato de losango (diamante) com centro no meio
void criar_habilidade_octaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa toda a matriz com 0
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }
    
    // Cria o formato de octaedro/losango usando condicionais
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância de Manhattan do centro
            int dist_vertical = (i > centro) ? (i - centro) : (centro - i);
            int dist_horizontal = (j > centro) ? (j - centro) : (centro - j);
            
            // Forma losango: soma das distâncias <= raio
            if (dist_vertical + dist_horizontal <= centro) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Função para sobrepor uma habilidade ao tabuleiro
// origem_linha, origem_coluna: ponto central da habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int origem_linha, int origem_coluna) {
    // Centro da matriz de habilidade
    int centro_hab = TAMANHO_HABILIDADE / 2;
    
    // Percorre a matriz de habilidade
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Calcula a posição correspondente no tabuleiro
            int tab_linha = origem_linha - centro_hab + i;
            int tab_coluna = origem_coluna - centro_hab + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                
                // Se a posição é afetada pela habilidade (valor 1)
                if (habilidade[i][j] == 1) {
                    // Marca no tabuleiro (não sobrescreve navios)
                    if (tabuleiro[tab_linha][tab_coluna] == AGUA) {
                        tabuleiro[tab_linha][tab_coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
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

// Função para exibir uma matriz de habilidade isoladamente
void exibir_habilidade(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], const char* nome) {
    printf("\n=== HABILIDADE: %s ===\n\n", nome);
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("  ");
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                printf(" 3 ");  // Representa área afetada
            } else {
                printf(" 0 ");  // Representa área não afetada
            }
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
    int navio3[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Navio diagonal crescente
    int navio4[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Navio diagonal decrescente
    
    // Inicializa o tabuleiro com água (0)
    inicializar_tabuleiro(tabuleiro);
    
    printf("=== BATALHA NAVAL - NIVEL MESTRE ===\n");
    printf("Posicionando navios no tabuleiro...\n\n");
    
    // ===== NAVIO 1: HORIZONTAL =====
    // Posiciona na linha 2, começando na coluna 3
    int navio1_linha = 2;
    int navio1_coluna = 3;
    int navio1_horizontal = 1;  // 1 = horizontal
    int navio1_diagonal = 0;    // 0 = não é diagonal
    
    printf("Navio 1 (Horizontal):\n");
    printf("  Posicao inicial: Linha %d, Coluna %d\n", navio1_linha, navio1_coluna);
    printf("  Tamanho: %d posicoes\n", TAMANHO_NAVIO);
    
    if (posicionar_navio(tabuleiro, navio1, navio1_linha, navio1_coluna, 
                         navio1_horizontal, navio1_diagonal)) {
        printf("  Status: Posicionado com sucesso!\n\n");
    } else {
        printf("  Status: Falha ao posicionar!\n\n");
        return 1;
    }
    
    // ===== NAVIO 2: VERTICAL =====
    // Posiciona na linha 5, coluna 0
    int navio2_linha = 5;
    int navio2_coluna = 0;
    int navio2_horizontal = 0;  // 0 = vertical
    int navio2_diagonal = 0;    // 0 = não é diagonal
    
    printf("Navio 2 (Vertical):\n");
    printf("  Posicao inicial: Linha %d, Coluna %d\n", navio2_linha, navio2_coluna);
    printf("  Tamanho: %d posicoes\n", TAMANHO_NAVIO);
    
    if (posicionar_navio(tabuleiro, navio2, navio2_linha, navio2_coluna, 
                         navio2_horizontal, navio2_diagonal)) {
        printf("  Status: Posicionado com sucesso!\n\n");
    } else {
        printf("  Status: Falha ao posicionar!\n\n");
        return 1;
    }
    
    // ===== NAVIO 3: DIAGONAL CRESCENTE =====
    // Posiciona na linha 0, coluna 0 (diagonal principal)
    // Linha e coluna aumentam simultaneamente: [0,0], [1,1], [2,2]
    int navio3_linha = 0;
    int navio3_coluna = 0;
    int navio3_horizontal = 0;  // não usado para diagonal
    int navio3_diagonal = 1;    // 1 = diagonal crescente
    
    printf("Navio 3 (Diagonal Crescente):\n");
    printf("  Posicao inicial: Linha %d, Coluna %d\n", navio3_linha, navio3_coluna);
    printf("  Tamanho: %d posicoes (diagonal: linha e coluna aumentam)\n", TAMANHO_NAVIO);
    
    if (posicionar_navio(tabuleiro, navio3, navio3_linha, navio3_coluna, 
                         navio3_horizontal, navio3_diagonal)) {
        printf("  Status: Posicionado com sucesso!\n\n");
    } else {
        printf("  Status: Falha ao posicionar!\n\n");
        return 1;
    }
    
    // ===== NAVIO 4: DIAGONAL DECRESCENTE =====
    // Posiciona na linha 7, coluna 9 (diagonal decrescente)
    // Linha aumenta, coluna diminui: [7,9], [8,8], [9,7]
    int navio4_linha = 7;
    int navio4_coluna = 9;
    int navio4_horizontal = 0;  // não usado para diagonal
    int navio4_diagonal = -1;   // -1 = diagonal decrescente
    
    printf("Navio 4 (Diagonal Decrescente):\n");
    printf("  Posicao inicial: Linha %d, Coluna %d\n", navio4_linha, navio4_coluna);
    printf("  Tamanho: %d posicoes (diagonal: linha aumenta, coluna diminui)\n", TAMANHO_NAVIO);
    
    if (posicionar_navio(tabuleiro, navio4, navio4_linha, navio4_coluna, 
                         navio4_horizontal, navio4_diagonal)) {
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
    printf("Resumo dos navios:\n");
    printf("  Navio 1: Horizontal (Linha %d, Colunas %d-%d)\n", 
           navio1_linha, navio1_coluna, navio1_coluna + TAMANHO_NAVIO - 1);
    printf("  Navio 2: Vertical (Linhas %d-%d, Coluna %d)\n", 
           navio2_linha, navio2_linha + TAMANHO_NAVIO - 1, navio2_coluna);
    printf("  Navio 3: Diagonal Crescente (Posicoes: [%d,%d], [%d,%d], [%d,%d])\n",
           navio3_linha, navio3_coluna, navio3_linha+1, navio3_coluna+1, 
           navio3_linha+2, navio3_coluna+2);
    printf("  Navio 4: Diagonal Decrescente (Posicoes: [%d,%d], [%d,%d], [%d,%d])\n\n",
           navio4_linha, navio4_coluna, navio4_linha+1, navio4_coluna-1, 
           navio4_linha+2, navio4_coluna-2);
    
    // ========================================
    // PARTE 2: HABILIDADES ESPECIAIS
    // ========================================
    
    printf("\n========================================\n");
    printf("PARTE 2: HABILIDADES ESPECIAIS\n");
    printf("========================================\n");
    
    // Declaração das matrizes de habilidades
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    // Cria as matrizes de habilidades usando condicionais e loops aninhados
    criar_habilidade_cone(habilidade_cone);
    criar_habilidade_cruz(habilidade_cruz);
    criar_habilidade_octaedro(habilidade_octaedro);
    
    // Exibe as habilidades isoladamente
    printf("\nVisualizacao das areas de efeito das habilidades:\n");
    exibir_habilidade(habilidade_cone, "CONE");
    exibir_habilidade(habilidade_cruz, "CRUZ");
    exibir_habilidade(habilidade_octaedro, "OCTAEDRO");
    
    // ===== APLICAR HABILIDADE CONE =====
    printf("\n--- Aplicando habilidade CONE no tabuleiro ---\n");
    int cone_origem_linha = 4;
    int cone_origem_coluna = 7;
    printf("Ponto de origem: [%d, %d]\n", cone_origem_linha, cone_origem_coluna);
    
    // Cria cópia do tabuleiro para mostrar efeito do Cone
    int tabuleiro_cone[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro_cone[i][j] = tabuleiro[i][j];
        }
    }
    aplicar_habilidade(tabuleiro_cone, habilidade_cone, cone_origem_linha, cone_origem_coluna);
    exibir_tabuleiro(tabuleiro_cone);
    
    // ===== APLICAR HABILIDADE CRUZ =====
    printf("\n--- Aplicando habilidade CRUZ no tabuleiro ---\n");
    int cruz_origem_linha = 5;
    int cruz_origem_coluna = 5;
    printf("Ponto de origem: [%d, %d]\n", cruz_origem_linha, cruz_origem_coluna);
    
    // Cria cópia do tabuleiro para mostrar efeito da Cruz
    int tabuleiro_cruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro_cruz[i][j] = tabuleiro[i][j];
        }
    }
    aplicar_habilidade(tabuleiro_cruz, habilidade_cruz, cruz_origem_linha, cruz_origem_coluna);
    exibir_tabuleiro(tabuleiro_cruz);
    
    // ===== APLICAR HABILIDADE OCTAEDRO =====
    printf("\n--- Aplicando habilidade OCTAEDRO no tabuleiro ---\n");
    int octaedro_origem_linha = 7;
    int octaedro_origem_coluna = 2;
    printf("Ponto de origem: [%d, %d]\n", octaedro_origem_linha, octaedro_origem_coluna);
    
    // Cria cópia do tabuleiro para mostrar efeito do Octaedro
    int tabuleiro_octaedro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro_octaedro[i][j] = tabuleiro[i][j];
        }
    }
    aplicar_habilidade(tabuleiro_octaedro, habilidade_octaedro, octaedro_origem_linha, octaedro_origem_coluna);
    exibir_tabuleiro(tabuleiro_octaedro);
    
    printf("\nLegenda final:\n");
    printf("  0 = Agua\n");
    printf("  3 = Navio\n");
    printf("  5 = Area afetada pela habilidade\n\n");
    
    return 0;
}
