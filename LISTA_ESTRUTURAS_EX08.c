#include <stdio.h>

struct Pessoa {
    char nome[50];
    int d,m,a;
};

int main() {
    struct Pessoa v[6], novo, velho;
    int i;
    for(i=0;i<6;i++){
        scanf("%s %d %d %d", v[i].nome, &v[i].d, &v[i].m, &v[i].a);
    }
    novo = velho = v[0];
    for(i=1;i<6;i++){
        if(v[i].a > novo.a ||
          (v[i].a == novo.a && v[i].m > novo.m) ||
          (v[i].a == novo.a && v[i].m == novo.m && v[i].d > novo.d)){
            novo = v[i];
        }
        if(v[i].a < velho.a ||
          (v[i].a == velho.a && v[i].m < velho.m) ||
          (v[i].a == velho.a && v[i].m == velho.m && v[i].d < velho.d)){
            velho = v[i];
        }
    }
    printf("%s\n%s\n", novo.nome, velho.nome);
    return 0;
}
