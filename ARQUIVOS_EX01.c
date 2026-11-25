#include <stdio.h>
int main(void) {
    FILE *clientes=fopen("clientes.txt","w");
    FILE *recebimentos=fopen("recebimentos.txt","w");
    if (!clientes || !recebimentos) {
        printf("Erro ao criar arquivos.\n");
        if(clientes) fclose(clientes);
        if(recebimentos) fclose(recebimentos);
        return 1;
    }
    fclose(clientes); fclose(recebimentos);
    printf("Arquivos criados com sucesso.\n");
    return 0;
}
