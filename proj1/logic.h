#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>
#include "board.h"


enum turn {
    BLACKS_TURN,
    WHITES_TURN
};

typedef enum turn turn;


enum outcome {
    IN_PROGRESS,
    BLACK_WIN,
    WHITE_WIN,
    DRAW
};

typedef enum outcome outcome;


struct game {
    unsigned int run, hangtime;
    board* b;
    posqueue* hanging;
    turn player;
};

typedef struct game game;

/* Creates a new game with the specified size and rules. */ 
game* new_game(unsigned int run, unsigned int hangtime, unsigned int width,
               unsigned int height, enum type type);

/* Frees the entirety of a given game. */
void game_free(game* g);

/* Places a piece for the specified player at position p. If the position is 
full it returns false. If the position is empty then adds the piece, simulates
the change in gravity for that return, changes the turn and returns true. */
bool place_piece(game* g, pos p);

/* Reports the outcome of the game, or returns in progress */
outcome game_outcome(game* g);

#endif /* LOGIC_H */
