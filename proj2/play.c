#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "pos.h"
#include "logic.h"

// takes the input from play and returns a pointer to a new game 
game* start_game (int argc, char* argv[])
{
    int w = 0;
    int h = 0; 
    int r = 0;
    int t = 0; 
    enum type typ; 
    int typ_found = 0; 

    for (int j = 1; j < argc; j++)
    {
        if (!strcmp(argv[j], "-w"))
        {
            w = atoi(argv[j+1]); 
        }
        else if (!strcmp(argv[j], "-h"))
        {
            h = atoi(argv[j+1]); 
        }
        else if (!strcmp(argv[j], "-r"))
        {
            r = atoi(argv[j+1]); 
        }
        else if (!strcmp(argv[j], "-t"))
        {
            t = atoi(argv[j+1]); 
        }
        else if (!strcmp(argv[j], "-b"))
        {
            typ = BITS; 
            typ_found = 1; 
        }
        else if (!strcmp(argv[j], "-m"))
        {
            typ = MATRIX; 
            typ_found = 1; 
        }
    }

    if (!((r && w && h && typ_found) && (r != 1)))
    {
        fprintf(stderr, "Not all inputs included\n"); 
        exit(1); 
    }

    game *n_game = new_game(r, t, w, h, typ); 

    return n_game; 
}

// takes a pointer to a game and prints whose turn it is
void print_turn(game* g)
{
    if (g->player == BLACKS_TURN)
    {
        printf("Black: \n\n"); 
    }        
    else
    {
        printf("White: \n\n");      
    }
}

// takes a char and returns the associated number value for col and row headers
char decode_ascii(char c)
{
    if (c < 58 && c >= 48)
    {
        return c - 48;  
    }
    else if (65 <= c && c < 91)
    {
        char val = c - 55;  
        c = val; 
        return c;  
    }
    else if (97 <= c && c < 123)
    {
        char val = c - 61;
        c = val; 
        return c;  
    }
    else 
    {
        return '.';
    }

}

// takes a pointer to a game and returns the outcome of the game 
int give_outcome(game* g)
{
    outcome result = game_outcome(g); 

    if (result != IN_PROGRESS)
    {
        board_show(g->b); 
        if (result == WHITE_WIN)       
        {
            printf("White wins!\n"); 
        }
        else if (result == BLACK_WIN)
        {
            printf("Black wins!\n");
        }
        else
        {
            printf("Draw!\n");
        }
        return 1; 
    }

    return 0; 
}

int main(int argc, char* argv[])
{
    game *curr_game = start_game(argc, argv); 

    int game_in_progress = 1; 
    int pos_unfilled = 1; 
    while (game_in_progress)
    {
        printf("\n");
        board_show(curr_game->b); 
        pos_unfilled = 1;

        while (pos_unfilled)
        {
            print_turn(curr_game); 

            char r; 
            char c; 
            scanf("%c%c%*c", &r, &c);
            
            
            r = decode_ascii(r); 
            c = decode_ascii(c); 

            printf("%c %c", r, c);

            if (r != '.' && c != '.')
            {
                if (!place_piece(curr_game, make_pos(r,c)))
                {
                    printf("Invalid location, "
                           "already full or off the board.\n");
                }
                else
                {
                    pos_unfilled = 0; 
                }
            }
            else
            {
                printf("Main: Invalid input. \n"); 
            }
        }

        if (give_outcome(curr_game))
        {
            exit(1); 
        } 
    }
}