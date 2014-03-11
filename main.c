#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "tokens.h"

int yylex();
extern FILE * yyin;
extern int running;
extern int lineNumber;

main(int a, char **b)
{


int token = 0;
hashInit();

yyin = fopen("teste.lin","r");


while(running)
{	
	
	token = yylex(); //chamada do lex

	if(!running) break;

	switch(token)
	{
		case KW_IF:						printf ("palavra reservada IF \n"); break;
		case TK_IDENTIFIER:				printf("identificador\n"); break; 
		//case SYMBOL_OPEN_BRACKET:		printf(); break;
		//case SYMBOL_CLOSE_BRACKET:	printf(); break;
		//case SYMBOL_SEMICOLON:		printf(); break;
		case LIT_INTEGER:				printf("forma literal inteira\n"); break;
		case 7:	printf("7\n"); break;
	}
// geralmente como codigo para os simbolos se usa os proprios codigos ASCII
// dai identificamos apenas as coisas mais estranhas com define.
// entao coisas de um caractere só não possuem "nome"
// PS: tomar cuidade para nao redefinir um cosigo ASCII

	printf("Esse treco tinha %d linhas", lineNumber);

}
}
