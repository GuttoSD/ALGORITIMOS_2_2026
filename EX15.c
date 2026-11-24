#include <stdio.h>
#include <stdlib.h>

int *multiplicaVetores(const int *A, const int *B, int N) {
    int *C;
    int i;
    if (N <= 0 || A == NULL || B == NULL) return NULL;
    C = malloc((size_t)N * sizeof(int));
    if (C == NULL) return NULL;
    for (i = 0; i < N; i++) C[i] = A[i] * B[i];
    return C;
}

int main(void) {
    int N, i;
    int *A, *B, *C;
    printf("N: ");
    if (scanf("%d", &N) != 1 || N <= 0) return 1;
    A = malloc((size_t)N * sizeof(int));
    B = malloc((size_t)N * sizeof(int));
    if (A == NULL || B == NULL) { free(A); free(B); return 1; }
    printf("Digite os elementos de A: ");
    for (i = 0; i < N; i++) if (scanf("%d", &A[i]) != 1) { free(A); free(B); return 1; }
    printf("Digite os elementos de B: ");
    for (i = 0; i < N; i++) if (scanf("%d", &B[i]) != 1) { free(A); free(B); return 1; }
    C = multiplicaVetores(A, B, N);
    if (C == NULL) { free(A); free(B); return 1; }
    printf("Vetor C: ");
    for (i = 0; i < N; i++) printf("%d ", C[i]);
    printf("\n");
    free(A); free(B); free(C);
    return 0;
}
