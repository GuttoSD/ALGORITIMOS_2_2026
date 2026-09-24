#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet[5];
    int *p = vet;
    int i;

    printf("Digite 5 valores inteiros:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", (p + i));   
    }

    printf("Dobro dos valores:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", 2 * (*(p + i)));  
    }

    return 0;
}
