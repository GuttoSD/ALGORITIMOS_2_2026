#include <stdio.h>
#include <stdlib.h>

void preenche(int *v, int n, int valor) {
    int *p = v;
    while (p < v + n) {
        *p = valor;
        p++;
    }
}

int main() {
    int v[5], i;
    preenche(v, 5, 7);
    for (i = 0; i < 5; i++) printf("%d ", v[i]);
    return 0;
}
