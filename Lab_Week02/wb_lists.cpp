#include <iostream>
#include "wb_lists.h"
#include "prefix_sum.h"

using namespace std;

void fisher_yates_shuffle(int* array, int length)
{
    int k, temp, last;
    for (int i=0; i<length-1; i++) {
        last = length-i;
        k = rand() % (last); 
        temp = array[k];
        array[k] = array[last-1];
        array[last-1] = temp;
    }
}

int counter(int n) 
{
    /* 
    This function will serve multiple purposes:
    - generate an array of 1s and -1s of length 2n
    - count how many iterations of fisher-shuffle are necessary for a well balanced list 
    - deallocate memory for the array
    */
    if (n<=0) return 0;
    int * array = generator(n);
    int count = 0;
    do {
        count++;
        fisher_yates_shuffle(array, 2*n);
    } while ((!non_negative_sum(array, 2*n)) && (!non_positive_sum(array, 2*n)));

    delete[] array;

    return count;
}

int* generator(int n)
{
    if (n<=0) return NULL;

    int * array = new int[2*n];
    for (int i=0; i<n; i++) {
        array[i] = 1;
    }
    for (int j=n; j<2*n; j++) {
        array[j] = -1;
    }

    return array;
}
