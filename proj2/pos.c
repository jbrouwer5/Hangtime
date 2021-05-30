#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pos.h"

pos make_pos(unsigned int r, unsigned int c)
{
    if (r < 0 || c < 0)
    {
        fprintf(stderr, "make_pos: Inputs must be positive.\n"); 
        exit(1); 
    }

    pos p;
    p.r = r;
    p.c = c;

    return p; 
}

posqueue* posqueue_new()
{
    posqueue *posq = (posqueue*)malloc(sizeof(posqueue)); 

    if (posq == NULL)
    {
        fprintf(stderr, "posqueue_new: Malloc failed\n"); 
        exit(1);
    }

    posq->len = 0; 
    posq->head = NULL;
    posq->tail = NULL;

    return posq; 
}

void posqueue_free(posqueue* q)
{
    while ((q->head != q->tail) && q->head != NULL && q->tail != NULL)
    {
        pq_entry *temp = q->head->next; 
        free(q->head); 
        q->head = temp; 
    }

    if (q->head != NULL)
    {
        free(q->head); 
    }

    free(q); 
}

void pos_enqueue(posqueue* q, pos p)
{
    pq_entry *new = (pq_entry*)malloc(sizeof(pq_entry));
    if (new == NULL)
    {
        fprintf(stderr, "posq_enqueue: Malloc failed\n"); 
        exit(1);
    }

    q->len++; 
    new->p = p; 

    if(q->len == 1)
    {
        q->head = new;  
        return; 
    }

    if(q->len == 2)
    {
        q->tail = new; 
        q->head->next = new; 
        return;
    }

    
    q->tail->next = new; 
    q->tail = q->tail->next; 
}

pos pos_dequeue(posqueue* q)
{
    if (q->len == 0)
    {
        fprintf(stderr, "posq_dequeue: Given an empty list\n"); 
        exit(1);
    }

    pos popped = q->head->p; 
    pq_entry *temp = q->head; 
    q->head = q->head->next; 
    free(temp); 
    q->len--; 

    return popped; 
}

bool pos_equals(pos a, pos b)
{
    if (a.c == b.c && a.r == b.r)
    {
        return true; 
    }
    
    return false;  
}

bool posqueue_member(posqueue* q, pos p)
{
    pq_entry *holder = q->head; 
    while (holder != NULL)
    {
        if (pos_equals(holder->p, p))
        {
            return true; 
        }

        holder = holder->next; 
    }

    return false; 
}


