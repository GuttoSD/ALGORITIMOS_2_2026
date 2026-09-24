#include <stdio.h>

void tabuada (int n)
{
    printf("Digite um valor: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d x %d = %d\n", i, n, i * n);
    }
}

int main(void)
{
    int n;

    tabuada(n);

    return(0);
}
