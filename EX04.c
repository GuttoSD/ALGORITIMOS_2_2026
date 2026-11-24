#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    int tamanho, i;
    int *vetor;

    printf("Tamanho do vetor: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0 || (size_t)tamanho > SIZE_MAX / sizeof(int)) {
        printf("Tamanho invalido.\n");
        return 1;
    }
    vetor = malloc((size_t)tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Falha na alocacao.\n");
        return 1;
    }
    for (i = 0; i < tamanho; i++) {
        printf("Valor %d: ", i + 1);
        if (scanf("%d", &vetor[i]) != 1) { free(vetor); return 1; }
    }
    printf("Vetor lido: ");
    for (i = 0; i < tamanho; i++) printf("%d ", vetor[i]);
    printf("\n");
    free(vetor);
    return 0;
}
