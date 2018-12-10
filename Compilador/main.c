#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "analex.h"
#include "anasint.h"
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
        printf("%s\n",tx.palavra);
        printf("%d\n",tx.tip);
        anasint(&tx);
    }
    return 0;
}
