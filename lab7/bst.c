#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst *bst_singleton(vcard *c)
{
    bst *new_bst = (bst*)malloc(sizeof(bst)); 

    new_bst->c = c; 
    new_bst->left = NULL;
    new_bst->right = NULL; 

    return new_bst;
}

int bst_insert(bst *t, vcard *c)
{
    int count = 0; 

    if (t == NULL)
    {
        fprintf(stderr, "bst_insert: Given an empty bst\n"); 
    }

    if (strcmp(c->cnet, t->c->cnet) < 0)
    {
        if (t->left == NULL)
        {
            t->left = bst_singleton(c); 
            count++;   
        }
        
        return count + bst_insert(t->left, c); 
    }

    if (strcmp(c->cnet, t->c->cnet) > 0)
    {
        if (t->right == NULL)
        {
            t->right = bst_singleton(c);  
            count++;  
        }
        
        return count + bst_insert(t->right, c); 
    }
    
    return 0; 
}

unsigned int bst_num_entries(bst *t)
{ 
    if (t == NULL)
    {
        return 0; 
    }

    int count = 1 + bst_num_entries(t->left) + bst_num_entries(t->right); 
    return count; 
}

unsigned int bst_height(bst *t)
{
    if (t == NULL)
    {
        return 0; 
    }

    if (t->left == NULL && t->right == NULL)
    {
        return 1;  
    }

    if (bst_height(t->left) > bst_height(t->right))
    {
        return 1 + bst_height(t->left);
    } 

    return 1 + bst_height(t->right); 
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
    if (t == NULL)
    {
        return NULL; 
    }

    int comp = strcmp(cnet, t->c->cnet); 
    *n_comparisons = *n_comparisons + 1; 

    if (!comp)
    { 
        return t->c; 
    }

    if (comp < 0)
    {
        return bst_search(t->left, cnet, n_comparisons); 
    }

    return bst_search(t->right, cnet, n_comparisons); 
}

/* note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
unsigned int bst_c(FILE *f, bst *t, char c)
{
    int count = 0; 

    if (t == NULL)
    {
        return count; 
    }

    if (t->c->cnet[0] == c)
    {
        fprintf(f, "%s\n", t->c->cnet); 
        count++; 
    }

    if (t->c->cnet[0] == c || t->c->cnet[0] >= c)
    {
        count += bst_c(f, t->left, c); 
    }

    if (t->c->cnet[0] == c || t->c->cnet[0] <= c)
    {
        count += bst_c(f, t->right, c); 
    }

    return count; 
}

void bst_free(bst *t)
{
    if (t == NULL)
    { 
        return; 
    }

    bst_free(t->left); 
    bst_free(t->right);
    vcard_free(t->c); 
    free(t); 
}

