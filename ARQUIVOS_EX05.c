
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void tira_fim(char *s) {
    s[strcspn(s, "\r\n")] = '\0';
}
static int separa(char *linha, char *campos[], int max) {
    int n = 0;
    char *p = strtok(linha, ";\r\n");
    while (p && n < max) { campos[n++] = p; p = strtok(NULL, ";\r\n"); }
    return n;
}
static int le_data(const char *s, struct tm *t) {
    int d, m, a;
    if (sscanf(s, "%d/%d/%d", &d, &m, &a) != 3) return 0;
    memset(t, 0, sizeof(*t));
    t->tm_mday=d; t->tm_mon=m-1; t->tm_year=a-1900; t->tm_hour=12;
    t->tm_isdst=-1;
    time_t v=mktime(t);
    if (v == (time_t)-1 || t->tm_mday != d || t->tm_mon != m-1 || t->tm_year != a-1900) return 0;
    return 1;
}

int main(void){
    FILE *in=fopen("clientes.txt","r"),*out=fopen("clientes.tmp","w");
    char linha[400],*c[4],nome[100],end[150],fone[30];int cod,achou=0;
    if(!in||!out){printf("Erro ao abrir arquivos.\n");if(in)fclose(in);if(out)fclose(out);return 1;}
    printf("Codigo do cliente a alterar: ");if(scanf("%d",&cod)!=1){fclose(in);fclose(out);return 1;}getchar();
    while(fgets(linha,sizeof linha,in)){
        char cp[400];strcpy(cp,linha);
        if(separa(cp,c,4)==4&&atoi(c[0])==cod){
            achou=1;
            printf("Novo nome: ");fgets(nome,sizeof nome,stdin);tira_fim(nome);
            printf("Novo endereco: ");fgets(end,sizeof end,stdin);tira_fim(end);
            printf("Novo telefone: ");fgets(fone,sizeof fone,stdin);tira_fim(fone);
            fprintf(out,"%d;%s;%s;%s\n",cod,nome,end,fone);
        }else fputs(linha,out);
    }
    fclose(in);fclose(out);
    if(remove("clientes.txt")||rename("clientes.tmp","clientes.txt")){printf("Erro ao atualizar arquivo.\n");return 1;}
    printf(achou?"Cadastro alterado.\n":"Cliente nao encontrado; arquivo mantido.\n");return 0;
}
