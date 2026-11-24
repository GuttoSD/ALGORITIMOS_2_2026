#include <stdlib.h>

int **criarMatrizSecundaria(int n) {
    int i, j;
    int **matriz;
    if (n <= 0) return NULL;
    matriz = malloc((size_t)n * sizeof(int *));
    if (matriz == NULL) return NULL;
    for (i = 0; i < n; i++) {
        matriz[i] = malloc((size_t)n * sizeof(int));
        if (matriz[i] == NULL) {
            while (i > 0) free(matriz[--i]);
            free(matriz);
            return NULL;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) matriz[i][j] = (j == n - 1 - i) ? 1 : 0;
    return matriz;
}
