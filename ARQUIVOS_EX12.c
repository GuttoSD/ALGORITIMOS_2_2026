#include <stdio.h>
int main(void){
    const char *nomes[]={"estilista.txt","roupa.txt","estacao.txt"};
    for(int i=0;i<3;i++){FILE *a=fopen(nomes[i],"w");if(!a){printf("Erro ao criar %s\n",nomes[i]);return 1;}fclose(a);}
    printf("Arquivos criados com sucesso.\n");return 0;
}
