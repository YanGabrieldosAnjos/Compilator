#ifndef ANASINT_H_INCLUDED
#define ANASINT_H_INCLUDED
#include "analex.h"

//Estrutura do vetor para analise sintatica

typedef struct pilha{
    struct pilha *topo;
    Token *info;
    int escopo;
}Pilha;

int anasint(Token *t,int i);
void start();
int isID(Token *t);
int prog(int j);
int var(int j);
#endif // ANASINT_H_INCLUDED
