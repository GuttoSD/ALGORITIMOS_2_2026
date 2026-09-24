#include <stdio.h>

float calculadora (float valor1, float valor2, char operacao)
{
    float resultado;

    printf("Digite os dois valores: \n");
    scanf("%f %f", &valor1, &valor2);

    printf("Digite a operação (+, -, / ou *): \n");
    scanf(" %c", &operacao);

    if (operacao == '+')
    {
        resultado = valor1 + valor2;
    }
    else if (operacao == '-')
    {
        resultado = valor1 - valor2;
    }
    else if (operacao == '/')
    {
        resultado = valor1 / valor2;
    }
    else if (operacao == '*')
    {
        resultado = valor1 * valor2;
    }
    else
    {
        printf("Operação inválida.\n");
        return 0;
    }

    printf("Resultado: %.2f\n", resultado);

    return resultado;
}

int main(void)
{
    float valor1, valor2;
    char operacao;

    calculadora(valor1, valor2, operacao);

    return(0);
}
