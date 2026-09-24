#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, *b, **c, ***d;
    b = &a;
    c = &b;
    d = &c;

    scanf("%d", &a);

    printf("%d\n", *b * 2);
    printf("%d\n", **c * 3);
    printf("%d\n", ***d * 4);

    return 0;
}
