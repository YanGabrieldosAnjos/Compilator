#ifndef ANALEX_H_INCLUDED
#define ANALEX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum Tipo
{
    
    BOOL=0,
    CHAR,
    ELSE,
    ENDFOR,
    ENDFUNC,
    ENDIF,
    ENDPROC,
    ENDPROG,
    ENDVAR,
    ENDWHILE,
    FOR,
    FUNC,
    IF,
    INT,
    PL,
    PROC,
    PROG,
    REAL,
    STRING,
    VAR,
    WHILE, //reservados,ler referencia dnv
    AND,
    OR,
    NOT,
    VIRGULA,
    PVIRGULA,
    PARD,
    PARE,
    MENOR,
    MENORIGUAL,
    MAIOR,
    MAIORIGUAL,
    ATRIB,
    IGUALDADE,
    hashtag,
    ID,
    SOMA,
    SUB,
    MULTI,
    DIV
} tipo; //simbolos
typedef struct
{
    tipo tip;
    union {
        int inteiro;
        float real;
        char caracter;
        char palavra[10];
        char reservada[10];
    };
} Token;

Token analex(char c, FILE *fp);
int finder(char c[10]);
#endif // ANALEX_H_INCLUDED
