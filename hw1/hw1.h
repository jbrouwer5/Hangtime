/* Takes the numner of cats in the house, the grams of food each cat
eats per day, and the number of days the owner is gone. 
Returns the number of cat food bags that should be purchased in order
to have enough food for the cats for the duration of the trip. */
unsigned int bags_of_cat_food(unsigned int num_cats, 
                              unsigned int grams_per_cat,
                              unsigned int num_days);

/* Takes two unsigned integers. 
Returns the fractional part of the first integer divided by the second*/
double fractional_part(unsigned int numerator, unsigned int denominator); 

/* Takes a double representing the weight of a spherical object, as
well as a double representing the radius of said object. 
Returns 1 if the object would float on water, returns 0 otherwise. */
int is_buoyant(double weight, double radius);