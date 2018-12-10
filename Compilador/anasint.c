#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "analex.h"
#include "anasint.h"
#include <string.h>
Token t;
Token  *pt;
//Estrutura do vetor para analise sintatica

typedef struct vetor{
    int escopo;
    int topo;
    Token* elementos[1000];
}Vetor;
//Operações de pilha para  o vetor
void push(Vetor *vetor,Token  *t){
    if(vetor->topo==0){
        vetor->elementos[vetor->topo]=t;
    }else if(vetor->topo>=1){
        vetor->topo++;
        vetor->elementos[vetor->topo]=t;
    }
}
void  pop(Vetor *vetor){
    vetor->elementos[vetor->topo]=NULL;
    vetor->topo--;
}
//CONVERTENDO TIPOS
int typeInt(Token *t){
    return t->inteiro;
}
float typeFloat(Token *t){
    return t->real;
}
char typeChar(Token *t){
    return t->caracter;
}
void anasint(Token  *t){}



