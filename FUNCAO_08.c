#include <stdio.h>

int main(void)
{
    int n;
    int soma = 0;

    printf("Digite um número inteiro positivo: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        soma += i;
    }

    printf("O somatório de 1 até %d é: %d\n", n, soma);

    return(0);
}
