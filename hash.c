#include "hash.h"
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
		
		for (i=0; i< HASH_SIZE; i++)
			addr = (addr*text[i]) % HASH_SIZE+1;
	
		return addr-1;
	}
	
	
	HASH_NODE *hashInsert(char *text, int type)
	{

		HASH_NODE *newnode;
		Address = hashAddress(text);
		newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
	
		newnode->type = type;
		newnode->text = (char*) calloc(1,sizeof(strlen(text)+1));
		strcpy(newnode->text,text);
	
		newnode->next = Table[Address];

		Table[Address] = newnode;
	
		return newnode;
	
	}
	
	
	HASH_NODE* hashFind(char *text)
	{
	
		HASH_NODE *pt;
		int addr = hashAddress(text);
		
		for(pt = Table[addr]; pt; pt = pt->next)
			if(!strcmp(pt->text, text))
				return pt;
			
		return 0;

	}
	
	void hashPrint()
	{
	
		int i;
		HASH_NODE *pt;
		
		for(i = 0; i< HASH_SIZE; i++)
			for(pt = Table[Address]; pt; pt = pt->next)
				printf("i = %d  type = %d text = %s \n", i, pt->type, pt->text);
	
	}