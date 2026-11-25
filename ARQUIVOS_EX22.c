
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
static void tira_fim(char *s) { s[strcspn(s, "\r\n")] = '\0'; }
static int separa(char *linha, char *campos[], int max) {
    int n=0; char *p=strtok(linha, "|\r\n");
    while(p && n<max){campos[n++]=p;p=strtok(NULL,"|\r\n");}
    return n;
}

int main(void){
    FILE*f=fopen("PRODUTOS.txt","r");char l[400],*c[3];int achou=0;
    if(!f){printf("Arquivo nao encontrado.\n");return 1;}
    while(fgets(l,sizeof l,f)){char cp[400];strcpy(cp,l);if(separa(cp,c,3)==3&&atof(c[2])<15){printf("Codigo: %s | Descricao: %s | Preco: %s\n",c[0],c[1],c[2]);achou=1;}}
    if(!achou)printf("Nenhum produto encontrado.\n");fclose(f);return 0;
}
