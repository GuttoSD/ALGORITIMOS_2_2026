
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
    FILE*in=fopen("PRODUTOS.txt","r"),*out=fopen("TEMP.txt","w");char l[400],*c[3];int removidos=0;
    if(!in||!out){printf("Erro ao abrir arquivos.\n");if(in)fclose(in);if(out)fclose(out);return 1;}
    while(fgets(l,sizeof l,in)){char cp[400];strcpy(cp,l);if(separa(cp,c,3)==3){if(atof(c[2])>200)removidos++;else fputs(l,out);}}
    fclose(in);fclose(out);if(remove("PRODUTOS.txt")||rename("TEMP.txt","PRODUTOS.txt")){printf("Erro ao atualizar arquivo.\n");return 1;}
    printf("%d produto(s) excluido(s).\n",removidos);return 0;
}
