#include <stdio.h>
#include <stdlib.h>

int *criaVetorValor(int n, int valor) {
    int *v;
    int i;
    if (n <= 0) return NULL;
    v = malloc((size_t)n * sizeof(int));
    if (v == NULL) return NULL;
    for (i = 0; i < n; i++) v[i] = valor;
    return v;
}

int main(void) {
    int n, valor, i;
    int *vetor;
    printf("Tamanho: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    printf("Valor para preencher: ");
    if (scanf("%d", &valor) != 1) return 1;
    vetor = criaVetorValor(n, valor);
    if (vetor == NULL) { printf("Nao foi possivel alocar.\n"); return 1; }
    for (i = 0; i < n; i++) printf("%d ", vetor[i]);
    printf("\n");
    free(vetor);
    return 0;
}
