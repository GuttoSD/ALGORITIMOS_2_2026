#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cadastro {
    char nome[100];
    int idade;
    char endereco[150];
};

static void lerLinha(char *texto, size_t tamanho) {
    if (fgets(texto, (int)tamanho, stdin) != NULL) {
        texto[strcspn(texto, "\n")] = '\0';
    }
}

struct Cadastro *criarVetor(int n) {
    struct Cadastro *vetor;
    int i;

    if (n <= 0) return NULL;
    vetor = malloc((size_t)n * sizeof(struct Cadastro));
    if (vetor == NULL) return NULL;

    for (i = 0; i < n; i++) {
        printf("\nCadastro %d\n", i + 1);
        printf("Nome: ");
        lerLinha(vetor[i].nome, sizeof(vetor[i].nome));
        printf("Idade: ");
        if (scanf("%d", &vetor[i].idade) != 1) {
            free(vetor);
            return NULL;
        }
        getchar();
        printf("Endereco: ");
        lerLinha(vetor[i].endereco, sizeof(vetor[i].endereco));
    }
    return vetor;
}

int main(void) {
    int n, i;
    struct Cadastro *p;

    printf("Quantidade de cadastros: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }
    getchar();

    p = criarVetor(n);
    if (p == NULL) {
        printf("Nao foi possivel criar os cadastros.\n");
        return 1;
    }

    printf("\nCadastros informados:\n");
    for (i = 0; i < n; i++)
        printf("%s | %d anos | %s\n", p[i].nome, p[i].idade, p[i].endereco);

    free(p);
    return 0;
}
