#include <stdio.h>

float volumeEsfera (float raio)
{
    float volume;

    printf("Digite o raio da esfera: \n");
    scanf("%f", &raio);

    volume = (4.0 / 3.0) * 3.14 * raio * raio * raio;

    printf("O volume da esfera é: %.2f\n", volume);

    return volume;
}

int main(void)
{
    float raio;

    volumeEsfera(raio);

    return(0);
}
