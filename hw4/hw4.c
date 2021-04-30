#include <stdlib.h>
#include <stdio.h>
#include "hw4.h"

unsigned int find_amount_of_denomination(unsigned int cents, 
                                         unsigned int denomination, 
                                         unsigned int *num_denomination_ptr)
{
    int count = cents / denomination;
    *num_denomination_ptr = count; 
    int total_value = count * denomination; 

    return total_value; 
}

struct coins make_change(unsigned int cents)
{
    unsigned int cents_left = cents; 

    int quarters = cents_left / 25; 
    cents_left -= quarters * 25; 
    int dimes = cents_left / 10; 
    cents_left -= dimes * 10; 
    int nickels = cents_left / 5; 
    cents_left -= nickels * 5;
    int pennies = cents_left / 1; 
    cents_left -= pennies * 1;

    struct coins change = {.quarters = quarters, .dimes = dimes, 
                            .nickels = nickels, .pennies = pennies}; 

    return change; 
}

struct color* negative(struct color* c)
{
    struct color* negative = (struct color*)malloc(sizeof(struct color));
    negative->red = 255 - c->red; 
    negative->green = 255 - c->green;
    negative->blue = 255 - c->blue;

    return negative; 
}

struct color* greyscale(struct color* c)
{
    struct color* grey = (struct color*)malloc(sizeof(struct color));
    int value = (77 * c->red + 150 * c->green + 29 * c->blue) / 256; 
    grey->red = value; 
    grey->green = value;
    grey->blue = value;

    return grey;
}

int all_black(struct card* cards, unsigned int ncards)
{
     for (int j = 0; j < ncards; j++)
     {
        int joker = 0; 
        if (cards[j].type == JOKER)
        {
            joker = 1; 
        }
        int black = 0; 
        if (cards[j].rs.f.suit == SPADES ||
            cards[j].rs.f.suit == CLUBS) 
        {
            black = 1;
        }
         if (joker || !black)
         {
             return 0; 
         }
     }

     return 1;
}

void card_show(struct card c)
{
    char* suit; 
    char* rank; 

    if (c.type == JOKER)
    {
        printf("Joker");
        return;  
    }
    else if (c.type == FACE)
    {
        switch (c.rs.f.rank)
        {
            case JACK:
            rank = "Jack"; 
            break;

            case QUEEN:
            rank = "Queen"; 
            break; 

            default:
            rank = "King"; 
        }

        switch (c.rs.f.suit)
        {
            case SPADES:
            suit = "Spades"; 
            break; 

            case HEARTS:
            suit = "Hearts"; 
            break; 

            case CLUBS:
            suit = "Clubs"; 
            break; 

            case DIAMONDS:
            suit = "Diamonds"; 
            break; 
        }

        printf("%s of %s", rank, suit); 
    }
    else
    {
        switch (c.rs.p.rank)
        {
            case 1:
            rank = "Ace"; 
            break;

            case 2:
            rank = "2"; 
            break; 

            case 3:
            rank = "3"; 
            break;

            case 4:
            rank = "4"; 
            break;

            case 5:
            rank = "5"; 
            break;

            case 6:
            rank = "6"; 
            break;

            case 7:
            rank = "7"; 
            break;
            
            case 8:
            rank = "8"; 
            break;

            case 9:
            rank = "9"; 
            break;

            default:
            rank = "10"; 
        }

        switch (c.rs.p.suit)
        {
            case SPADES:
            suit = "Spades"; 
            break; 

            case HEARTS:
            suit = "Hearts"; 
            break; 

            case CLUBS:
            suit = "Clubs"; 
            break; 

            case DIAMONDS:
            suit = "Diamonds"; 
            break; 
        }

        printf("%s of %s", rank, suit); 
    }
}

int cards_equal(struct card c1, struct card c2)
{
    if (c1.type != c2.type)
    {
        return 0; 
    }

    else if (c1.type == FACE)
    {
        if ((c1.rs.f.rank != c2.rs.f.rank) || (c1.rs.f.suit != c2.rs.f.suit))
        {
            return 0; 
        }
    }

    else if (c1.type == PIP)
    {
        if ((c1.rs.p.rank != c2.rs.p.rank) || (c1.rs.p.suit != c2.rs.p.suit))
        {
            return 0; 
        }
    }
    
    return 1; 
}

unsigned int sum_cards(struct card* cards, unsigned int ncards)
{
    int sum = 0; 

    for (int j = 0; j < ncards; j++)
    {
        if (cards[j].type == JOKER)
        {
            sum += 1; 
        }
        else if (cards[j].type == FACE)
        {
            sum += 10; 
        }
        else
        {
            sum += cards[j].rs.p.rank; 
        }
    }

    return sum;
}


