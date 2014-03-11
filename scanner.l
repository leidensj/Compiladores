
%{ 


int lineNumber = 0;
int running = 1;


#include "hash.h"
#include "tokens.h"


%}

DIGIT 			[0-9]

%x COMM 

INTEGER		[0-9]
CHAR		[a-zA-Z_]
SPECIAL		[,;:(){}\[\]{}\+\-\*<>=!&$\/]

%%



"word"								return KW_WORD;
"bool"								return KW_BOOL;
"byte"								return KW_BYTE;
"if"								return KW_IF;
"then"								return KW_THEN;
"else"								return KW_ELSE;
"loop"								return KW_LOOP;
"input"								return KW_INPUT;
"return"							return KW_RETURN;
"output"							return KW_OUTPUT;


"<="								return OPERATOR_LE;   
">="								return OPERATOR_GE;   
"=="								return OPERATOR_EQ;   
"!="								return OPERATOR_NE;  
"&&"								return OPERATOR_AND;  
"||"								return OPERATOR_OR;   


"false"								{ hash_insert(yytext, LIT_FALSE); return LIT_FALSE; }
"true"								{ hash_insert(yytext, LIT_TRUE); return LIT_TRUE; }



{CHAR}({CHAR}|{INTEGER})*			{ hash_insert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER; }
{INTEGER}+							{ hash_insert(yytext, LIT_INTEGER); return LIT_INTEGER; }








[DIGIT]+						{hashInsert(yytext, SYMBOL_INTEGER_LIT); return SYMBOL_INTEGER_LIT;}//{printf("achei um numero, lexema  %s\n", yytext);}
[0-9]+" " 						//{printf("achei um numero terminado por espaço, lexema %s\n", yytext);}
.			        			//return 7;//{printf("Oooops alguma coisa estranha...");}   // qualquer coisa menos \n : nao faz nada
"\n"							{/*printf("nova linha \n");*/ ++ lineNumber;}


[a-zA-Z_][a-zA-Z_0-9]*			{hashInsert(yytext, SYMBOL_ID); return SYMBOL_ID;};//{printf("identificador\n");}
"//".*							

"/*"							{ BEGIN(COMM);}
<COMM>"*/"						{ BEGIN(INITIAL);}
<COMM>"\n"						{ ++lineNumber; }
<COMM>.


%%


yywrap()
{
	running = 0;
	return 1; 
}