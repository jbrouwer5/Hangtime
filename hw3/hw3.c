#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw3.h"

// returns 1 or 0 if the given int is contained in the given array or not 
int contains(int i, int* in, unsigned int inlen)
{
    for (int j = 0; j < inlen; j++)
    {
        if (i == in[j])
        {
            return 1; 
        }
    }

    return 0; 
}

// returns the number of distinct values in a given array  
int num_ints(int* in, unsigned int inlen)
{
    int count = 0; 
    int counted[inlen]; 
    int iters = 0;  

    for (int j = 0; j < inlen; j++)
    {
        if (!(contains(in[j], counted, iters)))
        {
            counted[count] = in[j]; 
            count++;
        }
        iters++; 
    }

    return count; 
}

// returns the number of instances of the int in the given array 
int count(int i, int* in, int inlen)
{
    int count = 0; 

    for (int j = 0; j < inlen; j++)
    {
        if (in[j] == i)
            count++; 
    }

    return count; 
}

int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen)
{ 
    *outlen = 2 * (num_ints(in, inlen));   
    int* encoded = (int*)malloc(sizeof(int) * *outlen); 
    int found[inlen]; 
    int ints_traversed = 0; 

    for (int j = 0; j < inlen; j++)
    {
        if (!(contains(in[j], found, ints_traversed)))
        {
            found[ints_traversed] = in[j]; 
            int instances = count(in[j], in, inlen);
            encoded[ints_traversed * 2] = instances; 
            encoded[ints_traversed * 2 + 1] = in[j];  
            ints_traversed++; 
        }
    }

    return encoded; 
}

/* Given a compressed sequence of integers, calculates the length of the 
decompressed sequence. */ 
int total_ints(int* in, unsigned int inlen)
{
    int total = 0; 

    for (int j = 0; j < inlen; j+=2)
    {
        total += in[j]; 
    }

    return total; 
}

void arr_add_nums(int* out, int start, int value, int reps)
{
    for (int j = start; j < start + reps; j++)
    {
        out[j] = value; 
    }
}

void rle_decode(int* in, unsigned int inlen, int** out, unsigned int* outlen)
{
    *outlen = total_ints(in, inlen); 
    int arr[*outlen]; 
    *out = arr;  
    int nums_added = 0; 

    for (int j = 0; j < inlen; j+=2)
    {
        arr_add_nums(*out, nums_added, in[j+1], in[j]); 
        nums_added += in[j]; 
    }
}

int test_match(char* str, char* pat, int start)
{
    for (int j = start; j < (start + strlen(pat)); j++)
    {
        if((!(str[j] == pat[j - start])) && (!(pat[j - start] == '?')))
        {
            return 0;
        }
    }

    return 1; 
}

char* match_add(char* str, int pat_len, int start)
{ 
    char* match = (char*)malloc(sizeof(char) * (pat_len + 1)); 

    for (int j = 0; j < pat_len; j++)
    {
        match[j] = str[start + j]; 
    }  

    match[pat_len] = '\0'; 

    return match; 
}

char** find_matches(char* str, char* pat, unsigned int* nmatches)
{
    int pat_len = strlen(pat); 
    int str_len = strlen(str); 
    unsigned int matches = 0; 

    for(int j = 0; j <= (str_len - pat_len); j++)
    {  
        if (test_match(str, pat, j))
        {
            matches++; 
        }
    }

    *nmatches = matches; 
    char** matches_list = (char**)malloc(sizeof(char) * *nmatches);   
    int matches_added = 0; 
    
    for(int k = 0; k <= (str_len - pat_len); k++)
    {
        if (test_match(str, pat, k))
        { 
            matches_list[matches_added] = match_add(str, pat_len, k); 
            matches_added++; 
        }
    }

    return matches_list; 
}

int total_chars(char** strings, unsigned int num_strings)
{
    int total = 0; 

    for(int j = 0; j < num_strings; j++)
    {
        total += strlen(strings[j]) + 1; 
    }

    total--; 

    return total; 
}

char* concat_strings(char** strings, unsigned int num_strings)
{
    int chars = total_chars(strings, num_strings); 
    char* result = (char*)malloc(sizeof(char) * (chars + 1)); 
    int index = 0; 

    for (int j = 0; j < num_strings; j++)
    {
        for (int k = 0; k < strlen(strings[j]); k++)
        {
            result[index] = strings[j][k]; 
            index++; 
        }

        if(j < (num_strings - 1))
        {
                    result[index] = ' '; 
                    index++;
        }
    }

    result[chars] = '\0'; 

    return result; 
}