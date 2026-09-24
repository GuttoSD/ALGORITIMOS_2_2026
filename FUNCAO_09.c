#include <stdio.h>

int fatorial (int n)
{
    int resultado = 1;

    for (int i = 1; i <= n; i++)
    {
        resultado *= i;
    }

    return resultado;
}

float calcularS (int n)
{
    float soma = 1.0;

    for (int i = 1; i <= n; i++)
    {
        soma += 1.0 / fatorial(i);
    }

    return soma;
}

int main(void)
{
    int n;
    float resultado;

    printf("Digite um valor inteiro positivo: \n");
    scanf("%d", &n);

    resultado = calcularS(n);

    printf("O valor de S é: %.2f\n", resultado);

    return(0);
}
