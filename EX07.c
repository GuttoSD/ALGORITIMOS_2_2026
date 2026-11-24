#include <stdio.h>
#include <stdlib.h>

int *criarVetor(int quantidade) {
    int *vetor;
    int i;
    if (quantidade <= 0) return NULL;
    vetor = malloc((size_t)quantidade * sizeof(int));
    if (vetor == NULL) return NULL;
    for (i = 0; i < quantidade; i++) vetor[i] = i;
    return vetor;
}

int main(void) {
    int quantidade, i;
    int *vetor;
    printf("Quantidade de elementos: ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) return 1;
    vetor = criarVetor(quantidade);
    if (vetor == NULL) { printf("Falha na alocacao.\n"); return 1; }
    for (i = 0; i < quantidade; i++) printf("%d ", vetor[i]);
    printf("\n");
    free(vetor);
    return 0;
}
