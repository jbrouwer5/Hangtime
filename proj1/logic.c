#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "logic.h"

game* new_game(unsigned int run, unsigned int hangtime, unsigned int width,
               unsigned int height, enum type type)
{
    if (run > width && run > height)
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
    }
}

bool place_piece(game* g, pos p)
{
    if (board_get(g->b, p) != EMPTY)
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
                   && (!(posqueue_member(g->hanging, above))))
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

outcome check_left_col_rows(game* g)
{
    int count = 0; 
    bool black_win = false; 
    bool white_win = false;

    for (int i = 0; i < g->b->height; i++)
    {
        cell curr = board_get(g->b, make_pos(i, 0));
        count = 0; 

        for (int j = 0; j < g->b->width; j++)
        {
            cell new = board_get(g->b, make_pos(i, j));

            if (new == curr && curr != EMPTY)
            {
                count++;
            } 
            else
            {
                count = 0;
            }

            if (count == g->run)
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

            curr = new; 
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
    else
    {
        return IN_PROGRESS; 
    }
}

outcome check_left_col_up_dags(game* g)
{
    int count = 0; 
    int limit = 0; 
    bool black_win = false; 
    bool white_win = false;

    for (int i = 0; i < g->b->height; i++)
    {
        cell curr = board_get(g->b, make_pos(i, 0));
        count = 0; 

        if (i < g->b->width)
        {
            limit = i; 
        }
        else
        {
            limit = g->b->width; 
        }

        for (int j = 0; j < limit; j++)
        {
            cell new = board_get(g->b, make_pos(i - j, j));

            if (new == curr && curr != EMPTY)
            {
                count++;
            } 
            else
            {
                count = 0;
            }

            if (count == g->run)
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

            curr = new; 
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
    else
    {
        return IN_PROGRESS; 
    }
}

outcome check_left_col_down_dags(game* g)
{
    int count = 0; 
    int limit = 0; 
    bool black_win = false; 
    bool white_win = false;

    for (int i = 0; i < g->b->height; i++)
    {
        cell curr = board_get(g->b, make_pos(i, 0));
        count = 0; 

        if ((g->b->height - 1 - i) < (g->b->width - 1))
        {
            limit = (g->b->height - 1 - i); 
        }
        else
        {
            limit = (g->b->width - 1); 
        }

        for (int j = 0; j < limit; j++)
        {
            cell new = board_get(g->b, make_pos(i + j , j));

            if (new == curr && curr != EMPTY)
            {
                count++;
            } 
            else
            {
                count = 0;
            }

            if (count == g->run)
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

            curr = new; 
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
    else
    {
        return IN_PROGRESS; 
    }
}

outcome check_top_row_cols(game* g)
{
    int count = 0; 
    bool black_win = false; 
    bool white_win = false;

    for (int i = 0; i < g->b->width; i++)
    {
        cell curr = board_get(g->b, make_pos(0, i));
        count = 0; 

        for (int j = 0; j < g->b->height; j++)
        {
            cell new = board_get(g->b, make_pos(j, i));

            if (new == curr && curr != EMPTY)
            {
                count++;
            } 
            else
            {
                count = 0;
            }

            if (count == g->run)
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

            curr = new; 
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
    else
    {
        return IN_PROGRESS; 
    }
}

outcome check_top_row_right_dags(game* g)
{
    int count = 0; 
    int limit = 0; 
    bool black_win = false; 
    bool white_win = false;

    for (int i = 1; i < g->b->width; i++)
    {
        cell curr = board_get(g->b, make_pos(0, i));
        count = 0; 

        if ((g->b->width - i - 1) < (g->b->height - 1))
        {
            limit = g->b->width - i - 1;
        }
        else
        {
            limit = g->b->height; 
        }

        for (int j = 0; j < limit; j++)
        {
            cell new = board_get(g->b, make_pos(j, i + j));

            if (new == curr && curr != EMPTY)
            {
                count++;
            } 
            else
            {
                count = 0;
            }

            if (count == g->run)
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

            curr = new; 
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
    else
    {
        return IN_PROGRESS; 
    }
}

outcome check_right_col_down_dags(game* g)
{
    int count = 0;
    int limit = 0; 
    bool black_win = false; 
    bool white_win = false;

    for (int i = 1; i < (g->b->height - 1); i++)
    {
        cell curr = board_get(g->b, make_pos(i, 0));
        count = 0; 

        if ((i + g->b->width - g->b->height) > 0)
        {
            limit = (i + g->b->width - g->b->height); 
        }
        else
        {
            limit = 0; 
        }

        for (int j = g->b->width - 1; j > limit; j--)
        {
            cell new = board_get(g->b, make_pos(i + g->b->width - 1 - j, j));

            if (new == curr && curr != EMPTY)
            {
                count++;
            } 
            else
            {
                count = 0;
            }

            if (count == g->run)
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

            curr = new; 
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
    else
    {
        return IN_PROGRESS; 
    }
}



outcome game_outcome(game* g)
{
    if (check_left_col_rows(g) == DRAW||
        check_left_col_down_dags(g) == DRAW ||
        check_left_col_up_dags(g) == DRAW ||
        check_top_row_cols(g) == DRAW ||
        check_top_row_right_dags(g) == DRAW ||
        check_right_col_down_dags(g) == DRAW)
    {
        return DRAW;   
    }

    if (check_left_col_rows(g) == BLACK_WIN ||
        check_left_col_down_dags(g) == BLACK_WIN ||
        check_left_col_up_dags(g) == BLACK_WIN ||
        check_top_row_cols(g) == BLACK_WIN ||
        check_top_row_right_dags(g) == BLACK_WIN ||
        check_right_col_down_dags(g) == BLACK_WIN)
    {
        return BLACK_WIN;  
    }

    if (check_left_col_rows(g) == WHITE_WIN ||
        check_left_col_down_dags(g) == WHITE_WIN ||
        check_left_col_up_dags(g) == WHITE_WIN ||
        check_top_row_cols(g) == WHITE_WIN ||
        check_top_row_right_dags(g) == WHITE_WIN ||
        check_right_col_down_dags(g) == WHITE_WIN)
    {
        return WHITE_WIN; 
    }

    return IN_PROGRESS; 
}




            