#include <stdio.h>

void notaAluno (float nota)
{
    printf("Digite a nota do aluno: \n");
    scanf("%f", &nota);

    if (nota >= 0 && nota <= 4.9)
    {
        printf(" Conceito D \n");
    }
    else if (nota >= 5 && nota <= 6.9)
    {
        printf(" Conceito C \n");
    }
    else if (nota >= 7 && nota <= 8.9)
    {
        printf(" Conceito B \n");
    }
    else if (nota >= 9 && nota <= 10)
    {
        printf(" Conceito A \n");
    }
    else {
        printf(" Não é um valor válido. \n");
    }
}

int main(void) {

    int nota;
    notaAluno(nota);
    return(0);
}
