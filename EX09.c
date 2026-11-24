#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverteString(const char texto[]) {
    size_t tamanho = strlen(texto), i;
    char *invertida = malloc(tamanho + 1);
    if (invertida == NULL) return NULL;
    for (i = 0; i < tamanho; i++) invertida[i] = texto[tamanho - 1 - i];
    invertida[tamanho] = '\0';
    return invertida;
}

int main(void) {
    char texto[200];
    char *resultado;
    printf("Digite uma string: ");
    if (fgets(texto, sizeof(texto), stdin) == NULL) return 1;
    texto[strcspn(texto, "\n")] = '\0';
    resultado = inverteString(texto);
    if (resultado == NULL) { printf("Falha na alocacao.\n"); return 1; }
    printf("String invertida: %s\n", resultado);
    free(resultado);
    return 0;
}
