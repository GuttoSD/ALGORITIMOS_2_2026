#include <stdio.h>

struct Atleta {
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
};

int main() {
    struct Atleta v[5], temp;
    int i, j;
    for(i=0;i<5;i++)
        scanf("%s %s %d %f", v[i].nome, v[i].esporte, &v[i].idade, &v[i].altura);

    for(i=0;i<4;i++){
        for(j=i+1;j<5;j++){
            if(v[j].idade > v[i].idade){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    for(i=0;i<5;i++)
        printf("%s %s %d %.2f\n", v[i].nome, v[i].esporte, v[i].idade, v[i].altura);

    return 0;
}
