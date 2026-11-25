
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
    FILE *rec=fopen("recebimentos.txt","r"),*cli;
    char linha[400],*c[5],inicio[20],fim[20],cl[400],*cc[4];
    struct tm ti,tf,tv,th;time_t hoje=time(NULL);int achou=0;
    if(!rec){printf("Arquivo recebimentos.txt nao encontrado.\n");return 1;}
    printf("Data inicial (dd/mm/aaaa): ");fgets(inicio,sizeof inicio,stdin);tira_fim(inicio);
    printf("Data final (dd/mm/aaaa): ");fgets(fim,sizeof fim,stdin);tira_fim(fim);
    if(!le_data(inicio,&ti)||!le_data(fim,&tf)||mktime(&ti)>mktime(&tf)){printf("Periodo invalido.\n");fclose(rec);return 1;}
    struct tm *pt=localtime(&hoje);if(!pt){fclose(rec);return 1;}th=*pt;th.tm_hour=12;th.tm_min=th.tm_sec=0;
    while(fgets(linha,sizeof linha,rec)){
        char cp[400];strcpy(cp,linha);
        if(separa(cp,c,5)!=5||!le_data(c[3],&tv))continue;
        time_t venc=mktime(&tv), a=mktime(&ti), b=mktime(&tf);
        if(venc<a||venc>b)continue;
        int atraso=0;double dias=difftime(mktime(&th),venc)/86400.0;if(dias>0)atraso=(int)dias;
        int cod=atoi(c[4]);char nome[100]="(nao encontrado)";
        cli=fopen("clientes.txt","r");
        if(cli){while(fgets(cl,sizeof cl,cli)){char cp2[400];strcpy(cp2,cl);if(separa(cp2,cc,4)==4&&atoi(cc[0])==cod){snprintf(nome,sizeof nome,"%s",cc[1]);break;}}fclose(cli);}
        printf("Documento: %s | Valor: %s | Cliente: %s | Vencimento: %s | Dias em atraso: %d\n",c[0],c[1],nome,c[3],atraso);achou=1;
    }
    if(!achou)printf("Nenhum recebimento no periodo.\n");
    fclose(rec);return 0;
}
