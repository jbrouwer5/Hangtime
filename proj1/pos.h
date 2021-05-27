#ifndef POS_H
#define POS_H

#include <stdbool.h>

struct pos {
    unsigned int r, c;
};

typedef struct pos pos;


typedef struct pq_entry pq_entry;

struct pq_entry {
    pos p;
    pq_entry* next;
};


struct posqueue {
    pq_entry *head, *tail;
    unsigned int len; 
};

typedef struct posqueue posqueue;

/* This function takes two integers and returns a pos struct representing the 
point (r, c) */
pos make_pos(unsigned int r, unsigned int c);

/* Allocates memory for a new empty queue */
posqueue* posqueue_new();

/* Adds a position to the back of the queue. */
void pos_enqueue(posqueue* q, pos p);

/* Removes and returns the element at the front of the queue or raises
an error if given an empty queue. */ 
pos pos_dequeue(posqueue* q);

/* Determines if the given pos is in the queue. */ 
bool posqueue_member(posqueue* q, pos p);

/* Entirely deallocates an existing queue. */
void posqueue_free(posqueue* q);

#endif /* POS_H */
