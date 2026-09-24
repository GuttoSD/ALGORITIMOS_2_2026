#include <stdio.h>

int main (void)
{

    int matriz[3][3]= {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
    int *ptr = &matriz[0][0];

    int soma = *(ptr + 0) + *(ptr + 4) + *(ptr + 8) ;

    printf("O valor da soma é de: %d \n", soma);

    return 0;
}
