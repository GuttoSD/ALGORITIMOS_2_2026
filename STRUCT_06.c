#include <stdio.h>

struct Atleta {
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
};

int main() {
    struct Atleta v[5], alto, velho;
    int i;
    for(i=0;i<5;i++){
        scanf("%s %s %d %f", v[i].nome, v[i].esporte, &v[i].idade, &v[i].altura);
    }
    alto = velho = v[0];
    for(i=1;i<5;i++){
        if(v[i].altura > alto.altura) alto = v[i];
        if(v[i].idade > velho.idade) velho = v[i];
    }
    printf("%s\n%s\n", alto.nome, velho.nome);
    return 0;
}
