#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void evidence_find_min_max()
{
    int a[5] = {3, 4, 1, 5, 2}; 
    int min1 = a[0]; 
    int max1 = a[0]; 
    int *minp1 = &min1;
    int *maxp1 = &max1;
    find_min_max(a, 5, minp1, maxp1); 
    printf("\nExpecting 1 and 5: %d and %d\n", *minp1, *maxp1);
    
    int b[6] = {10, 0, 20, 20, 1, 30}; 
    int min2 = b[0]; 
    int max2 = b[0]; 
    int *minp2 = &min2;
    int *maxp2 = &max2;
    find_min_max(b, 6, minp2, maxp2); 
    printf("\nExpecting 0 and 30: %d and %d\n", *minp2, *maxp2);

    int c[7] = {-100, 3, -27, 0, 24, 1, 99}; 
    int min3 = c[0]; 
    int max3 = c[0]; 
    int *minp3 = &min3;
    int *maxp3 = &max3;
    find_min_max(c, 7, minp3, maxp3); 
    printf("\nExpecting -100 and 99: %d and %d\n", *minp3, *maxp3);
}

void evidence_make_star_string()
{
    char* test1 = make_star_string(0);
    printf("\nExpecting an empty string : %s\n", test1);
    free(test1);
    
    char* test2 = make_star_string(5);
    printf("\nExpecting ***** : %s\n", test2);
    free(test2);

    char* test3 = make_star_string(13);
    printf("\nExpecting ************* : %s\n", test3);
    free(test3);

}

void evidence_make_histogram()
{
     int test1[6] = {0,1,2,3,4,5};
     int place_hold = 1;
     int* test_out_param = &place_hold;  
     test_out_param = make_histogram(test1, 6, test_out_param);
     printf("\nExpecting {1,1,1,1,1} : {%d, %d, %d, %d, %d}\n", 
     test_out_param[0], test_out_param[1], test_out_param[2],
     test_out_param[3], test_out_param[4]);

     int test2[10] = {10,-2,4,6,3,2,6,4,2,3};
     int* test_out_param2 = &place_hold;  
     test_out_param2 = make_histogram(test2, 10, test_out_param2);
     printf("\nExpecting {1,0,0,0,2,2,2,0,2,0,0,0,1} : " 
            "{%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d}\n", 
     test_out_param2[0], test_out_param2[1], test_out_param2[2],
     test_out_param2[3], test_out_param2[4], test_out_param2[5], 
     test_out_param2[6], test_out_param2[7], test_out_param2[8], 
     test_out_param2[9], test_out_param2[10], test_out_param2[11],
     test_out_param2[12]);
     free(test_out_param);
     free(test_out_param2);   
}

void evidence_print_histogram_visualization()
{
    int test1[6] = {0,1,2,3,4,5};
    printf("\nExpecting\n*\n*\n*\n*\n*\n*:\n\n"); 
    print_histogram_visualization(test1, 6); 
    
    int test2[12] = {5,3,5,8,4,1,3,6,8,5,3,3}; 
    printf("\nExpecting\n*\n\n****\n*\n***\n*\n\n**:\n\n"); 
    print_histogram_visualization(test2, 12); 
}

int main(int argc, char *argv[])
{
    evidence_find_min_max(); 
    evidence_make_star_string(); 
    evidence_make_histogram(); 
    evidence_print_histogram_visualization(); 
    return 0; 
}