#include <stdlib.h>
#include <stdio.h>
#include "hw4.h"

void evidence_find_amount_of_denomination()
{
    printf("\n***Testing find_amount_of_denomination***\n");

    unsigned int amount1; 
    int value1 = find_amount_of_denomination(150, 25, &amount1); 
    printf("\nExpecting value 150 : %d, amount 6 : %d\n", 
        value1, amount1); 

    unsigned int amount2; 
    int value2 = find_amount_of_denomination(213, 10, &amount2); 
    printf("\nExpecting value 210 : %d, amount 21 : %d\n", 
        value2, amount2); 
}

void evidence_make_change()
{
    printf("\n***Testing make_change***\n"); 

    struct coins change1 = make_change(147); 
    printf("Expecting \n5 quarters, 2 dimes, 0 nickels, 2 pennies. : \n"
           "%d quarters, %d dimes, %d nickels, %d pennies\n", 
           change1.quarters, change1.dimes, change1.nickels, change1.pennies); 

    struct coins change2 = make_change(67); 
    printf("Expecting \n2 quarters, 1 dimes, 1 nickels, 2 pennies. : \n"
           "%d quarters, %d dimes, %d nickels, %d pennies\n", 
           change2.quarters, change2.dimes, change2.nickels, change2.pennies); 

    struct coins change3 = make_change(215); 
    printf("Expecting \n8 quarters, 1 dimes, 1 nickels, 0 pennies. : \n"
           "%d quarters, %d dimes, %d nickels, %d pennies\n", 
           change3.quarters, change3.dimes, change3.nickels, change3.pennies); 
}

void evidence_negative()
{
    printf("\n***Testing negative***\n");

    struct color purp = {.red = 255, .green = 0, .blue = 255};
    struct color* green = negative(&purp);
    printf("Expecting \n0 255 0 : \n%d %d %d\n",
            green->red, green->green, green->blue);

    struct color test1 = {.red = 177, .green = 3, .blue = 220};
    struct color* result1 = negative(&test1);
    printf("Expecting \n78 252 35 : \n%d %d %d\n",
            result1->red, result1->green, result1->blue);

    struct color test2 = {.red = 0, .green = 0, .blue = 0};
    struct color* result2 = negative(&test2);
    printf("Expecting \n255 255 255 : \n%d %d %d\n",
            result2->red, result2->green, result2->blue);

    struct color test3 = {.red = 255, .green = 255, .blue = 255};
    struct color* result3 = negative(&test3);
    printf("Expecting \n0 0 0 : \n%d %d %d\n",
            result3->red, result3->green, result3->blue);
}

void evidence_greyscale()
{
    printf("\n***Testing greyscale***\n");

    struct color test1 = {.red = 182, .green = 145, .blue = 0};
    struct color* result1 = greyscale(&test1);
    printf("Expecting \n139 139 139 : \n%d %d %d\n",
            result1->red, result1->green, result1->blue);

    struct color test2 = {.red = 129, .green = 10, .blue = 254};
    struct color* result2 = greyscale(&test2);
    printf("Expecting \n73 73 73 : \n%d %d %d\n",
            result2->red, result2->green, result2->blue);

    struct color test3 = {.red = 255, .green = 255, .blue = 255};
    struct color* result3 = greyscale(&test3);
    printf("Expecting \n255 255 255 : \n%d %d %d\n",
            result3->red, result3->green, result3->blue);
}

void evidence_all_black()
{
    printf("\n***Testing all_black***\n");

    struct card cards1[1]; 
    struct card card1 = {.type = JOKER}; 
    cards1[0] = card1; 
    unsigned int result1 = all_black(cards1, 1); 
    printf("Expecting 0 : %d\n", result1);

    struct card cards2[2]; 
    struct card card2 = {.type = FACE, .rs.f.suit = SPADES}; 
    struct card card3 = {.type = PIP, .rs.p.suit = CLUBS}; 
    cards2[0] = card2; 
    cards2[1] = card3; 
    unsigned int result2 = all_black(cards2, 2); 
    printf("Expecting 1 : %d\n", result2); 

    struct card cards3[3]; 
    cards3[0] = card2; 
    cards3[1] = card3; 
    cards3[2] = card1; 
    unsigned int result3 = all_black(cards3, 3); 
    printf("Expecting 0 : %d\n", result3); 

    struct card cards4[3]; 
    struct card card4 = {.type = PIP, .rs.p.suit = HEARTS}; 
    cards4[0] = card2; 
    cards4[1] = card3; 
    cards4[2] = card4; 
    unsigned int result4 = all_black(cards4, 3); 
    printf("Expecting 0 : %d\n", result4);  
}

