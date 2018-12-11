#include "anasint.h"

Token vetorToken[10000];
int vetor_token_pos = 0;

int x = 0;
int estadoToken = 0;
Pilha *v;
//Operações de pilha para  o vetor
Pilha *inicializa_pilha(void)
{
    return NULL;
}

Pilha *criapilha(Token v)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->info = &v;
    return novo;
}

Pilha *push(Pilha *p, Token v)
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
int typeInt(Token t)
{
    return t.inteiro;
}
float typeFloat(Token t)
{
    return t.real;
}
char typeChar(Token t)
{
    return t.caracter;
}
int isID(Token t)
{
    if (t.tip == ID)
    {
        return 1;
    }
    return 0;
}
int isType(Token t)
{
    if (t.tip == CHAR || t.tip == INT || t.tip == STRING || t.tip == BOOL || t.tip == REAL)
    {
        return 1;
    }

    return 0;
}
int isEscope(Token t)
{
    if (t.tip == PROG || t.tip == PROC || t.tip == FUNC)
    {
        return 1;
    }
}
int prog(int j)
{
    return j;
}

int var(int stack_pos)
{
    printf("Iniciando verificacao de VAR.\n");

    while (vetorToken[stack_pos].tip != ENDVAR)
    {
        if (stack_pos > vetor_token_pos)
        {
            printf("ERRO SINTATICO: VAR SEM ENDVAR");
            return -1;
        }
        else if (isType(vetorToken[stack_pos]))
        {
            v = push(v, vetorToken[stack_pos]);
            int id_pos = stack_pos + 1;

            if (isID(vetorToken[id_pos]))
            {

                printf("Variavel valida %s do tipo %s \n", vetorToken[id_pos].palavra, vetorToken[stack_pos].palavra);
                v = push(v, vetorToken[id_pos]);
            }
            else
            {

                printf("%d ", vetorToken[stack_pos].tip);
                printf("%d ", vetorToken[id_pos].tip);
                printf("ERRO SINTATICO: DECLARACAO SEM IDENTIFICADOR");
                return -1;
            }
        }

        stack_pos++;
    }

    // VERIFICAR VARIAVEL REPETIDA

    return stack_pos;
}

int start()
{

    for (int i = 0; i < vetor_token_pos; i++)
    {
        if (vetorToken[i].tip == VAR)
        {
            i = var(i);

            if (i == -1)
            {
                return -1;
            }
        }
    }
}

void stackAnasint(Token t)
{
    vetorToken[vetor_token_pos] = t;
    vetor_token_pos++;
}

int anasint()
{
    printf("Mostrando o resultado dos tokens do analisador lexico.\n");
    for (int i = 0; i < vetor_token_pos; i++)
    {

        if (vetorToken[i].tip == REAL)
        {
            printf("%d ", i);
            printf("%f ", vetorToken[i].real);
            printf("%d\n", vetorToken[i].tip);
        }

        else
        {
            printf("%d ", i);
            printf("%s ", vetorToken[i].palavra);
            printf("%d\n", vetorToken[i].tip);
        }
    }

    start();

    return 1;
}
