#include <stdlib.h>

int **multiplica_matrizes(int **A, int linhasA, int colunasA,
                          int **B, int linhasB, int colunasB) {
    int **C;
    int i, j, k;
    if (A == NULL || B == NULL || linhasA <= 0 || colunasA <= 0 ||
        linhasB <= 0 || colunasB <= 0 || colunasA != linhasB) return NULL;

    C = malloc((size_t)linhasA * sizeof(int *));
    if (C == NULL) return NULL;
    for (i = 0; i < linhasA; i++) {
        C[i] = malloc((size_t)colunasB * sizeof(int));
        if (C[i] == NULL) {
            while (i > 0) free(C[--i]);
            free(C);
            return NULL;
        }
    }
    for (i = 0; i < linhasA; i++) {
        for (j = 0; j < colunasB; j++) {
            C[i][j] = 0;
            for (k = 0; k < colunasA; k++) C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}
