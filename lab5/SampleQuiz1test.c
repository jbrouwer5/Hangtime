#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* given an input array and its length, 
returns the sum of the values in the input array. */ 
int add_array(int* input, int input_len)
{
    int sum = 0; 

    for (int j = 0; j < input_len; j++)
    {
        sum += input[j]; 
    }
    
    return sum; 
}

char* reverse(char* str)
{
    int len = strlen(str); 
    char* rev = (char*)malloc(sizeof(char) * len); 

    for (int j = 0; j < len; j++)
    {
        rev[j] = str[len - j - 1]; 
    }

    return rev; 
}

int* split_high(int* arr, int arrlen)
{
    int current_high = arr[0]; 
    int current_diff = arr[0] - arr[1]; 

    for (int j = 0; j < arrlen; j++)
    {
        if (arr[j] > current_high)
        {
            int temp = current_high; 
            current_high = arr[j]; 
            current_diff = current_high - temp; 
        }
    }

    int* new_arr = (int*)malloc(sizeof(int) * (arrlen + 1)); 
    for (int k = 0; k <= arrlen; k++)
    {
        if (arr[k] == current_high)
        {
            new_arr[k] = current_high - current_diff; 
            current_high++; 
        }
        else if ((current_high - arr[k]) < current_diff)
        {
            current_diff = (current_high - arr[k]); 
        }
        else 
        {
            new_arr[k] = arr[k]; 
        }

        if (k == arrlen)
        {
            new_arr[k] = current_diff; 
        }
        
    }

    return new_arr; 
}


int main(int argc, char *argv[])
{
    printf("\nExpecting niugnep : %s\n", reverse("penguin")); 
    int arr[] = {4,2,5,3,7,5,6};
    int* new = split_high(arr, 7); 
    printf("%d %d %d %d %d %d %d %d\n", new[0], new[1], new[2], 
    new[3],new[4], new[5], new[6], new[7]);
}