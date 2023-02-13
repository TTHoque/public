#include <iostream>
#include "wb_lists.h"
#include "prefix_sum.h"

using namespace std;

void fisher_yates_shuffle(int* array, const int length)
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

int* generator(int n)
{
    if (n<=0) return NULL;

    int * array = new int[2*n + 1];
    for (int i=0; i<n; i++) {
        array[i] = 1;
    }
    for (int j=n; j<2*n+1; j++) {
        array[j] = -1;
    }

    fisher_yates_shuffle(array, 2*n+1);
    return array;
}
