#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int n) {
    int *p = v;
    while (p < v + n) {
        printf("%d ", *p);
        p++;
    }
}

int main() {
    int v[5], i;
    for (i = 0; i < 5; i++) scanf("%d", &v[i]);
    imprime(v, 5);
    return 0;
}
