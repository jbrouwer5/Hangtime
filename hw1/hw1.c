#include "hw1.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned int bags_of_cat_food(unsigned int num_cats, 
                              unsigned int grams_per_cat,
                              unsigned int num_days)
{
    unsigned int total_food = num_cats * grams_per_cat * num_days; 
    unsigned int num_bags;
    unsigned int BAG_WEIGHT = 4000; 
    /* If the amount of food needed doesn't exactly match a # of bags, 
    we round up and get an extra bag */ 
    if ((total_food % BAG_WEIGHT) == 0)
    {
        num_bags = total_food / BAG_WEIGHT;  
    }
    else 
    {
        num_bags = (total_food / BAG_WEIGHT) + 1;  
    }
    return num_bags; 
}

double fractional_part(unsigned int numerator, unsigned int denominator)
{
    double numerator_dub = numerator * 1.0; 
    double denominator_dub = denominator * 1.0; 
    double quotient = numerator_dub / denominator_dub;
    unsigned int quotient_int = quotient / 1.0;
    double fractional = quotient - quotient_int;
    return fractional;  
}

int is_buoyant(double weight, double radius)
{
    double SPECIFIC_WEIGHT_WATER = 62.4; 
    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3.0);  
    double buoyant_force = volume * SPECIFIC_WEIGHT_WATER;  
    return (buoyant_force >= weight);
}