/* The function takes an integer from 0 to 9 and returns the 
first letter of the english word for that digit. */
unsigned char first_letter(unsigned int digit);

/* Given a number of slices along each axis in the first quadrant, 
attempts to calculate an estimate for pi. */ 
double calc_pi(unsigned long long int nslices);

/* The function bakshali is used to calculate the sqaure root of a number s
by using simple arithmatic. Given an initial guess, it finds the square root 
of s within the given epsilon. If the answer is not within epsilon after 
the given max iterations max_iters, the current answer is returned. */ 
double bakhshali(double s, double guess, 
                 double epsilon, unsigned int max_iters);

/* Designs a ASCII drawing of a rectangle with side lengths side_length. 
The border will be filled with asteriks and if upper_right is true, 
the upper-right half of the rectangle will 
be shaded. Otherwise the lower-left half will be shaded. */ 
void half_filled_square(unsigned int side_length, int upper_right);