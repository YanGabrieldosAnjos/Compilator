#ifndef ANASINT_H_INCLUDED
#define ANASINT_H_INCLUDED
#include "analex.h"

//Estrutura do vetor para analise sintatica
typedef struct vetor
{
    int escopo;
    int topo;
    Token *elementos[1000];
} Vetor;

void anasint(Token *t);
void push(Vetor *v, Token *t);
void pop(Vetor *vetor);
#endif // ANASINT_H_INCLUDED
