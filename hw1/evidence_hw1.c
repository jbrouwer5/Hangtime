#include <stdlib.h>
#include <stdio.h>
#include "hw1.h"

void evidence_bags_of_cat_food()
{
    printf("- expecting 3: %d\n", bags_of_cat_food(5, 300, 7));
    printf("- expecting 2: %d\n", bags_of_cat_food(3, 500, 3));
    printf("- expecting 1: %d\n", bags_of_cat_food(1, 500, 2));
    printf("- expecting 3: %d\n", bags_of_cat_food(2, 600, 10));
}

void evidence_fractional_part()
{
    printf("- expecting .5: %lf\n", fractional_part(3, 2)); 
    printf("- expecting .2: %lf\n", fractional_part(10, 50)); 
    printf("- expecting .6: %lf\n", fractional_part(3, 5)); 
    printf("- expecting .25: %lf\n", fractional_part(8, 32)); 
}

void evidence_is_buoyant()
{
    printf("- expecting 1: %d\n", is_buoyant(1000, 3));
    printf("- expecting 1: %d\n", is_buoyant(30, .5));
    printf("- expecting 0: %d\n", is_buoyant(50, .5));
    printf("- expecting 0: %d\n", is_buoyant(100000, 5));
}

int main(int argc, char *argv[])
{
    evidence_bags_of_cat_food(); 
    evidence_fractional_part(); 
    evidence_is_buoyant(); 
    return 0; 
}