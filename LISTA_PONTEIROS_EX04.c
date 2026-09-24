#include <stdio.h>
#include <stdlib.h>

int main() {
    float mat[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Endereco de mat[%d][%d] = %p\n", i, j, (void*)&mat[i][j]);
        }
    }

    return 0;
}
