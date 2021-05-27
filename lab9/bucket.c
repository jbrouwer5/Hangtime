#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

bucket *bucket_cons(char *s, unsigned long int hash, bucket *b)
{
    bucket *new_bucket = (bucket*)malloc(sizeof(bucket)); 
    char *str = (char*)malloc(sizeof(char) * strlen(s)); 

    for (int j = 0; j < strlen(s); j++)
    {
        str[j] = s[j]; 
    }

    new_bucket->string = str; 
    new_bucket->hash = hash; 
    new_bucket->next = b; 

    return new_bucket; 
}

unsigned int bucket_size(bucket *b)
{
    int count = 0; 

    while (b != NULL)
    {
        count++; 
        b = b->next; 
    }

    return count; 
}

void bucket_show(bucket *b)
{
    while (b != NULL)
    {
        fprintf(stdout, "%s", b->string); 
        if (b->next != NULL)
        {
            fprintf(stdout, " -> "); 
        }

        b = b->next; 
    }
}

void bucket_free(bucket *b)
{
    while (b != NULL)
    {
        free(b->string);
        bucket *temp = b->next; 
        free(b);  
        b = temp; 
    }
}

