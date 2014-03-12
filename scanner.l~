
%{ //codigo em C, inserido no inicio


int lineNumber = 0;
int running = 1;


#include "hash.h"
#include "tokens.h"


%}

DIGIT 			[0-9]

%x COMM 

%%

"a" 	 						 //{printf("achei um a \n");}
[DIGIT]+						{hashInsert(yytext, SYMBOL_INTEGER_LIT); return SYMBOL_INTEGER_LIT;}//{printf("achei um numero, lexema  %s\n", yytext);}
[0-9]+" " 						//{printf("achei um numero terminado por espaço, lexema %s\n", yytext);}
.			        			//return 7;//{printf("Oooops alguma coisa estranha...");}   // qualquer coisa menos \n : nao faz nada
"\n"							{/*printf("nova linha \n");*/ ++ lineNumber;}



"if"							return KW_IF;//{printf("palavra reservada IF \n");}
[a-zA-Z_][a-zA-Z_0-9]*			{hashInsert(yytext, SYMBOL_ID); return SYMBOL_ID;};//{printf("identificador\n");}
"//".*							

"/*"							{ BEGIN(COMM);}
<COMM>"*/"						{ BEGIN(INITIAL);}
<COMM>"\n"						{ ++lineNumber; }
<COMM>.


%%
//codigo em C


//funcao chamada quando encontra final de arquivo, serve pra imendar em outro
yywrap()
{
running = 0;
return 1; // terminou a historia (se fosse 0 nao terminaria nunca)
}