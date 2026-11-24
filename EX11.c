#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int n) {
    int **m;
    int i, j;
    if (n <= 0) return NULL;
    m = malloc((size_t)n * sizeof(int *));
    if (m == NULL) return NULL;
    for (i = 0; i < n; i++) {
        m[i] = malloc((size_t)n * sizeof(int));
        if (m[i] == NULL) {
            while (i > 0) free(m[--i]);
            free(m);
            return NULL;
        }
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) m[i][j] = (i == j) ? 1 : 0;
    return m;
}

int main(void) {
    int n, i, j;
    int **mat;
    printf("Tamanho N: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    mat = criaMatriz(n);
    if (mat == NULL) { printf("Falha na alocacao.\n"); return 1; }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
    for (i = 0; i < n; i++) free(mat[i]);
    free(mat);
    return 0;
}
