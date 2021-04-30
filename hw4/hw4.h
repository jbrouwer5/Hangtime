 struct coins {
   unsigned int quarters;
   unsigned int dimes;
   unsigned int nickels;
   unsigned int pennies;
};

/* Given a total amount of cents and a denomination, 
returns the total value of the maximum number of that 
denomination with a value less than the given value. */
unsigned int find_amount_of_denomination(unsigned int cents, 
                                         unsigned int denomination, 
                                         unsigned int *num_denomination_ptr);

/* Given a total number of cents, returns a combination of denominations 
which adds up to the given total. This function uses a greedy algorithm 
meaning that larger denominations will be maximimized first. */
struct coins make_change(unsigned int cents);

struct color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

/* Given a pointer to a struct color, returns a pointer to a struct color 
containing the negative of that color. */
struct color* negative(struct color* c);

/* Given a pointer to a struct color, returns a pointer to a struct color 
containing the greyscale of that color. */
struct color* greyscale(struct color* c);

enum face {
    JACK, QUEEN, KING
};

enum suit {
    SPADES, HEARTS, CLUBS, DIAMONDS
};

enum card_type {
    FACE, PIP, JOKER
};

struct face_card { 
    enum face rank;
    enum suit suit;
};

struct pip_card { 
    unsigned char rank;
    enum suit suit;
};

union rank_suit { 
    struct face_card f;
    struct pip_card p; 
};

struct card {
    enum card_type type;
    union rank_suit rs; 
};

/* Returns 1 if and only if every card in the given array is of a 
black suit. */
int all_black(struct card* cards, unsigned int ncards); 

/* Prints out a textual representation of the given card. */
void card_show(struct card c);

/* Returns 1 if and only if the two given cards are identical. */
int cards_equal(struct card c1, struct card c2);

/* Returns the sum of the value of the cards in the given array. 
Jokers are worth 1, Face cards are worth 10, and Pip cards have 
their associated value. */
unsigned int sum_cards(struct card* cards, unsigned int ncards);
