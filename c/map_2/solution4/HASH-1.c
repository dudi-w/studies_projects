#include "solution4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* lookup:  Look for s in hashtab.*/
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

/* install:From K&R2 page 145. Put (name, value) in hashtab. */
struct nlist *install(char *name, char *value)
{
	struct nlist *np;
	unsigned hashval;
	
	if((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = strduplicat(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
		printf("%s\t%d\n", hashtab[hashval]->name , hashval);
	}
	else
		free((void *) np->value);

	if((np->value = strduplicat(value)) == NULL)
		return NULL;
	return np;
}

/* hash: From K&R2 page 144.  Form hash value for string s. */
unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* strduplicat: From K&R2 page 143. Makes a duplicate of s. */
char *strduplicat(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}
struct nlist *lookupPrev(char *s){
		struct nlist *npp;
		for(npp = hashtab[hash(s)]; npp->next != NULL; npp = npp->next)
			if(strcmp(s, npp->next->name) == 0){
				printf("efefrf");
				return npp;
			}
		printf("45454\n");
		return NULL;
	}
/*remove a name and definition from the table*/
void undef(char *name){
	struct nlist *np , *npp;
	if(name==NULL || (np=lookup(name))==NULL){
		printf("The input value does not exist\n");
		return;
	}
	free(np->value);
	free(np->name);
	if((npp= lookupPrev(name))==NULL)
		hashtab[hash(name)]= np->next;
	else
		npp->next = np->next;
	free(np);
	printf("The input value is deleted from the hashtable\n");
}
void printHash(){
	 for(int i =0 ; i<HASHSIZE ; ++i){
        struct nlist *np;
        printf("%p->\t i=%d\n", hashtab[i] , i);
        for(np = hashtab[i]; np!=NULL ; np= np->next)
            printf("name= %s, value = %s\n" , np->name , np->value);

	 }
}