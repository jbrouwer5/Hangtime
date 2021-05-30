#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

board* board_new(unsigned int width, unsigned int height, enum type type)
{
    board *new_board = (board*)malloc(sizeof(board)); 

    new_board->width = width; 
    new_board->height = height; 
    new_board->type = type; 

    if (type == MATRIX) 
    {
        enum cell** new_matrix;
        new_matrix = (cell**)malloc(sizeof(cell*) * height); 

        for (int j = 0; j < height; j++)
        {
            new_matrix[j] = (cell*)malloc(sizeof(cell) * width); 

            for (int i = 0; i < width; i++)
            {
                new_matrix[j][i] = EMPTY; 
            }
        }

        new_board->u.matrix = new_matrix; 
    }
    else
    {
        fprintf(stderr, "board_new : Bits not implemented yet\n");
        exit(1); 
    }

    return new_board; 
}

void board_free(board* b)
{
    if (b->type == MATRIX)
    {
        for (int j = 0; j < b->height; j++)
        {
            free(b->u.matrix[j]); 
        }

        free(b->u.matrix); 
        free(b); 
    }
    else
    {
        fprintf(stderr, "board_free : Bits not supported\n"); 
    }
}

void print_header(int val)
{
    if (val < 10)
    {
        printf("%d", val); 
    }
    else if (10 <= val && val < 36)
    {
        char c = val + 55; 
        printf("%c", c); 
    }
    else if (36 <= val && val < 62)
    {
        char c = val + 61; 
        printf("%c", c); 
    }
    else
    {
        printf("?"); 
    }
}

void show_col_heads(int width)
{
    printf("  "); 

    for (int j = 0; j < width; j++)
    {
        print_header(j); 
    }

    printf("\n\n");
}

void board_show(board* b)
{
    show_col_heads(b->width); 

    for (int j = 0; j < b->height; j++)
    {
        print_header(j); 
        printf(" ");

        for (int i = 0; i < b->width; i++)
        {
            if (b->u.matrix[j][i] == EMPTY)
            {
                printf(".");  
            }
            else if (b->u.matrix[j][i] == BLACK)
            {
                printf("*"); 
            }
            else
            {
                printf("o"); 
            }
        }

        printf("\n"); 
    }
}

cell board_get(board* b, pos p)
{
    if (b->width <= p.c || b->height <= p.r)
    {
        fprintf(stderr, "board_get : position is out of bounds.\n");
        exit(1); 
    }

    cell c = b->u.matrix[p.r][p.c]; 

    return c;
}

void board_set(board* b, pos p, cell c)
{
    if (b->width <= p.c || b->height <= p.r)
    {
        fprintf(stderr, "board_set : position is out of bounds.\n");
        exit(1); 
    }

    b->u.matrix[p.r][p.c] = c; 
}

