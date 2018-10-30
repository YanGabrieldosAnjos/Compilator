#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "analex.h"
#include <string.h>
int main()
{
    Token tx;
    FILE *fp=fopen("teste.txt","r+");
    if(fp==NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }
    char c;
    while(!feof(fp)){
        c=fgetc(fp);
        tx=analex(c,fp);
        printf("VALOR DO TOKEN :%s\n",tx.palavra);
        printf("ID DO TOKEN : %d\n",tx.tip);
    }
    return 0;
}
