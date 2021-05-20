#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "waves.h"

int main(int argc, char *argv[])
{
    int side = 200; 
    double r_scale = 1.0; 
    double g_scale = 1.0; 
    double b_scale = 1.0; 
    int offset_x = 0; 
    int offset_y = 0; 

    for (int j = 1; j < argc; j+=2)
    {
        char* curr = argv[j]; 

        if (!strcmp(curr, "-s"))
        {
            side = atoi(argv[j + 1]); 
        }
        else if (!strcmp(curr, "-r"))
        {
            r_scale = atof(argv[j + 1]); 
        }
        else if (!strcmp(curr, "-g"))
        {
            g_scale = atof(argv[j + 1]); 
        }
        else if (!strcmp(curr, "-b"))
        {
            b_scale = atof(argv[j + 1]); 
        }
        else if (!strcmp(curr, "-x"))
        {
            offset_x = atoi(argv[j + 1]); 
        }
        else if (!strcmp(curr, "-y"))
        {
            offset_y = atoi(argv[j + 1]); 
        }
    }

    draw_waves(side, offset_x, offset_y, r_scale, g_scale, b_scale);
    return 0;
}