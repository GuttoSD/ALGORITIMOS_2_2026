
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

#include <ctype.h>
int main(void){
    FILE*f=fopen("PRODUTOS.txt","r");char l[400],*c[3],letra;float min,max;int achou=0;
    if(!f){printf("Arquivo nao encontrado.\n");return 1;}
    printf("Letra inicial: ");scanf(" %c",&letra);printf("Preco minimo e maximo: ");if(scanf("%f%f",&min,&max)!=2||min>max){fclose(f);return 1;}
    while(fgets(l,sizeof l,f)){char cp[400];strcpy(cp,l);if(separa(cp,c,3)==3&&tolower((unsigned char)c[1][0])==tolower((unsigned char)letra)&&atof(c[2])>=min&&atof(c[2])<=max){printf("%s | %s | %s",c[0],c[1],c[2]);achou=1;}}
    if(!achou)printf("Nenhum produto encontrado.\n");fclose(f);return 0;
}
