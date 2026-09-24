#include <stdio.h>

void extrair_estatisticas(int *vetor, int tamanho, int *min, int *max,float *media)
{

int i;
float soma = 0;

*min = *(vetor + 0);
*max = *(vetor + 0);
 
for (i = 0; i < tamanho; i++)
{
    *(vetor + i);
    
    if (*(vetor + i) < *min)
{
    *min = *(vetor + i);
}

if (*(vetor + i) > *max)
{
    *max = *(vetor + i);
}

soma = soma + *(vetor + i);

}

*media = soma / 5;

}


int main(void)
{
    int min, max;
    float media;
    int vetor[5] = {51, 1, 51, -100, 14};

    extrair_estatisticas(vetor, 5, &min, &max, &media);

    printf("%d %d %.2f", min, max, media);

    return 0;

}
