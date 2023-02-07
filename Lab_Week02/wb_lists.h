#ifndef __WB_LISTS_H
#define __WB_LISTS_H

void fisher_yates_shuffle(int* array, int length);

int counter(int n);
/* 
This function will serve multiple purposes:
- generate an array of 1s and -1s of length 2n
- count how many iterations of fisher-shuffle are necessary for a well balanced list 
- deallocate memory for the array
*/

int* generator(int n);

#endif