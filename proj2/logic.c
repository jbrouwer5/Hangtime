#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "logic.h"

game* new_game(unsigned int run, unsigned int hangtime, unsigned int width,
               unsigned int height, enum type type)
{
    if ((run > width && run > height) || width < 1 || height < 1 || run < 2 )
    {
        fprintf(stderr, "new_game : a winning run isn't possible" 
                        "with the given dimensions. \n");
        exit(1); 
    }

    game *game_new = (game*)malloc(sizeof(game)); 

    game_new->run = run; 
    game_new->hangtime = hangtime; 
    game_new->player = BLACKS_TURN; 
    game_new->hanging = posqueue_new();  
    game_new->b = board_new(width, height, type); 

    return game_new; 
}

void game_free(game* g)
{
        board_free(g->b); 
        posqueue_free(g->hanging); 
        free(g);
} 

// takes a position and returns the position up one row
pos up_one(pos p)
{
    p = make_pos(p.r - 1, p.c); 
    return p;
}

pos down_one(pos p)
{
    p = make_pos(p.r + 1, p.c); 
    return p; 
}

// takes a position and returns the position down one row 
void fall(board *b, pos p)
{
    pos spot = p; 

    while ((spot.r < (b->height - 1)) &&
           board_get(b, make_pos(spot.r + 1,spot.c)) == EMPTY)
    {
        cell curr = board_get(b, spot); 
        board_set(b, spot, EMPTY); 
        spot = down_one(spot); 
        board_set(b, spot, curr);
        board_get(b, spot); 
    }
}

bool place_piece(game* g, pos p)
{
    if ((p.r >= g->b->height) || (p.c >= g->b->width) || 
        (board_get(g->b, p) != EMPTY))
    {
        return false; 
    }

    if (g->player == BLACKS_TURN)
    {
        board_set(g->b, p, BLACK);
        g->player = WHITES_TURN;  
    }
    else
    {
        board_set(g->b, p, WHITE);
        g->player = BLACKS_TURN; 
    }

    pos_enqueue(g->hanging, p); 

    if (g->hanging->len > g->hangtime)
    {
        pos falling = pos_dequeue(g->hanging); 
        fall(g->b, falling); 

        pos above = falling; 
        if (falling.r > 0)
        {
            above = up_one(above); 
            while (board_get(g->b, above) != EMPTY
                   && (!(posqueue_member(g->hanging, above)))
                   && above.r > 0)
            {
               fall(g->b, above); 
               if (above.r > 0)
                {
                    above = up_one(above); 
                }
            }
        }
    }

    return true; 
}

// checks if the board is full
int check_full(game *g)
{
    for (int j = 0; j < g->b->height; j++)
    {
        for (int i = 0; i < g->b->width; i++)
        {
            if (board_get(g->b, make_pos(j, i)) == EMPTY)
            {
                return 0; 
            }
        }
    }

    return 1; 
}

// checks if there is a winning run in the given line 
outcome check_direction(game* g, int start_row, int start_col, 
                        int y_direction, int x_direction)
{
    int count = 0; 
    bool black_win = false; 
    bool white_win = false;
    int row = start_row;
    int col = start_col; 
    cell curr = EMPTY;

    while (row < g->b->height && row >= 0 && col < g->b->width && col >= 0)
    {
        cell new = board_get(g->b, make_pos(row, col));

        if (new == curr && curr != EMPTY)
        {
            count++;
        } 
        else
        {
            count = 0;
        }

        if (count == (g->run - 1))
        {
            if (new == BLACK)
            {
                black_win = true; 
            }
            else
            {
                white_win = true;  
            }
        }

        row += y_direction; 
        col += x_direction; 
        curr = new; 
    }
    
    if (white_win && black_win)
    {
        return DRAW; 
    }
    else if (white_win)
    {
        return WHITE_WIN;  
    }
    else if (black_win)
    {
        return BLACK_WIN;
    }
    else
    {
        return IN_PROGRESS; 
    }
}

outcome game_outcome(game* g)
{
    bool white_win;
    bool black_win; 
    outcome rows; 
    outcome cols; 
    outcome left_down_dags; 
    outcome right_down_dags; 
    outcome left_up_dags; 
    outcome right_up_dags;  

    for (int i = 0; i < g->b->height; i++)
    {
        rows = check_direction(g, i, 0, 0, 1); 
        left_down_dags = check_direction(g, i, 0, 1, 1); 
        left_up_dags = check_direction(g, i, 0, -1, 1); 
        right_up_dags = check_direction(g, i, g->b->width - 1, 1, -1); 

        if (rows == DRAW ||
            left_down_dags == DRAW ||
            left_up_dags == DRAW ||
            right_up_dags == DRAW)
        {
            return DRAW;  
        }  

        if (black_win == false &&
            (rows == BLACK_WIN ||
            left_down_dags == BLACK_WIN ||
            left_up_dags == BLACK_WIN ||
            right_up_dags == BLACK_WIN)) 
        {
            black_win = true;  
        }  

        if (white_win == false &&
            (rows == WHITE_WIN ||
            left_down_dags == WHITE_WIN ||
            left_up_dags == WHITE_WIN ||
            right_up_dags == WHITE_WIN))
        {
            white_win = true;    
        }
    }

    for (int j = 0; j < g->b->width; j++)
    {
        cols = check_direction(g, 0, j, 1, 0);
        right_down_dags = check_direction(g, 0, j, 1, 1);

        if (cols == DRAW ||
            right_down_dags == DRAW) 
        {
            return DRAW;  
        }  

        if (black_win == false &&
            (cols == BLACK_WIN ||
            right_down_dags == BLACK_WIN)) 
        {
            black_win = true;  
        }  

        if (white_win == false &&
            (cols == WHITE_WIN ||
            right_down_dags == WHITE_WIN))
        {
            white_win = true;    
        }
    }

    if (white_win && black_win)
    {
        return DRAW;
    }
    else if (white_win)
    {
        return WHITE_WIN; 
    }
    else if (black_win)
    {
        return BLACK_WIN; 
    }
    else if (check_full(g))
    {
        return DRAW;
    }
    else
    {
        return IN_PROGRESS; 
    }
}




            