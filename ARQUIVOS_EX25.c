
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
    FILE*in=fopen("PRODUTOS.txt","r"),*out=fopen("TEMP.txt","w");char l[400],*c[3];float min,max,perc;
    if(!in||!out){printf("Erro ao abrir arquivos.\n");if(in)fclose(in);if(out)fclose(out);return 1;}
    printf("Preco minimo e maximo: ");if(scanf("%f%f",&min,&max)!=2||min>max){fclose(in);fclose(out);return 1;}
    printf("Percentual de desconto: ");if(scanf("%f",&perc)!=1||perc<0||perc>100){fclose(in);fclose(out);return 1;}
    while(fgets(l,sizeof l,in)){char cp[400];strcpy(cp,l);if(separa(cp,c,3)==3){float p=atof(c[2]);if(p>=min&&p<=max)p-=p*perc/100;fprintf(out,"%s|%s|%.2f\n",c[0],c[1],p);}}
    fclose(in);fclose(out);if(remove("PRODUTOS.txt")||rename("TEMP.txt","PRODUTOS.txt")){printf("Erro ao atualizar arquivo.\n");return 1;}
    printf("Descontos aplicados.\n");return 0;
}
