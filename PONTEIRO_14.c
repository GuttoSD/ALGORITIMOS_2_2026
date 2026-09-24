#include <stdio.h>

void inverte_vetor(int *vetor, int tamanho)
{
    int *p1 = vetor;    
    int *p2 = vetor + (tamanho - 1);

    int temp;

    while (p1 < p2)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;

        p1++;
        p2--;
    }
}


int main(void)
{

    int vetor[] = {10, 20, 30, 40, 50};
    int tamanho = 5;

    inverte_vetor(vetor, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}
