#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hw2.h"
unsigned char first_letter(unsigned int digit)
{
    if (!((digit >= 0) && (digit < 10)))
    {
        fprintf(stderr, "first_letter: The input must be an integer "
                        "with a single digit value.\n");
    }

    switch (digit)
    {
    case (0):
    {
        return 'Z';
    }
    case (1):
    {
        return 'O';
    }
    case (2):
    {
        return 'T';
    }
    case (3):
    {
        return 'T';
    }
    case (4):
    {
        return 'F';
    }
    case (5):
    {
        return 'F';
    }
    case (6):
    {
        return 'S';
    }
    case (7):
    {
        return 'S';
    }
    case (8):
    {
        return 'E';
    }
    case (9):
    {
        return 'N';
    }
    }
}

// tests whether given points are within the unit circle
int within(double x, double y)
{
    int within = (pow(x, 2) + pow(y, 2)) <= 1;
    return within;
}

double calc_pi(unsigned long long int nslices)
{
    if (nslices <= 0)
    {
        fprintf(stderr, "calc_pi: The input should be a positive inteher\n");
    }
    double section_length = 1.0 / (1.0 * nslices);
    double total_intersections = nslices * nslices;
    double intersections_within = 0;
    for (double y = 1; y >= 0; y -= section_length)
    {
        for (double x = 1; x >= 0; x -= section_length)
        {
            if (within(x, y))
            {
                intersections_within++;
            }
        }
    }
    double pi_est = 4 * (intersections_within / total_intersections);
    return pi_est;
}

double bakhshali(double s, double guess, double epsilon, unsigned int max_iters)
{
    if ((s < 0) || (guess < 0) || (epsilon < 0) || (max_iters <= 0))
    {
        fprintf(stderr, "bakhshali: all arguments must be non-negative numbers"
                        " and max_iters must be at least 1\n");
    }
    int iters_left = max_iters;
    double current_guess = guess;
    double current_error = fabs(s - pow(guess, 2));
    while ((iters_left > 0) && (current_error > epsilon))
    {
        double a = (s - (pow(current_guess, 2))) / (2 * current_guess);
        double b = current_guess + a;
        current_guess = b - (pow(a, 2) / (2 * b));
        iters_left--;
        current_error = fabs(s - pow(current_guess, 2));
    }
    if (current_error < epsilon)
    {
        return current_guess;
    }
    if (iters_left == 0)
    {
        return current_guess;
    }
    return 0;
}

void half_filled_square(unsigned int side_length, int upper_right)
{
    if (side_length < 1)
    {
        fprintf(stderr, "half_filled_square: "
                        "Side length must be a positive value.\n");
    }
    for (int y = 0; y < side_length; y++)
    {
        for (int x = 0; x < side_length; x++)
        {
            if (y == (side_length - 1))
            {
                printf("*");
            }
            else if (x == (side_length -1))
            {
                printf("*\n"); 
            }
            else if ((x == 0) || (y == 0))
            {
                printf("*");
            }
            else if (((x > y) && (upper_right == 1)) ||
                     ((y > x) && (upper_right != 1)))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
    }
}
