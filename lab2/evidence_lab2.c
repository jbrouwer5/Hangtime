#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"

/* runs multiple eye comparison tests for the 
generated graphs */
void evidence_graph()
{
    printf("- expecting a graph of the equation y = 0.1x^2 + 2. "
           "The graph should have x dimensions of -20 to 20 and " 
           "y dimensions of -1 to 20. The function will have a standard "  
           "symmetrical x^2 shape. The step is 1.\n"); 
    graph(.1, 0, 2, 1, -20, 20, -1, 20);
    printf("- expecting a graph of the equation y = x^2. "
           "The graph should have x dimensions of -3 to 4 and " 
           "y dimensions of -1 to 16. The function will have a standard "  
           "x^2 shape. The step is 1.\n"); 
    graph(1, 0, 0, 1, -3, 4, -1, 16);
    printf("- expecting a graph of the equation y = x^2. "
           "The graph should have x dimensions of -1.5 to 2 and " 
           "y dimensions of -.5 to 8. The function will have a standard "  
           "x^2 shape. The step is 0.5.\n"); 
    graph(1, 0, 0, .5, -3, 4, -1, 16);  
    printf("- expecting a graph of the equation y = -.5x^2 + 2x +5. "
           "The graph should have x dimensions of -10 to 10 and "
           "y dimensions of -25 to 10. The slope of the curve "
           "should be downwards in an x^2 manner. The step is 1.\n");
    graph(-.5, 2, 5, 1, -10, 10, -25, 10);
}

/* main: run the evidence function above */
int main(int argc, char *argv[])
{
    evidence_graph(); 
    return 0;
}