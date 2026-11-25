#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void fim(char*s){s[strcspn(s,"\r\n")]=0;}
static int existe(const char*arq,int cod){
    FILE*f=fopen(arq,"r");char l[400];int ok=0,x;char *p;
    if(!f)return 0;
    while(fgets(l,sizeof l,f)){p=strchr(l,';');if(p)*p=0;if(sscanf(l,"%d",&x)==1&&x==cod){ok=1;break;}}
    fclose(f);return ok;
}
int main(void){
    int op;
    do{
        printf("\n1-Cadastrar estacao\n2-Cadastrar estilista\n3-Cadastrar roupa\n4-Relatorio por estacao\n5-Sair\nOpcao: ");
        if(scanf("%d",&op)!=1) break;
        getchar();
        if(op==1){
            int cod;char nome[100];FILE*f;
            printf("Codigo: ");scanf("%d",&cod);getchar();printf("Nome da estacao: ");fgets(nome,sizeof nome,stdin);fim(nome);
            f=fopen("estacao.txt","a");if(!f){perror("estacao.txt");continue;}fprintf(f,"%d;%s\n",cod,nome);fclose(f);
        }else if(op==2){
            int cod;char nome[100];float sal;FILE*f;
            printf("Codigo: ");scanf("%d",&cod);getchar();printf("Nome: ");fgets(nome,sizeof nome,stdin);fim(nome);printf("Salario: ");scanf("%f",&sal);
            f=fopen("estilista.txt","a");if(!f){perror("estilista.txt");continue;}fprintf(f,"%d;%s;%.2f\n",cod,nome,sal);fclose(f);
        }else if(op==3){
            int cr,ce,cs,ano;char desc[150];FILE*f;
            printf("Codigo da roupa: ");scanf("%d",&cr);getchar();printf("Descricao: ");fgets(desc,sizeof desc,stdin);fim(desc);
            printf("Codigo do estilista: ");scanf("%d",&ce);printf("Codigo da estacao: ");scanf("%d",&cs);printf("Ano: ");scanf("%d",&ano);
            if(!existe("estilista.txt",ce)||!existe("estacao.txt",cs)){printf("Estilista ou estacao nao cadastrado.\n");continue;}
            f=fopen("roupa.txt","a");if(!f){perror("roupa.txt");continue;}fprintf(f,"%d;%s;%d;%d;%d\n",cr,desc,ce,cs,ano);fclose(f);
        }else if(op==4){
            FILE *r=fopen("roupa.txt","r"),*e=fopen("estilista.txt","r");char l[400],*p,desc[150],nome[100];int cr,ce,cs,ano,achou=0;
            if(!r||!e){printf("Crie os arquivos primeiro.\n");if(r)fclose(r);if(e)fclose(e);continue;}
            int busca;printf("Codigo da estacao: ");scanf("%d",&busca);
            while(fgets(l,sizeof l,r)){
                char *a=strtok(l,";"),*b=strtok(NULL,";"),*c=strtok(NULL,";"),*d=strtok(NULL,";"),*g=strtok(NULL,";\r\n");
                if(!a||!b||!c||!d||!g)continue;
                cr=atoi(a);snprintf(desc,sizeof desc,"%s",b);ce=atoi(c);cs=atoi(d);ano=atoi(g);
                if(cs==busca){
                    rewind(e);char linha[300];int encontrou=0;
                    while(fgets(linha,sizeof linha,e)){char *x=strtok(linha,";"),*y=strtok(NULL,";");if(x&&y&&atoi(x)==ce){snprintf(nome,sizeof nome,"%s",y);fim(nome);encontrou=1;break;}}
                    printf("Roupa %d: %s | Ano: %d | Estilista: %s\n",cr,desc,ano,encontrou?nome:"nao encontrado");achou=1;
                }
            }
            if(!achou)printf("Nenhuma roupa encontrada.\n");fclose(r);fclose(e);
        }
    }while(op!=5);
    return 0;
}
