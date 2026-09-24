#include <stdio.h>
#include <math.h>

void bhaskara (float x1, float x2)
{
    int a,b,c;
    int d, b2;

    printf("Digite os valores de A, B e C \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    b2 = (b * b);
    d = b2 - 4 * (a * c);

    x1 = ((-b) + sqrt(d)) / (2 * a);
    x2 = ((-b) - sqrt(d)) / (2 * a);

    printf(" Os valor de x1 é: %f", x1);
    printf(" Os valor de x2 é: %f", x2);

}

int main(void){

    float x1, x2;

    bhaskara(x1,x2);

    return(0);
}
