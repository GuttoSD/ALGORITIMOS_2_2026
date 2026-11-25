#include <stdio.h>
int main(void){FILE*f=fopen("PRODUTOS.txt","w");if(!f){perror("PRODUTOS.txt");return 1;}fclose(f);printf("Arquivo PRODUTOS.txt criado.\n");return 0;}
