
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
    FILE *arq=fopen("clientes.txt","a");
    int cod; char nome[100], endereco[150], fone[30];
    if(!arq){perror("clientes.txt");return 1;}
    printf("Codigo: "); if(scanf("%d",&cod)!=1){fclose(arq);return 1;} getchar();
    printf("Nome: "); if(!fgets(nome,sizeof nome,stdin)){fclose(arq);return 1;} tira_fim(nome);
    printf("Endereco: "); if(!fgets(endereco,sizeof endereco,stdin)){fclose(arq);return 1;} tira_fim(endereco);
    printf("Telefone: "); if(!fgets(fone,sizeof fone,stdin)){fclose(arq);return 1;} tira_fim(fone);
    fprintf(arq,"%d;%s;%s;%s\n",cod,nome,endereco,fone);
    fclose(arq); return 0;
}
