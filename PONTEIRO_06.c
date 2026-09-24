#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet[5];
    int i;

    printf("Digite 5 valores inteiros:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &vet[i]);
    }

    printf("Enderecos com valores pares:\n");
    for (i = 0; i < 5; i++) {
        if (vet[i] % 2 == 0) {
            printf("vet[%d] = %d  Endereco: %p\n", i, vet[i], (void*)&vet[i]);
        }
    }

    return 0;
}
