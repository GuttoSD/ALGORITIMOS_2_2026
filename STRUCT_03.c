#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[50];
    float n1, n2, n3;
};

int main(void) {
    struct Aluno alunos[5];
    float maiorMedia = -1;
    int indice = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Digite o nome: ");
        scanf("%s", alunos[i].nome);

        printf("Digite as tres notas: ");
        scanf("%f %f %f", &alunos[i].n1, &alunos[i].n2, &alunos[i].n3);

        float media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;

        if (media > maiorMedia) {
            maiorMedia = media;
            indice = i;
        }
    }

    printf("Aluno com maior media:\n");
    printf("%s\n", alunos[indice].nome);
    printf("%.2f %.2f %.2f\n", alunos[indice].n1, alunos[indice].n2, alunos[indice].n3);

    return 0;
}
