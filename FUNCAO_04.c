#include <stdio.h>

int idadeEmDias (int anos, int meses, int dias)
{

    printf("Insira sua idade em anos, meses e dias: \n");
    scanf("%d", &anos);
    scanf("%d", &meses);
    scanf("%d", &dias);

    int total = (anos * 365) + (meses * 30) + dias;

    printf(" Sua idade total em dias é igual a: %d dias\n", total);

    return total;
}

int main (void)
{
    int anos, meses, dias;

    idadeEmDias (anos, meses, dias);
}
