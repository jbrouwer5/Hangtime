#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waves.h"

double dist(double x0, double y0, double x1, double y1)
{
    double xdiff = x1 - x0; 
    double ydiff = y1 - y0; 
    double distance = sqrt((pow(xdiff, 2) + pow(ydiff, 2)));

    return distance; 
}

int color(double distance, double scalar)
{
    double sine = sin(distance * scalar); 
    sine++; 
    int color = (sine * 255 / 2); 

    return color;
}

void draw_waves(int side_length, int x_offset, int y_offset, 
                double red_scale, double green_scale, double blue_scale)
{
    if (side_length < 0)
    {
        fprintf(stderr, "draw_waves: "
                        "Side length must be a positive value. "
                        "Invalid input: %d\n", side_length); 
    }

     printf("P3\n"); 
     printf("%d %d\n", side_length, side_length);
     printf("255\n");
     
     int offset_centerx = side_length / 2 + x_offset; 
     int offset_centery = side_length / 2 + y_offset; 

     for (int y = 0; y < side_length; y++)
     {
         for (int x = 0; x < side_length; x++)
         {
            double distance = dist(x, y, offset_centerx, offset_centery); 
            int r = color(distance, red_scale);
            int g = color(distance, green_scale);
            int b = color(distance, blue_scale); 
            
            printf("%d %d %d\n", r, g, b);
         }
     }
}