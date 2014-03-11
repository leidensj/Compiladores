
#define SYMBOL_ID 1
#define SYMBOL_INTEGER_LIT 2


typedef struct hash_node {

	char* text;
	int type;
	struct hash_node *next;
} HASH_NODE;

#define HASH_SIZE 997 // tem que ser primo

HASH_NODE* Table[HASH_SIZE];
void hashInit(void);
int hashAddress(char *text);
int Address;
HASH_NODE *hashInsert(char *text, int type);
HASH_NODE *hashFind(char *text);