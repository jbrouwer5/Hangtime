/* Finds the minimum and maximum values of a given integer array. The 
function then stores the min and max in the given pointers. */ 
void find_min_max(int a[], int a_len, int* min_ptr, int* max_ptr);

/* Given an integer n, this function returns a heap allocated array 
of n asterisks. */
char* make_star_string(int n);

/* Given an array of integers the function make_histogram returns a 
heap allocated array representing a histogram representation of the 
integers in the given array. The 0 index of the returned array represents
the occurences of the minimum value in the passed array. */ 
int* make_histogram(int a[], int a_len, int* hist_len_ptr);

/* Given an array and its length, the function prints 
a horizontal histogram of the integers in the array. */ 
void print_histogram_visualization(int a[], int a_len);