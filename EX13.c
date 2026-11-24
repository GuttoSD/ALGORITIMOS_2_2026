#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, j;
    int **matriz;
    printf("Digite N: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    matriz = malloc((size_t)n * sizeof(int *));
    if (matriz == NULL) return 1;
    for (i = 0; i < n; i++) {
        matriz[i] = malloc((size_t)n * sizeof(int));
        if (matriz[i] == NULL) {
            while (i > 0) free(matriz[--i]);
            free(matriz);
            return 1;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matriz[i][j] = (i == j) ? 0 : (j > i ? 1 : -1);
    printf("Matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%d ", matriz[i][j]);
        printf("\n");
    }
    for (i = 0; i < n; i++) free(matriz[i]);
    free(matriz);
    return 0;
}
