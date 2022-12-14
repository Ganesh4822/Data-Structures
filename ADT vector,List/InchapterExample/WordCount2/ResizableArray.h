#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct structWord
{
    char* word;
    size_t line_number;
    size_t word_number;
}structWord;

typedef struct vector
{
    structWord** pp;
    size_t size;
}vector;

vector* createVector()
{
    vector* WordVec = (vector*)malloc(sizeof(vector));
    WordVec->pp = NULL;
    WordVec->size = 0;

    return WordVec;
}


void DestroyVector(vector* vecobj)
{
    size_t i =0 ;
    for(i = 0 ; i < vecobj->size ; i++)
    {
        free(vecobj->pp[i]->word);
        free(vecobj->pp[i]);
    }
    free(vecobj->pp);
    free(vecobj);
    vecobj= NULL;
}

void pushBack(vector* vec, structWord* obj)
{
    vec->pp = (structWord**)realloc(vec->pp,(vec->size + 1) * sizeof(structWord*));

    if(vec->pp == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    vec->size = vec->size + 1;
    vec->pp[vec->size - 1] = obj;
}


size_t searchWordcount(vector* vec , char* word)
{
    int i;
    size_t count = 0;
    for(i = vec->size - 1 ; i >= 0 ; i--)
    {
        if(strcmp(vec->pp[i]->word,word) == 0)
            return vec->pp[i]->word_number;
    }

    return 0;
}

size_t searchWord(vector* vec , char* word)
{
    size_t i ;
    size_t count = 0;

    for(i = 0 ; i < vec->size ; i++)
    {
        if(strcmp(vec->pp[i]->word, word) == 0)
            count++;
    }
    return count;
}
void pushBackVersionV2(vector* vec, char* word, int LineNumber)
{
    structWord* wordv = (structWord*)malloc(sizeof(structWord));
    if(wordv == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory:pushBackV2\n"); 
        exit(EXIT_FAILURE); 
    }

    wordv->word = (char*)malloc(strlen(word));
    if(wordv->word == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory:pushBackV2\n"); 
        exit(EXIT_FAILURE); 
    }
    
    strcpy(wordv->word ,word);
    //A more efficient algorithm can be implementated for this by getting the latest word number and
    //Incrementing it by one for the latest word
    size_t count = searchWordcount(vec,word);

    wordv->word_number = count+1;
    wordv->line_number = LineNumber;

    vec->pp = (structWord**)realloc(vec->pp,(vec->size + 1) * sizeof(structWord*));

    if(vec->pp == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    vec->size = vec->size++;
    vec->pp[vec->size - 1] = wordv;

}

void ShowVector(vector* vec)
{
    size_t i ;

    for(i = 0 ; i < vec->size ; i++)
    {
        printf("Pvector->arr[%zu] = %s , wordNUmber = %zu , LineNumber = %zu\n",
        i,vec->pp[i]->word,vec->pp[i]->word_number,vec->pp[i]->line_number);
    }
}