void evidence_card_show()
{
    printf("\n***Testing card_show***\n"); 

    struct card aceofspades = {.type = PIP, .rs.p.rank = 1, 
                              .rs.p.suit = SPADES}; 
    printf("Expecting Ace of Spades : "); 
    card_show(aceofspades); 
    printf("\n"); 

    struct card jackofdiamonds = {.type = FACE, .rs.f.rank = JACK, 
                              .rs.f.suit = DIAMONDS}; 
    printf("Expecting Jack of Diamonds : "); 
    card_show(jackofdiamonds); 
    printf("\n"); 

    struct card sevenofclubs = {.type = PIP, .rs.p.rank = 7, 
                              .rs.p.suit = CLUBS}; 
    printf("Expecting 7 of Clubs : "); 
    card_show(sevenofclubs); 
    printf("\n"); 
}

void evidence_cards_equal()
{
    printf("\n***Testing cards_equal***\n"); 

    struct card card1 = {.type = JOKER}; 
    struct card card2 = {.type = JOKER}; 
    struct card card3 = {.type = FACE, .rs.f.rank = JACK, .rs.f.suit = SPADES};
    struct card card4 = {.type = FACE, .rs.f.rank = KING, .rs.f.suit = CLUBS};
    struct card card5 = {.type = PIP, .rs.p.rank = 2, .rs.p.suit = SPADES};
    struct card card6 = {.type = PIP, .rs.p.rank = 2, .rs.p.suit = SPADES};
    struct card card7 = {.type = PIP, .rs.p.rank = 5, .rs.p.suit = DIAMONDS};
    struct card card8 = {.type = FACE, .rs.f.rank = JACK, .rs.f.suit = SPADES};

    int result1 = cards_equal(card1, card2); //true
    int result2 = cards_equal(card3, card8); //true 
    int result3 = cards_equal(card3, card4); //false
    int result4 = cards_equal(card5, card6); //true
    int result5 = cards_equal(card6, card7); //false
    int result6 = cards_equal(card1, card7); //false

    printf("Expecting \n1 : %d\n1 : %d\n0 : %d\n1 : %d\n0 : %d\n0 : %d\n", 
           result1, result2, result3, result4, result5, result6); 
}

void evidence_sum_cards()
{
    printf("\n***Testing sum_cards***\n"); 

    struct card card1 = {.type = JOKER}; 
    struct card card2 = {.type = FACE, .rs.f.rank = JACK};
    struct card card3 = {.type = FACE, .rs.f.rank = QUEEN};
    struct card card4 = {.type = PIP, .rs.p.rank = 2};
    struct card card5 = {.type = PIP, .rs.p.rank = 7}; 

    struct card cards1[5]; 
    cards1[0] = card1; 
    cards1[1] = card2; 
    cards1[2] = card3; 
    cards1[3] = card4; 
    cards1[4] = card5; 

    struct card cards2[4]; 
    cards2[0] = card1; 
    cards2[1] = card1; 
    cards2[2] = card5; 
    cards2[3] = card5; 

    printf("Expecting 29 : %d\n", sum_cards(cards1, 5)); 
    printf("Expecting 14 : %d\n", sum_cards(cards2, 4));    
}

int main(int argc, char *argv[])
{
    evidence_find_amount_of_denomination(); 
    evidence_make_change(); 
    evidence_negative();
    evidence_greyscale(); 
    evidence_all_black(); 
    evidence_card_show();
    evidence_cards_equal();
    evidence_sum_cards(); 
    return 0; 
}