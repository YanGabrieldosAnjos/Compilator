#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum Tipo{BOOL=0,CHAR,ELSE,ENDFOR,ENDIF,ENDPROG,ENDWHILE,FOR,IF,INT,PROG,REAL,STRING,WHILE,//reservados,ler referencia dnv
                       VIRGULA,PVIRGULA,MENOR,MENORIGUAL,MAIOR,MAIORIGUAL,ATRIB,IGUALDADE,hashtag,ID,SOMA,SUB,MULTI,DIV}tipo;//simbolos
char reservadas[14][10]={"bool","char","else","endfor","endif","endprog","endwhile","for","if","int","prog","real","string","while"};
typedef struct{
    tipo tip;
     union{
        int inteiro;
        float real;
        char  caracter;
        char palavra[10];
        char reservada[10];
    }
}Token;
int finder(char *buffer){
    char reservadas[14][10]={"bool","char","else","endfor","endif","endprog","endwhile","for","if","int","prog","real","string","while"};
     int Tam=14;
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (strcmp(reservadas[meio],buffer)==0)
               return meio;
          if (strcmp(reservadas[meio],buffer)>0)
               sup = meio-1;
          else
               inf = meio+1;
     }
     printf("aqui func %s\n",reservadas[meio]);
     return -1;   // não encontrado
}
/*globais*/
int estado=0;
Token t;
char buffer[10];
int i=0;
/*fim globais*/
void analex(char c,FILE *fp){
    switch(estado){
        //estado inicial;
            case 0:
                if(isalpha(c)){
                    buffer[i]=c;
                    i++;
                    estado=1;
                }else if(c=='<'){
                    printf("oi");
                    buffer[i]=c;
                    i++;
                    estado=2;
                }else if(c=='>'){
                    buffer[i]=c;
                    i++;
                    estado =4;
                }else if(c=='='){
                    buffer[i]=c;
                    i++;
                    estado=9;
                }else if(isdigit(c)){
                    printf("cu0");
                    buffer[i]=c;
                    i++;
                    estado=13;
                }else if(c=='\''){
                    buffer[i]=c;
                    i++;
                    estado=15;
                }else if(c=='\"'){
                    buffer[i]=c;
                    i++;
                    estado=17;
                }else if(c=='+'){
                    buffer[i]=c;
                    i++;
                    estado=19;
                }else if(c=='/'){
                    buffer[i]=c;
                    i++;
                    estado=20;
                }else if(c=='-'){
                    buffer[i]=c;
                    i++;
                    estado=21;
                }else if(c=='*'){
                    buffer[i]=c;
                    i++;
                    estado=22;
                }else if(c=='#'){
                    buffer[i]=c;
                    i++;
                    estado=27;
                }else if(c=='|'){
                    buffer[i]=c;
                    i++;
                    estado=29;
                }else if(c=='.'){
                    buffer[i]=c;
                    i++;
                    estado=35;
                }else if(c=='('){
                    buffer[i]=c;
                    i++;
                    estado=44;
                }else if(c==')'){
                    buffer[i]=c;
                    i++;
                    estado=49;
                }else if(c==','){
                    buffer[i]=c;
                    i++;
                    estado=51;
                }else if(c==';'){
                    buffer[i]=c;
                    i++;
                    estado=53;
                }
            break;
            case 1:
                if(isalpha(c)||isdigit(c)){
                    buffer[i]=c;
                    i++;
                }else{

                    buffer[i]=0;
                    estado=3;
                }
            break;
            case 3:
                t.tip=finder(buffer);
                if(t.tip==-1){
                    t.tip=ID;
                }
                strcpy(t.reservada,buffer);
                strcpy(buffer,"");
                i=0;
                estado=0;
                printf("%s\n",t.reservada);
                printf("%d\n",t.tip);
                //return t;
            break;
           case 2:
                if(c=='='){
                    buffer[i]=c;
                    i++;
                    printf("oi2\n");
                    estado=8;
                }else{
                    estado=7;
                }
           break;
           case 7:
                buffer[i]=0;
                t.tip=MENOR;
                strcpy(t.palavra,buffer);
                strcpy(buffer,"");
                printf("%d\n",t.tip);
                printf("%s\n",t.palavra);
                i=0;
                estado=0;

          break;
          case 8:
                buffer[i]=0;
                t.tip=MENORIGUAL;
                strcpy(t.palavra,buffer);
                strcpy(buffer,"");
                printf("%d\n",t.tip);
                printf("%s\n",t.palavra);
                i=0;
                estado=0;
          break;
          case 4:
               if(c=='='){
                  buffer[i]=c;
                  i++;
                  estado=5;
               }else{
                   estado=6;
               }
          break;
         case 5:
                buffer[i]=0;
                t.tip=MAIORIGUAL;
                strcpy(t.palavra,buffer);
                strcpy(buffer,"");
                printf("%d\n",t.tip);
                printf("%s\n",t.palavra);
                i=0;
                estado=0;
         break;
         case 6:
                buffer[i]=0;
                t.tip=MENOR;
                strcpy(t.palavra,buffer);
                strcpy(buffer,"");
                printf("%d\n",t.tip);
                printf("%s\n",t.palavra);
                i=0;
                estado=0;
        break;
        case 9:
                if(c=='='){
                    buffer[i]=c;
                    i++;
                    estado=11;
                }else{
                    estado=10;
                }
        break;
        case 11:
                buffer[i]=0;
                t.tip=IGUALDADE;
                strcpy(t.palavra,buffer);
                strcpy(buffer,"");
                printf("%d\n",t.tip);
                printf("%s\n",t.palavra);
                i=0;
                estado=0;
        break;
        case 10:
                buffer[i]=0;
                t.tip=ATRIB;
                strcpy(t.palavra,buffer);
                strcpy(buffer,"");
                printf("%d\n",t.tip);
                printf("%s\n",t.palavra);
                i=0;
                estado=0;
        break;
        case 13:
              if(isdigit(c)){
                printf("cu1");
                buffer[i]=c;
                //talvez não de pra gravar em um vetor
                i++;
              }else if(!(isdigit(c))&&!(c=='.')){
                printf("cu2");
                estado=12;
              }else if(c=='.'){
                buffer[i]=c;
                i++;
                estado=33;
              }
       break;
       case 12:
            t.tip=INT;
            t.inteiro=atoi(buffer);
            printf("cu");
            strcpy(buffer,"");
            i=0;
            estado=0;
       break;
       case 33:
            if(isdigit(c)){
                //talvez n de pra gravar em um vetor
                buffer[i]=c;
                i++;
            }else{
                estado=34;
            }
       break;
       case 34:
            buffer[i]=0;
            t.tip=REAL;
            t.real=atof(buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
       break;
       case 15:
            if(isalpha(c)||isdigit(c)){
                buffer[i]=c;
                i++;
                estado=14;
            }else{
                printf("erro lexico");
            }
       break;
       case 14:
            if(c=='\''){
               buffer[i]=c;
               i++;
               estado=16;
            }
       break;
       case 16:
            buffer[i]=0;
            t.tip=CHAR;
            t.caracter=buffer[1];
            strcpy(buffer,"");
            i=0;
            estado=0;
       break;
       case 17:
            if(isalpha(c)||isdigit(c)){
                buffer[i]=c;
                i++;
            }else{
                estado=18;
            }
       break;
       case 18:
            buffer[i]=0;
            t.tip=STRING;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;
      case 19:
            buffer[i]=c;
            estado=26;
      break;
      case 26:
            buffer[i]=0;
            t.tip=SOMA;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;
      case 21:
            buffer[i]=c;
            estado=25;
      break;
      case 25:
            buffer[i]=0;
            t.tip=SUB;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;
      case 20:
            buffer[i]=c;
            if(buffer[i]=='/'){
                estado=32;
            }
      break;
      case 24:
            buffer[i]=0;
            t.tip=DIV;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;

    //case 32:
      case 22:
            buffer[i]=c;
            estado=23;
      break;
      case 23:
            buffer[i]=0;
            t.tip=MULTI;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;
      case 53:
            buffer[i]=c;
            estado=54;
      break;
      case 54:
            buffer[i]=0;
            t.tip=PVIRGULA;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;
      case 51:
            buffer[i]=c;
            estado=23;
      break;
      case 52:
            buffer[i]=0;
            t.tip=VIRGULA;
            strcpy(t.palavra,buffer);
            strcpy(buffer,"");
            i=0;
            estado=0;
      break;


  }
}
