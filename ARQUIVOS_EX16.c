
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
    FILE*f=fopen("PRODUTOS.txt","r");char l[400],*c[3],desc[150];int cod,dup=0;float preco;
    printf("Codigo: ");if(scanf("%d",&cod)!=1){if(f)fclose(f);return 1;}getchar();
    if(f){while(fgets(l,sizeof l,f)){char cp[400];strcpy(cp,l);if(separa(cp,c,3)==3&&atoi(c[0])==cod){dup=1;break;}}fclose(f);}
    if(dup){printf("Codigo ja cadastrado.\n");return 1;}
    printf("Descricao: ");if(!fgets(desc,sizeof desc,stdin))return 1;tira_fim(desc);
    printf("Preco: ");if(scanf("%f",&preco)!=1||preco<0)return 1;
    f=fopen("PRODUTOS.txt","a");if(!f){perror("PRODUTOS.txt");return 1;}
    fprintf(f,"%d|%s|%.2f\n",cod,desc,preco);fclose(f);printf("Produto cadastrado.\n");return 0;
}
