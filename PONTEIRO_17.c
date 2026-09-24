#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar(int *vetor, int tamanho)
{
    int *i, *j;

    for (i = vetor; i < vetor + tamanho - 1; i++)
    {
        for (j = vetor; j < vetor + tamanho - 1 - (i - vetor); j++)
        {
            if (*j > *(j + 1))
                swap(j, j + 1);
        }
    }
}

int main()
{
    int vetor[] = {5, 2, 8, 1, 3};
    int tamanho = 5;
    int i;

    ordenar(vetor, tamanho);

    printf("Vetor ordenado: ");

    for (i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);

    printf("\n");

    return 0;
}
