#include <stdio.h>
#include <string.h>

struct Pessoa
{
    char nome[100];
    int idade;
    char endereco[100];
};

int main (void)
{
    struct Pessoa pessoa1;

    printf("Digite o nome da pessoa: ");
    fgets(pessoa1.nome, 100, stdin);

    printf("Digite o endereço da pessoa: ");
    fgets(pessoa1.endereco, 100, stdin);

    printf("Digite a idade da pessoa:");
    scanf("%d", &pessoa1.idade);

    


    printf("\nSeu nome: %sSua idade: %d\nSeu endereço: %s\n", pessoa1.nome, pessoa1.idade, pessoa1.endereco);

    return 0;
}
