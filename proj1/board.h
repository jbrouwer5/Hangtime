#ifndef BOARD_H
#define BOARD_H

#include "pos.h"


enum cell {
    EMPTY,
    BLACK,
    WHITE
};

typedef enum cell cell;


union board_rep {
    enum cell** matrix;
    unsigned int* bits;
};

typedef union board_rep board_rep;
 
enum type {
    MATRIX, BITS
};


struct board {
    unsigned int width, height;
    enum type type;
    board_rep u; 
};

typedef struct board board;

/* Creates an empty board with the given dimensions and given type */
board* board_new(unsigned int width, unsigned int height, enum type type);

/* Fully frees a board, including whatever representation it is using */ 
void board_free(board* b);

/* Prints the board to the screen along with row and column headers. */ 
void board_show(board* b);

/* Retrieves the value at position p on board b. Raises an error if the position
does not exist. */ 
cell board_get(board* b, pos p);

/* Sets the value at position p on board b to the given cell c. If out of bounds 
raises an error. */ 
void board_set(board* b, pos p, cell c);

#endif /* BOARD_H */
