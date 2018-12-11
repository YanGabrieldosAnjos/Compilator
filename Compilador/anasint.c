#include "anasint.h"

Token t;
Token *vetorToken[10000];
int x = 0;
int estadoToken = 0;
Pilha *v;
//Operações de pilha para  o vetor
Pilha *inicializa_pilha(void)
{
    return NULL;
}

Pilha *criapilha(Token *v)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->info = v;
    return novo;
}

Pilha *push(Pilha *p, Token *v)
{
    Pilha *paux = p;
    Pilha *novo = criapilha(v);

    if (paux == NULL)
    {
        paux = novo;
    }
    else
    {
        novo->topo = paux;
    }
    return novo;
}
Pilha *pop(Pilha *p)
{
    Pilha *paux = p;
    Pilha *rem = NULL;
    if (paux == NULL)
    {
        printf("nao foi possivel realizar o pop");
        exit(1);
    }
    else
    {
        rem = paux;
        paux = paux->topo;
        free(rem);
    }
    return paux;
}

//CONVERTENDO TIPOS
int typeInt(Token *t)
{
    return t->inteiro;
}
float typeFloat(Token *t)
{
    return t->real;
}
char typeChar(Token *t)
{
    return t->caracter;
}
int isID(Token *t)
{
    if (t->tip == ID)
    {
        return 1;
    }
    return 0;
}
int isType(Token *t)
{
    if (t->tip == CHAR || t->tip == INT || t->tip == STRING || t->tip == BOOL || t->tip == REAL)
    {
        return 1;
    }
}
int isEscope(Token *t)
{
    if (t->tip == PROG || t->tip == PROC || t->tip == FUNC)
    {
        return 1;
    }
}
int prog(int j)
{
    return j;
}

int var(int j)
{
    v->escopo = 0;
    while (vetorToken[j]->tip != ENDVAR)
    {
        if (isType(vetorToken[j]))
        {
            v = push(v, vetorToken[j]);
            j++;
            if (isID(vetorToken[j]))
            {
                v = push(v, vetorToken[j]);
                j++;
            }
            else
            {
                printf("erro: sem identificador");
            }
            printf("erro:sem tipo");
        }
        if (isEscope(vetorToken[j]))
        {
            printf("erro:Sem  o endvar");
            break;
        }
    }

    return j;
}
void start()
{
    int j = 0;

    if (vetorToken[j]->tip == 14)
    {
        if (!isID(vetorToken[j]))
        {
            printf("erro aqui\n");
        }
        j++;
        if (vetorToken[j]->tip = VAR)
        {
            j = var(j);
        }
        while (vetorToken[j]->tip == FUNC || vetorToken[j]->tip == PROC)
        {
            j = prog(j);
        }
    }
    else
    {
        printf("erro SEM pl\n");
    }
}
int anasint(Token *t, int i)
{

    printf("%s\n", t->palavra);
    printf("%d\n", t->tip);

    vetorToken[i] = t;

    start();

    return i;
}
