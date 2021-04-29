#include <stdlib.h>
#include <stdio.h>
#include "hw2.h"

void evidence_first_letter()
{
    printf("- expecting Z: %c\n", first_letter(0)); 
    printf("- expecting O: %c\n", first_letter(1)); 
    printf("- expecting T: %c\n", first_letter(2)); 
    printf("- expecting T: %c\n", first_letter(3)); 
    printf("- expecting F: %c\n", first_letter(4)); 
    printf("- expecting F: %c\n", first_letter(5)); 
    printf("- expecting S: %c\n", first_letter(6)); 
    printf("- expecting S: %c\n", first_letter(7)); 
    printf("- expecting E: %c\n", first_letter(8)); 
    printf("- expecting N: %c\n", first_letter(9)); 
}

void evidence_calc_pi()
{
    printf("- with an input of 10, the value shouldn't be very accurate " 
           ": %f\n", calc_pi(10)); 
    printf("- with an input of 100, the value should be accurate to " 
           "2 or 3 decimal places: %f\n", calc_pi(100)); 
    printf("- with an input of 10000, the value should be accurate to " 
           "2 or 3 decimal places: %f\n", calc_pi(1000)); 
}

void evidence_bakhshali()
{
    printf("- expecting approximately 3: %f\n", bakhshali(9,4,.001, 100));
    printf("- expecting approximately 1: %f\n", bakhshali(1,.5,.01, 50)); 
    printf("- expecting approximately 4: %f\n", bakhshali(16,7,.0001, 1000));
    printf("- expecting approximately 5: %f\n", bakhshali(25,10,.001, 10));
    printf("- expecting approximately 8: %f\n", bakhshali(64,3,.0001, 1000));
    printf("- expecting approximately 11: %f\n", bakhshali(121,7,.001, 100));
}

void evidence_half_filled_square()
{
    printf("- expecting a square with side length 15 and the upper"
           " right half filled with asterisks.\n"); 
    half_filled_square(15, 1); 
    printf("- expecting a square with side length 8 and the lower"
           " left half filled with asterisks.\n"); 
    half_filled_square(15, 0);
}

int main(int argc, char *argv[])
{
    evidence_first_letter();
    evidence_calc_pi();
    evidence_bakhshali(); 
    evidence_half_filled_square(); 
    return 0; 
}