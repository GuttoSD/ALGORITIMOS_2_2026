#include <stdio.h>

int* receber_Vetor (int *v, int tam, int x)
{
    for (int i = 0; i < tam; i++) {
        if (v[i] == x) {
            return &v[i]; 
        }
    }
    return NULL; 

}

int main (void)
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int x;

    printf("Digite o valor de x: \n");
    scanf("%d", &x);

     int *resultado = receber_Vetor(vetor, tamanho, x);

    if (resultado != NULL)
    {
        printf("O valor %d foi encontrado", *resultado);
        printf("Endereco de memoria: %p\n", (void*)resultado);
        printf("Indice no vetor: %ld\n", resultado - vetor);
    } else {
        printf("Valor %d nao foi encontrado no vetor.\n", x);
    }

    return 0;
    
}
