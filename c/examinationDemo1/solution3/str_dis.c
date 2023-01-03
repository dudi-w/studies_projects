#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(char **a, char **b)
{
	char *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArrString(char** arrString){
    for(int i=0;i<4;++i)
            printf("%s,\t", *((arrString)+i));
    printf("\n");
}

//look if char is in the string 
bool lookFor(char* str, char w, int buffer){
    for(int i=0; i<buffer;++i)
    {
        //printf("str[%d]: %c?=?%c\n",i, str[i] ,w);
        if(str[i]==w)
            return true;
    }
    return false;
}

//get a string and returns a string with its unique char
char* uniqChar(char *str){
    int i=0;
    int j=0;
    char* new_str = (char*)malloc(sizeof(str));
    if(new_str==NULL)
        exit(0);

    while ( str[i]!='\0')
    {
        if(!lookFor(new_str, str[i], strlen(new_str)))
            new_str[j++]= str[i];
        ++i;
    }
    new_str[j]='\0';
    //printf("%s\n", new_str);
    return new_str;    
}

int scor(char *word , char* str)
{   
    char *uniqWord = word;//uniqChar(word);
    int size =strlen(uniqWord);
    int cout=0;
    for(int i=0 ; i< size;++i){
        for(int j=0 ; j< strlen(str);++j){
            if(uniqWord[i]==str[j]){
                //printf("word[%c]==str[%c]\n", uniqWord[i], str[j]);
                ++cout;
                break;
            }
        }
    }
    //free(uniqWord);
    return size - cout;
}
void sortSringsByMatch(char** arr ,int arrSize , char * word){
    char* uniqWord= uniqChar(word);
    int size= strlen(uniqWord);
    int buffer =0;
    for(int i= 0; i< size; ++i){
        for(int j=0;j<arrSize;++j){
            if(scor(uniqWord, *((arr)+j))==i){
                swap(&(*(arr+j)), &(*(arr+buffer++)));
                //printf("buffer= %d\n", buffer);
            }
        }
        //printf("i");
    }
    free(uniqWord);
}