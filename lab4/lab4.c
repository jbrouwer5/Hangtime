#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lab4.h"

void find_min_max(int a[], int a_len, int* min_ptr, int* max_ptr)
{
    if (a_len == 0)
    {
        fprintf(stderr, "find_min_max: Please input a non-empty array.\n"); 
    }

    int min = a[0]; 
    int max = a[0]; 

    for (int x = 0; x < a_len; x++)
    {
        if(a[x] < min)
        {
            min = a[x]; 
        }
        if(a[x] > max)
        {
            max = a[x]; 
        }
    }

    *min_ptr = min; 
    *max_ptr = max; 
}

char* make_star_string(int n)
{
    if (n < 0)
    {
        fprintf(stderr, "make_star_string: "
                        "Please input a number equal to or greater than 0\n")
    }
    char* stars = (char*)malloc(sizeof(char) * n); 
    char star = '*'; 

    for (int j = 0; j < n; j++)
    {
        stars[j] = star; 
    } 
    stars[n] = '\0'; 

    return stars; 
}

int count(int k[], int arr_len, int key)
{
    int count = 0; 
    for (int l = 0; l < arr_len; l++)
    {
        if(key == k[l])
        {
            count++; 
        }
    }
    return count; 
}

int* make_histogram(int a[], int a_len, int* hist_len_ptr)
{
    int max = a[0];
    int min = a[0]; 
    int *maxp = &max; 
    int *minp = &min;

    find_min_max(a, a_len, minp, maxp); 
    int difference = *maxp - *minp + 1; 

    hist_len_ptr = (int*)malloc(sizeof(int) * difference + 5);

    for (int x = 0; x < a_len; x++)
    {
        int index = a[x] - *minp; 
        hist_len_ptr[index] = count(a, a_len, a[x]);    
    }

    return hist_len_ptr; 
}

void print_histogram_visualization(int a[], int a_len)
{
    int place = 1;  
    int* histogram_data = &place;  
    histogram_data = make_histogram(a, a_len, histogram_data); 

    int max = a[0];
    int min = a[0]; 
    int *maxp = &max; 
    int *minp = &min;
    find_min_max(a, a_len, minp, maxp); 
    int difference = *maxp - *minp + 1;  

    for (int j = 0; j < difference; j++)
    {
        char* histo = make_star_string(histogram_data[j]); 
        printf("%s\n", histo); 
    }

}

