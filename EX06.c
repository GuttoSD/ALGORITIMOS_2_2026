#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int procurarValor(int **matriz, int linhas, int colunas, int valor) {
    int i, j;
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            if (matriz[i][j] == valor) return 1;
    return 0;
}

int main(void) {
    int **matriz;
    int linhas, colunas, i, j, valor;

    printf("Quantidade de linhas: ");
    if (scanf("%d", &linhas) != 1 || linhas <= 0) return 1;
    printf("Quantidade de colunas: ");
    if (scanf("%d", &colunas) != 1 || colunas <= 0) return 1;

    matriz = malloc((size_t)linhas * sizeof(int *));
    if (matriz == NULL) return 1;
    for (i = 0; i < linhas; i++) {
        matriz[i] = malloc((size_t)colunas * sizeof(int));
        if (matriz[i] == NULL) {
            while (i > 0) free(matriz[--i]);
            free(matriz);
            return 1;
        }
    }
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            if (scanf("%d", &matriz[i][j]) != 1) {
                for (i = 0; i < linhas; i++) free(matriz[i]);
                free(matriz);
                return 1;
            }

    printf("Valor para procurar: ");
    if (scanf("%d", &valor) != 1) {
        for (i = 0; i < linhas; i++) free(matriz[i]);
        free(matriz);
        return 1;
    }
    printf(procurarValor(matriz, linhas, colunas, valor) ? "Valor encontrado\n" : "Valor nao encontrado\n");
    for (i = 0; i < linhas; i++) free(matriz[i]);
    free(matriz);
    return 0;
}
