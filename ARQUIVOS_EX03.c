
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

int main(void) {
    FILE *cli=fopen("clientes.txt","r"), *rec;
    char linha[400], *c[4]; int cod, existe=0, doc; float valor;
    char emissao[20], venc[20];
    if(!cli){printf("Crie/cadastre clientes primeiro.\n");return 1;}
    printf("Codigo do cliente: "); if(scanf("%d",&cod)!=1){fclose(cli);return 1;} getchar();
    while(fgets(linha,sizeof linha,cli)){
        char copia[400]; strcpy(copia,linha);
        if(separa(copia,c,4)==4 && atoi(c[0])==cod){existe=1;break;}
    }
    fclose(cli);
    if(!existe){printf("Cliente nao cadastrado.\n");return 1;}
    printf("Numero do documento: "); if(scanf("%d",&doc)!=1)return 1;
    printf("Valor: "); if(scanf("%f",&valor)!=1)return 1; getchar();
    printf("Data de emissao (dd/mm/aaaa): "); if(!fgets(emissao,sizeof emissao,stdin))return 1; tira_fim(emissao);
    printf("Data de vencimento (dd/mm/aaaa): "); if(!fgets(venc,sizeof venc,stdin))return 1; tira_fim(venc);
    rec=fopen("recebimentos.txt","a"); if(!rec){perror("recebimentos.txt");return 1;}
    fprintf(rec,"%d;%.2f;%s;%s;%d\n",doc,valor,emissao,venc,cod);
    fclose(rec); return 0;
}
