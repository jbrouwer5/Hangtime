#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pos.h"
#include "board.h"
#include "logic.h"

void show_pos(posqueue* p) 
{
    if (p->head == NULL)
    {
        return; 
    }

    printf("\n");
    pq_entry *holder = p->head; 

    while (holder != NULL)
    {
        pos curr = holder->p;   
        printf("(%d, %d)", curr.r, curr.c); 

        if (holder->next != NULL) 
        {
            printf(" -> ");
        }

        holder = holder->next;  
    }
}

void evidence_make_pos()
{
    printf("\n***Testing make_pos***\n");

    pos test1 = make_pos(1,2); 
    printf("Expecting (1,2) : (%d, %d)\n", test1.r, test1.c); 

    pos test2 = make_pos(0,0); 
    printf("Expecting (0,0) : (%d, %d)\n", test2.r, test2.c); 

    pos test3 = make_pos(5,3); 
    printf("Expecting (5,3) : (%d, %d)\n", test3.r, test3.c); 
}

/* tests for posqueue_new and posqueue_free built into 
evidence_pos_enqueue and evidence_pos_dequeue */
void evidence_pos_enqueue_and_pos_dequeue()
{
    printf("\n***Testing posqueue_new, pos_enqueue," 
           "pos_deqeue, and posqueue_free***\n");

    posqueue *q1 = posqueue_new(); 
    pos p1 = make_pos(2,6); 
    pos p2 = make_pos(5,2); 
    pos p3 = make_pos(3,3); 
    pos p4 = make_pos(1,0); 

    pos_enqueue(q1, p1); 
    show_pos(q1);
    pos_enqueue(q1, p2);
    show_pos(q1);
    pos_enqueue(q1, p3);
    show_pos(q1);
    pos_enqueue(q1, p4);
    show_pos(q1);
    pos pos1 = pos_dequeue(q1); 
    printf("\nExpecting (2,6) : (%d, %d)\n", pos1.r, pos1.c); 
    show_pos(q1);
    pos pos2 = pos_dequeue(q1); 
    printf("\nExpecting (5,2) : (%d, %d)\n", pos2.r, pos2.c); 
    show_pos(q1);
    pos pos3 = pos_dequeue(q1); 
    printf("\nExpecting (3,3) : (%d, %d)\n", pos3.r, pos3.c); 
    show_pos(q1);
    pos pos4 = pos_dequeue(q1); 
    printf("\nExpecting (1,0) : (%d, %d)\n", pos4.r, pos4.c); 
    show_pos(q1);

    posqueue_free(q1);
}

void evidence_posqueue_member()
{
    printf("\n***Testing posqueue_member***\n");

    posqueue *q1 = posqueue_new(); 
    pos p1 = make_pos(2,6); 
    pos p2 = make_pos(5,2); 
    pos p3 = make_pos(3,3); 
    pos p4 = make_pos(1,0); 
    pos p5 = make_pos(3,3);
    pos p6 = make_pos(7,3); 
    pos p7 = make_pos(2,6);
    pos p8 = make_pos(1,0);  

    pos_enqueue(q1, p1); 
    pos_enqueue(q1, p2);
    pos_enqueue(q1, p3);
    pos_enqueue(q1, p4);
    show_pos(q1);

    printf("\nExpecting 1: %d\n", posqueue_member(q1, p5));
    printf("Expecting 1: %d\n", posqueue_member(q1, p7));
    printf("Expecting 1: %d\n", posqueue_member(q1, p8));
    printf("Expecting 0: %d\n", posqueue_member(q1, p6));

    posqueue_free(q1); 
}

// tests board_new, board_free, and board_show
void evidence_board_new()
{
    printf("\n***Testing evidence_board_new***\n");

    board *board1 = board_new(4, 6, MATRIX); 
    board_show(board1); 
    board_free(board1); 

    board *board2 = board_new(90, 60, MATRIX); 
    board_show(board2); 
    board_free(board2); 
}

void evidence_board_get()
{
    printf("\n***Testing board_get***\n"); 

    board *board1 = board_new(4, 6, MATRIX); 
    pos p1 = make_pos(1,3); 
    cell c1 = BLACK; 
    board_set(board1, p1, c1); 
    pos p2 = make_pos(5,2); 
    cell c2 = WHITE; 
    board_set(board1, p2, c2); 
    printf("Expecting black :"); 
    if (board_get(board1, p1) == BLACK)
    {
        printf("black\n");
    }
    printf("Expecting white :"); 
    if (board_get(board1, p2) == WHITE)
    {
        printf("white\n");
    }
    board_show(board1); 
    board_free(board1); 
}

