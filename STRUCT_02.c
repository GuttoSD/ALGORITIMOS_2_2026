#include <stdio.h>
#include <math.h>

struct Ponto {
    float x, y;
};

struct Retangulo {
    struct Ponto superior_esquerdo;
    struct Ponto inferior_direito;
};

int main(void) {
    struct Retangulo retangulo1;

    printf("Digite o ponto superior esquerdo (x y): ");
    scanf("%f %f", &retangulo1.superior_esquerdo.x, &retangulo1.superior_esquerdo.y);

    printf("Digite o ponto inferior direito (x y): ");
    scanf("%f %f", &retangulo1.inferior_direito.x, &retangulo1.inferior_direito.y);

    float largura = fabs(retangulo1.inferior_direito.x - retangulo1.superior_esquerdo.x);
    float altura = fabs(retangulo1.superior_esquerdo.y - retangulo1.inferior_direito.y);

    float area = largura * altura;
    float diagonal = sqrt(largura * largura + altura * altura);
    float perimetro = 2 * (largura + altura);

    printf("Área: %.2f\n", area);
    printf("Diagonal: %.2f\n", diagonal);
    printf("Perímetro: %.2f\n", perimetro);

    return 0;
}
