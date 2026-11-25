
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
    FILE *arq=fopen("recebimentos.txt","r");char linha[400],*c[5];int achou=0;
    int cod; printf("Codigo do cliente: "); if(scanf("%d",&cod)!=1)return 1;
    if(!arq){printf("Arquivo recebimentos.txt nao encontrado.\n");return 1;}
    while(fgets(linha,sizeof linha,arq)){
        char cp[400];strcpy(cp,linha);
        if(separa(cp,c,5)==5 && atoi(c[4])==cod){
            printf("Documento: %s | Valor: %s | Emissao: %s | Vencimento: %s | Codigo cliente: %s\n",c[0],c[1],c[2],c[3],c[4]);achou=1;
        }
    }
    if(!achou)printf("Nenhum recebimento encontrado.\n");
    fclose(arq);return 0;
}
