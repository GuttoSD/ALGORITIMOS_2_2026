
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
    FILE *in=fopen("clientes.txt","r"), *out=fopen("clientes.tmp","w");
    FILE *ri,*ro; char linha[400],*c[5]; int cod, removidos=0;
    if(!in||!out){printf("Erro ao abrir arquivos de clientes.\n");if(in)fclose(in);if(out)fclose(out);return 1;}
    printf("Codigo do cliente a excluir: ");if(scanf("%d",&cod)!=1){fclose(in);fclose(out);return 1;}
    while(fgets(linha,sizeof linha,in)){
        char cp[400];strcpy(cp,linha);
        if(separa(cp,c,4)==4&&atoi(c[0])==cod)removidos++;else fputs(linha,out);
    }
    fclose(in);fclose(out);
    if(remove("clientes.txt")!=0||rename("clientes.tmp","clientes.txt")!=0){printf("Erro ao atualizar clientes.\n");return 1;}
    ri=fopen("recebimentos.txt","r");ro=fopen("recebimentos.tmp","w");
    if(!ri||!ro){printf("Erro ao abrir recebimentos.\n");if(ri)fclose(ri);if(ro)fclose(ro);return 1;}
    while(fgets(linha,sizeof linha,ri)){
        char cp[400];strcpy(cp,linha);
        if(separa(cp,c,5)==5&&atoi(c[4])==cod)continue;
        fputs(linha,ro);
    }
    fclose(ri);fclose(ro);
    if(remove("recebimentos.txt")!=0||rename("recebimentos.tmp","recebimentos.txt")!=0){printf("Erro ao atualizar recebimentos.\n");return 1;}
    printf("Cliente excluido. Registros removidos: %d\n",removidos);return 0;
}
