#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int n, i;
    int *vetor;

    do {
        printf("Digite N (positivo): ");
        if (scanf("%d", &n) != 1) return 1;
    } while (n <= 0);

    if ((size_t)n > SIZE_MAX / sizeof(int)) return 1;
    vetor = malloc((size_t)n * sizeof(int));
    if (vetor == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        do {
            printf("Valor da posicao %d (>= 2): ", i + 1);
            if (scanf("%d", &vetor[i]) != 1) { free(vetor); return 1; }
        } while (vetor[i] < 2);
    }
    printf("Vetor: ");
    for (i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");
    free(vetor);
    return 0;
}
