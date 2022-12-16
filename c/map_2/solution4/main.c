#include "solution4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //static struct nlist *hashtab[HASHSIZE];
    /*struct nlist qq;
    qq.name= "qwer";
    qq.value="22";
    hashtab[8]= &qq;
    for(int i =0 ; i<HASHSIZE ; ++i){
        struct nlist *np;
        printf("%p->\n", hashtab[i]);
        for(np = hashtab[i]; np!=NULL ; np= np->next){
            printf("name= %s, value = %s\n" , np->name , np->value);
        }
    }
*/  
    printHash();
    install("dudi" , "12");
    install("yoyo" , "33");
    install("yosi" , "33");
    install("yoryo" , "334");
    install("11yoyo" , "3");
    install("22yoyo" , "32");
    printHash();
    printf("%p\n",lookup("dudi"));
    undef("dudi");
    printf("%p\n",lookup("dudi"));
    lookup("dfd");
    return 0;
}
