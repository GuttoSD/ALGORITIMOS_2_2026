#include <stdio.h>
#include <stdlib.h>

int *criaVetor(int n) {
    int *vetor;
    if (n <= 0) return NULL;
    vetor = malloc((size_t)n * sizeof(int));
    return vetor;
}

int main(void) {
    int n, i;
    int *vetor;
    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &n) != 1) return 1;
    vetor = criaVetor(n);
    if (vetor == NULL) { printf("Valor invalido ou falha na alocacao.\n"); return 1; }
    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        if (scanf("%d", &vetor[i]) != 1) { free(vetor); return 1; }
    }
    printf("Vetor digitado: ");
    for (i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");
    free(vetor);
    return 0;
}
