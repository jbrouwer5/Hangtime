/* Takes an array of integers and compresses it in a lossless manner
such that it returns a compressed array of integers where 
each odd number refers to the count of the following value. */
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen);

/* Takes an encoded sequence in which every odd position value refers
to the count of the following even positioned number. Then returns the 
decoded segment in which every value number in the coded segment 
appears n times according to the number n preceding it. */ 
void rle_decode(int* in, unsigned int inlen, int** out, unsigned int* outlen);

/* The function takes two strings and returns an array of all the substrings 
in str that match pat according to pattern matching rules including wildcards. 
Also the length of the output array is stored in nmatches. */
char** find_matches(char* str, char* pat, unsigned int* nmatches);

/* Takes an array of strings and concatenates them. The final product
will have a space between each string with no space before the first 
string or after the last. */
char* concat_strings(char** strings, unsigned int num_strings);