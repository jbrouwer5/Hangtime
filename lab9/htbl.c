#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

unsigned long int good_hash(char *s)
{
    unsigned long int result = 17; 

    for (int j = 0; j < strlen(s); j++)
    {
        result = result * 37 + s[j]; 
    }

    return result; 
}

unsigned long int bad_hash(char *s)
{
    unsigned long int result = 10; 

    if (strlen(s) > 0)
    {
        result += s[strlen(s) - 1];  
    }
    
    return result; 
}

htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
    htbl *new_htbl = (htbl*)malloc(sizeof(htbl)); 
    if (new_htbl == NULL)
    {
        fprintf(stderr, "htbl_new: malloc failed\n"); 
        exit(1);
    }

    new_htbl->hash = h; 
    new_htbl->n_buckets = sz; 
    new_htbl->buckets = (bucket**)malloc(sizeof(bucket*) * sz);
    if (new_htbl->buckets == NULL)
    {
        fprintf(stderr, "htbl_new: malloc failed\n"); 
        exit(1);
    }

    for (int j = 0; j < sz; j++)
    {
        new_htbl->buckets[j] = NULL;
    } 

    return new_htbl; 
}

unsigned int htbl_n_entries(htbl *t)
{
    unsigned int count = 0; 

    for (int j = 0; j < t->n_buckets; j++)
    {
        count += bucket_size(t->buckets[j]); 
    }

    return count; 
}

double htbl_load_factor(htbl *t)
{
    double avg = htbl_n_entries(t);

    avg = avg / (double) t->n_buckets;  

    return avg; 
}

unsigned int htbl_max_bucket(htbl *t)
{
    unsigned int max = 0; 

    for (int j = 0; j < t->n_buckets; j++)
    {
        if (bucket_size(t->buckets[j]) > max)
        {
            max = bucket_size(t->buckets[j]); 
        }
    }

    return max; 
}

void htbl_insert(char *s, htbl *t)
{
    unsigned int hash_res = t->hash(s) % t->n_buckets; 
    if (t->buckets[hash_res] == NULL)
    {
        t->buckets[hash_res] = bucket_cons(s, t->hash(s), NULL);
    }
    else
    {
        bucket *holder = t->buckets[hash_res]; 

        while (holder->next != NULL)
        {
            holder = holder->next; 
        }

        holder->next = bucket_cons(s, t->hash(s), NULL);
    }
}

int htbl_member(char *s, htbl *t)
{
    unsigned long int hash_res = t->hash(s); 

    for (int j = 0; j < t->n_buckets; j++)
    {
        bucket *holder = t->buckets[j];
        while (holder != NULL)
        {
            if (holder->hash == hash_res)
            {
                if (!strcmp(holder->string, s))
                {
                    return 1; 
                }
            }

            holder = holder->next;
        }
    }

    return 0; 
}

void htbl_show(htbl *t)
{
    for (int j = 0; j < t->n_buckets; j++)
    {
        fprintf(stdout, "\n%d | ", j); 
        bucket_show(t->buckets[j]); 
    }
}

void htbl_free(htbl *t)
{
    free(t->buckets);

    for (int j = 0; j < t->n_buckets; j++)
    {
        if (t->buckets[j] != NULL)
        {
            bucket_free(t->buckets[j]); 
        }
    }

    free(t);
}
