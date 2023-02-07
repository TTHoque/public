#include "prefix_sum.h"
#include <iostream>

using namespace std;

int prefix_sum(int array[], int length) 
{
    int sum = 0;
    for (int i=0; i<length; i++) {
        sum += array[i];
    }

    return sum;
}

bool non_negative_sum(int array[], int length) 
{   
    if (length <= 0) return false; // edgecase

    for(int i=0; i<length; i++) {
        if ((prefix_sum(array, i+1)) >= 0) return false;
    }

    return true;
}

bool non_positive_sum(int array[], int length) 
{
    if (length <= 0) return false; // edgecase
    
    for(int i=0; i<length; i++) {
        if ((prefix_sum(array, i+1)) < 0) return false;
    }

    return true;
}
