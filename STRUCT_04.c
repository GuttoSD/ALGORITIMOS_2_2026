#include <stdio.h>

struct Hora {
    int h, m, s;
};

int main() {
    struct Hora v[5], maior;
    int i;
    for(i=0;i<5;i++) scanf("%d %d %d", &v[i].h, &v[i].m, &v[i].s);
    maior = v[0];
    for(i=1;i<5;i++){
        if(v[i].h > maior.h ||
           (v[i].h == maior.h && v[i].m > maior.m) ||
           (v[i].h == maior.h && v[i].m == maior.m && v[i].s > maior.s)){
            maior = v[i];
        }
    }
    printf("%02d:%02d:%02d\n", maior.h, maior.m, maior.s);
    return 0;
}
