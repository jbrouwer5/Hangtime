#include <stdlib.h>
#include <stdio.h>
#include "waves.h"

void evidence_dist()
{
    printf("- expecting 3.0: %f\n", dist(0, 0, 3, 0));
    printf("- expecting 4.0: %f\n", dist(0, 0, 0, -4)); 
    printf("- expecting 2.0: %f\n", dist(2, 0, 0, 0));
    printf("- expecting 1.0: %f\n", dist(-1, 0, 0, 0));
    printf("- expecting 0.0: %f\n", dist(0, 0, 0, 0));
    printf("- expecting 5.0: %f\n", dist(7, 5, 10, 1));
    printf("- expecting 13.0: %f\n", dist(20, -3, 8, 2));
}

int main(int argc, char *argv[])
{
    evidence_dist(); 
    return 0; 
}