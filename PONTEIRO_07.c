#include <stdio.h>
#include <stdlib.h>

int ocorre(char *s1, char *s2) {
    char *p1, *p2, *inicio;
    if (*s2 == '\0') return 1;

    for (p1 = s1; *p1 != '\0'; p1++) {
        inicio = p1;
        p2 = s2;
        while (*inicio == *p2 && *p2 != '\0') {
            inicio++;
            p2++;
        }
        if (*p2 == '\0') return 1;
    }
    return 0;
}

int main() {
    char s1[100], s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    if (ocorre(s1, s2)) printf("Sim");
    else printf("Nao");
    return 0;
}
