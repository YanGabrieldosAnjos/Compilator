#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "analex.h"
#include "anasint.h"
#include <string.h>
int main(int argc, char *argv[])
{
    int i = 0;
    Token tx;
    FILE *fp = fopen(argv[1], "r+");
    if (fp == NULL)
    {
        printf("erro ao abrir arquivo");
        return 0;
    }
    char c;
    while (!feof(fp))
    {
        c = fgetc(fp);
        tx = analex(c, fp);
        i = anasint(&tx, i);
    }
    return 0;
}
