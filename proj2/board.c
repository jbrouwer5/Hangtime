#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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
        unsigned int* new_bits;  
         
        int length = ceil(width * height / 16); 

         new_bits = (unsigned int*)malloc(sizeof(unsigned int) * length); 
         
         for (int j = 0; j < length; j++)
         {
             new_bits[j] = 0; 
         }

         new_board->u.bits = new_bits;
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
    }
    else
    {
        free(b->u.bits); 
    }

    free(b); 
}

// prints the corresponding header value for row or column j 
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

// prints the column headers for a board 
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
            if (board_get(b, make_pos(j,i)) == EMPTY)
            {
                printf(".");  
            }
            else if (board_get(b, make_pos(j,i)) == BLACK)
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

    if (b->type == MATRIX)
    {
        cell c = b->u.matrix[p.r][p.c]; 
        return c;
    }
    else
    {
        int tot = p.r * b->width + p.c;
        int index = tot / 16; 
        int magnitude = tot % 16 * 2; 
        unsigned int compare = pow(2, magnitude) + pow(2, magnitude + 1); 
        unsigned int result = b->u.bits[index] & compare; 
        result = result >> magnitude; 
        if (result == 0)
        {
            return EMPTY; 
        }
        else if (result == 1)
        {
            return BLACK; 
        }
        else
        {
            return WHITE; 
        }
    }
}

void board_set(board* b, pos p, cell c)
{
    if (b->width <= p.c || b->height <= p.r)
    {
        fprintf(stderr, "board_set : position is out of bounds.\n");
        exit(1); 
    }

    if (b->type == MATRIX)
    {
        b->u.matrix[p.r][p.c] = c; 
    }
    else
    {
        int tot = p.r * b->width + p.c;
        int index = tot / 16; 
        int magnitude = tot % 16 * 2; 
        unsigned int new; 
        if (c == EMPTY)
        {
            new = 3; 
            new = new << magnitude; 
            new = ~new; 
            b->u.bits[index] = b->u.bits[index] & new; 
        }
        else if (c == BLACK)
        {
            new = 1; 
            new = new << magnitude;  
            b->u.bits[index] = b->u.bits[index] | new; 
            new = 1; 
            new = new << (magnitude + 1);
            new = ~new; 
            b->u.bits[index] = b->u.bits[index] & new; 
        }
        else
        {
            new = 1; 
            new = new << (magnitude + 1);  
            b->u.bits[index] = b->u.bits[index] | new; 
            new = 1; 
            new = new << magnitude;
            new = ~new; 
            b->u.bits[index] = b->u.bits[index] & new; 
        }
    }
}

