#include <stdio.h>

int numeroPerfeito (int n)
{
    int soma = 0;
    int i;

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }

    if (soma == n) 
    {
        printf("É um número perfeito \n");
    } else {
        printf("Não é um número perfeito \n");
    }
}

int main (void)
{
    int numero;

    printf("Digite o número selecionado: \n");
    scanf("%d", &numero);

    numeroPerfeito (numero);

    return (0);
}
