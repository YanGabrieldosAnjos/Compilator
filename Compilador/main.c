#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "analex.h"
#include <string.h>
int main()
{
    FILE *fp=fopen("teste.txt","r+");
    if(fp==NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }
    char c;
    while(!feof(fp)){
        c=fgetc(fp);
        analex(c,fp);
    }
    return 0;
}
