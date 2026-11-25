
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
    FILE *in=fopen("recebimentos.txt","r"),*out=fopen("recebimentos.tmp","w");
    char linha[400],*c[5],em[20],ve[20];int doc,cod,achou=0;float valor;
    if(!in||!out){printf("Erro ao abrir arquivos.\n");if(in)fclose(in);if(out)fclose(out);return 1;}
    printf("Numero do documento: ");if(scanf("%d",&doc)!=1){fclose(in);fclose(out);return 1;}
    printf("Codigo do cliente: ");if(scanf("%d",&cod)!=1){fclose(in);fclose(out);return 1;}getchar();
    while(fgets(linha,sizeof linha,in)){
        char cp[400];strcpy(cp,linha);
        if(separa(cp,c,5)==5&&atoi(c[0])==doc&&atoi(c[4])==cod){
            achou=1;printf("Novo valor: ");scanf("%f",&valor);getchar();
            printf("Nova data de emissao: ");fgets(em,sizeof em,stdin);tira_fim(em);
            printf("Nova data de vencimento: ");fgets(ve,sizeof ve,stdin);tira_fim(ve);
            fprintf(out,"%d;%.2f;%s;%s;%d\n",doc,valor,em,ve,cod);
        }else fputs(linha,out);
    }
    fclose(in);fclose(out);
    if(remove("recebimentos.txt")||rename("recebimentos.tmp","recebimentos.txt")){printf("Erro ao atualizar arquivo.\n");return 1;}
    printf(achou?"Recebimento alterado.\n":"Recebimento nao encontrado.\n");return 0;
}
