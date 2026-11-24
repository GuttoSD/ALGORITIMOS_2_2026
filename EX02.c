#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[50];
    float notas[3];
};

int main(void) {
    printf("Tamanho da estrutura: %zu bytes\n", sizeof(struct Aluno));
    return 0;
}
