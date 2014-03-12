#include "hash.h"
#include "tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hashInit(void)
{
	int i;
	for (i = 0; i < HASH_SIZE; i++)
		Table[i] = 0;
}
	
	
int hashAddress(char *text)
{
	int addr = 1;
	int i;
	
	for (i=0; i<strlen(text); i++)
		addr = (addr*text[i]) % HASH_SIZE + 1;
	return addr - 1;
}
	
	
HASH_NODE *hashInsert(char *text, int type)
{
	HASH_NODE *newnode;
	newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));

	newnode->type = type;
	if(newnode->type == LIT_CHAR || newnode->type == LIT_STRING)
	{
		/* Procedimento para cortar as aspas na hora de inserir na tabela                 *
		 * exemplo: "minha string" eh inserido como minha string | 'a' eh inserido como a */
		newnode->text = (char*) calloc(1, sizeof(strlen(text) + -1)); //+1 para termino de string -2 para descontar as aspas resulta em -1
		strncpy(newnode->text, text+1, strlen(text)-2); //text+1 -> ignora primeira aspa, tamanho eh descontado em 2 para ignorar a ultima aspa
	}
	else
	{
		newnode->text = (char*) calloc(1, sizeof(strlen(text) + 1));
		strcpy(newnode->text,text);
	}

	if(!hashFind(newnode->text, newnode->type))
	{
		//se a palavra ainda nao constava na tabela eh inserida
		int address = hashAddress(newnode->text);
		newnode->next = Table[address];
		Table[address] = newnode;
		return newnode;
	}
	else
	{
		//nao precisa incluir na tabela
		free(newnode); //libera a memoria, nao vai ser necessaria
		return NULL;
	}	
}
	
	
HASH_NODE* hashFind(char *text, int type)
{
	//verifica se o CONTEUDO e o TIPO sao iguais
	HASH_NODE *pt;
	int addr = hashAddress(text);
	
	for(pt = Table[addr]; pt; pt = pt->next)
		if(!strcmp(pt->text, text) && pt->type == type)
			return pt;
		
	return NULL;
}
	
void hashPrint()
{
	int i;
	HASH_NODE *pt;
	
	for(i = 0; i< HASH_SIZE; i++)
		for(pt = Table[i]; pt; pt = pt->next)
			printf("i = %d  type = %d text = %s \n", i, pt->type, pt->text);

}
