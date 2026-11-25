
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
    FILE*in=fopen("PRODUTOS.txt","r"),*out=fopen("TEMP.txt","w");char l[400],*c[3];
    if(!in||!out){printf("Erro ao abrir arquivos.\n");if(in)fclose(in);if(out)fclose(out);return 1;}
    while(fgets(l,sizeof l,in)){char cp[400];strcpy(cp,l);if(separa(cp,c,3)==3){float p=atof(c[2]);if(p>100)p+=10;fprintf(out,"%s|%s|%.2f\n",c[0],c[1],p);}}
    fclose(in);fclose(out);if(remove("PRODUTOS.txt")||rename("TEMP.txt","PRODUTOS.txt")){printf("Erro ao substituir arquivo.\n");return 1;}printf("Precos atualizados.\n");return 0;
}
