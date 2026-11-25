#include <stdio.h>
#include <string.h>
static void fim(char*s){s[strcspn(s,"\r\n")]=0;}
int main(void){
    int op;
    do{
        printf("\n1-Criar\n2-Incluir\n3-Sair\nOpcao: ");
        if(scanf("%d",&op)!=1) break;
        getchar();
        if(op==1){FILE*f=fopen("dados.txt","w");if(!f){perror("dados.txt");continue;}fclose(f);printf("Arquivo criado.\n");}
        else if(op==2){
            FILE*f=fopen("dados.txt","a");if(!f){printf("Crie o arquivo primeiro.\n");continue;}
            char linha[200],nome[100];int num;float n1,n2;
            while(1){
                printf("Numero (ENTER para encerrar): ");
                if(!fgets(linha,sizeof linha,stdin))break;
                if(linha[0]=='\n'||linha[0]=='\r')break;
                if(sscanf(linha,"%d",&num)!=1){printf("Numero invalido.\n");continue;}
                printf("Nome: ");if(!fgets(nome,sizeof nome,stdin))break;fim(nome);
                printf("Nota 1: ");if(scanf("%f",&n1)!=1)break;
                printf("Nota 2: ");if(scanf("%f",&n2)!=1)break;getchar();
                fprintf(f,"%d|%s|%.2f|%.2f\n",num,nome,n1,n2);
            }
            fclose(f);
            f=fopen("dados.txt","r");if(!f){perror("dados.txt");continue;}
            printf("\nRegistros e medias:\n");
            while(fgets(linha,sizeof linha,f)){char nome2[100];int x;float a,b;if(sscanf(linha,"%d|%99[^|]|%f|%f",&x,nome2,&a,&b)==4)printf("%d - %s: media %.2f\n",x,nome2,(a+b)/2);}
            fclose(f);
        }
    }while(op!=3);
    return 0;
}
