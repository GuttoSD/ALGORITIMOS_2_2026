#include <stdio.h>
#include <stdlib.h>

//(Fórmulas: Área = 4 * PI * R² | Volume = (4/3) * PI * R³).


void calcular_esfera(float raio, float *area, float *volume)
{
    *area = 4 * 3.14 * (raio * raio);
    
    *volume = 4/3 * 3.14 * (raio * raio * raio);

}

int main(void)
{
    float r, a, v;

    printf(" Digite o valor do raio. \n");
    scanf("%f", &r);
    
    calcular_esfera(r, &a, &v);

    printf("Sua area é: %2.f, e seu volume é: %2.f", a , v);

    return 0;

}
