#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw3.h"

// prints out an array for testing purposes
void print_array(int *arr, int arrlen)
{
    printf("\n{");
    for (int j = 0; j < arrlen; j++)
    {
        if (j == (arrlen - 1))
        {
            printf("%d", arr[j]); 
        }
        else
        {
            printf("%d ", arr[j]); 
        }     
    }
    printf("}\n");
}

void print_string_array(char **arr, int arrlen)
{
    printf("\n{");
    for (int j = 0; j < arrlen; j++)
    {
        if (j == (arrlen - 1))
        {
            printf("%s", arr[j]); 
        }
        else
        {
            printf("%s ", arr[j]); 
        }     
    }
    printf("}\n");
}

void evidence_rle_encode()
{
    printf("\n***Testing rle_encode***\n"); 
    int test1[7] = {3,7,1,7,8,6,6}; 
    unsigned int out1;
    int* result1 = rle_encode(test1, 7, &out1); 

    printf("\nExpecting {1 3 2 7 1 1 1 8 2 6}: \n"); 
    print_array(result1, out1); 
    free(result1); 

    int test2[12] = {3,0,7,1,7,8,6,6,0,2,7,4};  
    unsigned int out2;
    int* result2 = rle_encode(test2, 12, &out2); 
 
    printf("\nExpecting {1 3 2 0 3 7 1 1 1 8 2 6 1 2 1 4}: \n"); 
    print_array(result2, out2);
    free(result2); 

    int test3[20] = {1,0,4,0,3,2,1,2,3,0,2,1,0,4,0,3,2,4,1,4};
    unsigned int out3; 
    int* result3 = rle_encode(test3, 20, &out3); 

    printf("\nExpecting {4 1 5 0 4 4 3 3 4 2}: \n");  
    print_array(result3, out3);
    free(result3); 
}

void evidence_rle_decode()
{
    printf("\n***Testing rle_decode***\n"); 
    int test1[4] = {6,2,4,7}; 
    int *out_arr; 
    unsigned int outlen;  
    rle_decode(test1, 4, &out_arr, &outlen); 
    printf("\nExpecting {2 2 2 2 2 2 7 7 7 7}:\n"); 
    print_array(out_arr, outlen);

    int test2[6] = {1,9,3,5,8,2}; 
    int *out_arr2; 
    unsigned int outlen2;  
    rle_decode(test2, 6, &out_arr2, &outlen2); 
    printf("\nExpecting {9 5 5 5 2 2 2 2 2 2 2 2}:\n"); 
    print_array(out_arr2, outlen2);  
}

void evidence_find_matches()
{
    printf("\n***Testing find_matches***\n"); 

    char* str1 = "cathode"; 
    char* pat1 = "cat"; 
    unsigned int nmatches1; 
    char** matches1 = find_matches(str1, pat1, &nmatches1);  

    printf("\nExpecting {cat}: "); 
    print_string_array(matches1, 1);
    free(matches1); 

    char* str2 = "tortoise"; 
    char* pat2 = "to"; 
    unsigned int nmatches2; 
    char** matches2 = find_matches(str2, pat2, &nmatches2);  

    printf("\nExpecting {to to}: "); 
    print_string_array(matches2, 2);
    free(matches2); 

    char* str3 = "chocolate chip cookies"; 
    char* pat3 = "c??"; 
    unsigned int nmatches3; 
    char** matches3 = find_matches(str3, pat3, &nmatches3); 

    printf("\nExpecting {cho col chi coo}: "); 
    print_string_array(matches3, 4);
    free(matches3); 
}

void evidence_concat_strings()
{
    char* test1[3] = {"cat", "dog", "turtle"}; 
    char* result1 = concat_strings(test1, 3); 
    printf("\nExpecting cat dog turtle: %s\n", result1); 
    free(result1); 
    
    char* test2[5] = {"Oak", "Maple", "Birch", "Beech", "Cherry"}; 
    char* result2 = concat_strings(test2, 5); 
    printf("\nExpecting Oak Maple Birch Beech Cherry: %s\n", result2); 
    free(result2); 

    char* test3[8] = {"In", "Out", "In", "Out", "In", "Out", "In", "Out"};
    char* result3 = concat_strings(test3, 8); 
    printf("\nExpecting In Out In Out In Out In Out: %s\n", result3); 
}

int main(int argc, char *argv[])
{
    evidence_rle_encode(); 
    evidence_rle_decode(); 
    evidence_find_matches(); 
    evidence_concat_strings(); 
    return 0; 
}