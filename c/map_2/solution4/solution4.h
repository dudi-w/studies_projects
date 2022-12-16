#define HASHSIZE 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* nlist:  From K&R2 page 144.  Points to a search text and a replacement text */
static struct nlist *hashtab[HASHSIZE];

struct nlist
{
	struct nlist *next;
	char *name;
	char *value;
};
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *value);
unsigned hash(char *s);
char *strduplicat(char *s);
struct nlist *lookupPrev(char *s);
void undef(char *name);
void printHash();