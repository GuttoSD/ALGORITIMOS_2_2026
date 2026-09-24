#include <stdio.h>

int main() {
    int numero, i = 0;
    float soma = 0.0;

    printf("Digite os números positivos:\n(OBS. Digite um número negativo para parar) \n");

    while (1) {
        scanf("%d", &numero);
        if (numero < 0) break;
        soma += numero;
        i++;
    }

    if (i > 0) 
        printf("Média: %.2f\n", soma / i);
    else
        printf("Nenhum número positivo foi inserido.\n");

    return 0;
}
