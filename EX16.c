#include <stdlib.h>

int *produto_matriz_vetor(int **A, const int *B, int N) {
    int *C;
    int i, j;
    if (A == NULL || B == NULL || N <= 0) return NULL;
    C = malloc((size_t)N * sizeof(int));
    if (C == NULL) return NULL;
    for (i = 0; i < N; i++) {
        C[i] = 0;
        for (j = 0; j < N; j++) C[i] += A[i][j] * B[j];
    }
    return C;
}