void evidence_new_game()
{
    printf("\n***Testing new_game***\n"); 
    game *game1 = new_game(3, 2, 4, 6, MATRIX);
    
    printf("Expecting 3 : %d\n", game1->run); 
    printf("Expecting 2 : %d\n", game1->hangtime); 

    game_free(game1);
}

void evidence_place_piece()
{
    printf("\n***Testing place_piece***\n"); 

    printf("game1\n\n");
    game *game1 = new_game(3, 2, 4, 6, MATRIX);
    
    place_piece(game1, make_pos(1,2));
    board_show(game1->b); 
    place_piece(game1, make_pos(2,2));
    board_show(game1->b); 
    place_piece(game1, make_pos(3,2));
    board_show(game1->b); 
    printf("Expecting 3 : %d\n", game1->run); 
    printf("Expecting 2 : %d\n", game1->hangtime); 

    game_free(game1);

    printf("game2\n\n");
    game *game2 = new_game(3, 2, 5, 8, MATRIX);
    
    place_piece(game2, make_pos(4,3));
    board_show(game2->b); 
    place_piece(game2, make_pos(4,2));
    board_show(game2->b); 
    place_piece(game2, make_pos(4,1));
    board_show(game2->b); 

    game_free(game2);

    printf("game3\n\n");   
    game *game3 = new_game(3, 2, 10, 12, MATRIX);
    
    place_piece(game3, make_pos(1,2));
    board_show(game3->b); 
    place_piece(game3, make_pos(3,5));
    board_show(game3->b); 
    place_piece(game3, make_pos(6,1));
    board_show(game3->b); 
    place_piece(game3, make_pos(10,2));
    board_show(game3->b); 
    place_piece(game3, make_pos(8,8));
    board_show(game3->b); 
    place_piece(game3, make_pos(7,1));
    board_show(game3->b);
    place_piece(game3, make_pos(5,4));
    board_show(game3->b); 
    place_piece(game3, make_pos(4,2));
    board_show(game3->b); 
    place_piece(game3, make_pos(9,3));
    board_show(game3->b);
    place_piece(game3, make_pos(11,9));
    board_show(game3->b);
    place_piece(game3, make_pos(11,0));
    board_show(game3->b);
    place_piece(game3, make_pos(0,9));
    board_show(game3->b);
    place_piece(game3, make_pos(0,0));
    board_show(game3->b);
    if (game_outcome(game3) == WHITE_WIN)
    {
        printf("WHITE_WIN\n"); 
    }
    else if (game_outcome(game3) == BLACK_WIN)
    {
        printf("BLACK_WIN\n"); 
    }
    else if (game_outcome(game3) == DRAW)
    {
        printf("DRAW\n"); 
    }
    else
    {
        printf("IN_PROGRESS\n"); 
    }

    game_free(game3);

    printf("game4\n\n");   
    game *game4 = new_game(4, 1, 5, 7, MATRIX);
    place_piece(game4, make_pos(1,1));
    board_show(game4->b);
    place_piece(game4, make_pos(0,1));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,2));
    board_show(game4->b);  
    place_piece(game4, make_pos(0,3));
    board_show(game4->b);
    place_piece(game4, make_pos(0,4));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,0));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,1));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,2));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,3));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,4));
    board_show(game4->b);  
    place_piece(game4, make_pos(0,2));
    board_show(game4->b); 
    place_piece(game4, make_pos(0,3));
    board_show(game4->b); 
    place_piece(game4, make_pos(3,3));
    board_show(game4->b);
    place_piece(game4, make_pos(1,1));
    board_show(game4->b);
    place_piece(game4, make_pos(3,2));
    board_show(game4->b); 
    place_piece(game4, make_pos(1,0));
    board_show(game4->b);
    place_piece(game4, make_pos(2,3));
    board_show(game4->b);
    place_piece(game4, make_pos(1,3));
    board_show(game4->b);
    place_piece(game4, make_pos(1,4));
    board_show(game4->b);

    if (game_outcome(game4) == WHITE_WIN)
    {
        printf("WHITE_WIN\n"); 
    }
    else if (game_outcome(game4) == BLACK_WIN)
    {
        printf("BLACK_WIN\n"); 
    }
    else if (game_outcome(game4) == DRAW)
    {
        printf("DRAW\n"); 
    }
    else
    {
        printf("IN_PROGRESS\n"); 
    }

    game_free(game4);

    printf("game5\n\n");   
    game *game5 = new_game(3, 2, 5, 5, MATRIX);
    place_piece(game5, make_pos(2,2));
    board_show(game5->b);
    place_piece(game5, make_pos(1,2));
    board_show(game5->b);
    place_piece(game5, make_pos(0,0));
    board_show(game5->b);
    place_piece(game5, make_pos(0,1));
    board_show(game5->b);
    place_piece(game5, make_pos(0,2));
    board_show(game5->b);
    place_piece(game5, make_pos(0,3));
    board_show(game5->b);
    place_piece(game5, make_pos(0,4));
    board_show(game5->b);

    if (game_outcome(game5) == WHITE_WIN)
    {
        printf("WHITE_WIN\n"); 
    }
    else if (game_outcome(game5) == BLACK_WIN)
    {
        printf("BLACK_WIN\n"); 
    }
    else if (game_outcome(game5) == DRAW)
    {
        printf("DRAW\n"); 
    }
    else
    {
        printf("IN_PROGRESS\n"); 
    }

    game_free(game5);

    printf("game6\n\n");   
    game *game6 = new_game(3, 2, 5, 5, MATRIX);
    place_piece(game6, make_pos(4,2));
    board_show(game6->b);
    place_piece(game6, make_pos(4,4));
    board_show(game6->b);
    place_piece(game6, make_pos(3,2));
    board_show(game6->b);
    place_piece(game6, make_pos(3,1));
    board_show(game6->b);
    place_piece(game6, make_pos(2,2));
    board_show(game6->b);
    place_piece(game6, make_pos(2,1));
    board_show(game6->b);
    place_piece(game6, make_pos(1,1));
    board_show(game6->b);

    if (game_outcome(game6) == WHITE_WIN)
    {
        printf("WHITE_WIN\n"); 
    }
    else if (game_outcome(game6) == BLACK_WIN)
    {
        printf("BLACK_WIN\n"); 
    }
    else if (game_outcome(game6) == DRAW)
    {
        printf("DRAW\n"); 
    }
    else
    {
        printf("IN_PROGRESS\n"); 
    }

    game_free(game6);

    printf("game7\n\n");   
    game *game7 = new_game(4, 2, 5, 5, MATRIX);
    place_piece(game7, make_pos(4,4));
    board_show(game7->b);
    place_piece(game7, make_pos(3,4));
    board_show(game7->b);
    place_piece(game7, make_pos(2,4));
    board_show(game7->b);
    place_piece(game7, make_pos(1,4));
    board_show(game7->b);
    place_piece(game7, make_pos(4,3));
    board_show(game7->b);
    place_piece(game7, make_pos(3,3));
    board_show(game7->b);
    place_piece(game7, make_pos(4,0));
    board_show(game7->b);
    place_piece(game7, make_pos(2,3));
    board_show(game7->b);
    place_piece(game7, make_pos(4,2));
    board_show(game7->b);
    place_piece(game7, make_pos(3,2));
    board_show(game7->b);
    place_piece(game7, make_pos(3,0));
    board_show(game7->b);
    place_piece(game7, make_pos(4,1));
    board_show(game7->b);

    if (game_outcome(game7) == WHITE_WIN)
    {
        printf("WHITE_WIN\n"); 
    }
    else if (game_outcome(game7) == BLACK_WIN)
    {
        printf("BLACK_WIN\n"); 
    }
    else if (game_outcome(game7) == DRAW)
    {
        printf("DRAW\n"); 
    }
    else
    {
        printf("IN_PROGRESS\n"); 
    }

    game_free(game7);

    printf("game8\n\n");   
    game *game8 = new_game(3, 2, 5, 6, MATRIX);
    place_piece(game8, make_pos(0,0));
    board_show(game8->b);
    place_piece(game8, make_pos(1,2));
    board_show(game8->b);
    place_piece(game8, make_pos(1,0));
    board_show(game8->b);
    place_piece(game8, make_pos(2,2));
    board_show(game8->b);
    place_piece(game8, make_pos(2,0));
    board_show(game8->b);

    if (game_outcome(game8) == WHITE_WIN)
    {
        printf("WHITE_WIN\n"); 
    }
    else if (game_outcome(game8) == BLACK_WIN)
    {
        printf("BLACK_WIN\n"); 
    }
    else if (game_outcome(game8) == DRAW)
    {
        printf("DRAW\n"); 
    }
    else
    {
        printf("IN_PROGRESS\n"); 
    }

    game_free(game8);
}

int main(int argc, char* argv[])
{
    evidence_make_pos(); 
    evidence_pos_enqueue_and_pos_dequeue(); 
    evidence_posqueue_member(); 
    evidence_board_new(); 
    evidence_board_get();
    evidence_new_game();
    evidence_place_piece();

    return 0; 
}
