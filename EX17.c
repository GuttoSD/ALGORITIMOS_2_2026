#include <stdlib.h>

int *soma_colunas(int **A, int N) {
    int *B;
    int i, j;
    if (A == NULL || N <= 0) return NULL;
    B = malloc((size_t)N * sizeof(int));
    if (B == NULL) return NULL;
    for (j = 0; j < N; j++) {
        B[j] = 0;
        for (i = 0; i < N; i++) B[j] += A[i][j];
    }
    return B;
}
