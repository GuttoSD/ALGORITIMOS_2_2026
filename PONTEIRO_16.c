#include <stdio.h>

int* busca_subvetor(int *vetor, int tam_v, int *sub, int tam_s)
{
    int i, j;

    for (i = 0; i <= tam_v - tam_s; i++)
    {
        for (j = 0; j < tam_s; j++)
        {
            if (*(vetor + i + j) != *(sub + j))
                break;
        }

        if (j == tam_s)
            return vetor + i;
    }

    return NULL;
}

int main()
{
    int vetor[] = {10, 20, 30, 40, 50, 60};
    int sub[] = {30, 40, 50};

    int *resultado = busca_subvetor(vetor, 6, sub, 3);

    if (resultado != NULL)
        printf("Subvetor encontrado na posicao %ld.\n", resultado - vetor);
    else
        printf("Subvetor nao encontrado.\n");

    return 0;
}

