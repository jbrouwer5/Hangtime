#include "lab2.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* takes a given point and decides what symbol should be drawn there. */
void draw_point(double a, double b, double c, double step, int x_val, int y_val)
{
    double x = step * x_val; 
    double y = step * y_val;
    double function_value = (a * x * x + b * x + c);
    if ((function_value < (y + step)) && (function_value >= y))
    {
        printf("*");
    }
    else if ((y== 0) && (x == 0))
    {
        printf("+");
    }
    else if (x == 0)
    {
        printf("|");
    }
    else if (y == 0)
    {
        printf("-"); 
    }
    else
    {
        printf(" ");
    }
}

/* draws the row with the given y value between
   the given x dimensions */ 
void draw_row(double a, double b, double c, double step, 
              int xleft, int xright, int yvalue)
{
    if (xright < xleft)
    {
        return;
    }
    draw_point(a, b, c, step, xleft, yvalue);
    draw_row(a, b, c, step, xleft + 1, xright, yvalue); 
}

/* Calls a function which draws the top row of the picture and then 
   makes a recursive call to itself in order to make the next row. */
void graph(double a, double b, double c, double step, int xleft, int xright,
            int ybottom, int ytop)
{
    if (ybottom > ytop)
    {
        return; 
    }
    
    draw_row(a, b, c, step, xleft, xright, ytop); 
    printf("\n");
    graph(a, b, c, step, xleft, xright, ybottom, ytop - 1); 

}




