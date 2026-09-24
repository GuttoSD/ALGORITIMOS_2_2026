#include <stdio.h>

void horasMinutosSegundos (float h, float m, float s){

    printf("Digite o valor em segundos: \n");
    scanf("%f", &s);

    m = 0;
    h = 0;

    while (s >= 60)
    {
        s = s - 60;
        m++;
    }
     while (m >= 60)
    {
        m = m - 60;
        h++;
    }

    printf(" O valor em horas, minutos e segundos é: %f %f %f", h, m, s);
}

int main(void){

    float h, m, s;

    horasMinutosSegundos (h,m,s);

    return(0);
}
