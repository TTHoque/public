#include "balanced_lists.h"
//#include "prefix_sum.h"
//#include "wb_lists.h"
//#include <algorithm>
#include <iostream>

using namespace std;

void print_array(int array[], const int length) {
    for(int i=0; i<length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int lowest_depth_index(int array[], const int length) 
{
    int lowest_index;
    int lowest_value = length;
    int path_sum = 0;
    int i;

    for (i=0; i<length; i++) {
        path_sum += array[i];
        if (path_sum < lowest_value) {
            lowest_value = path_sum;
            lowest_index = i;
        }
    } 
    return lowest_index;  
}

int* new_balanced_list(int array[], const int length)
{
    if (length <= 0) return NULL;
    int lowest_depth_idx = lowest_depth_index(array, length);
    int new_length = length - 1;
    int * new_array = new int[new_length];

    for (int i=0; i<length-lowest_depth_idx-1; i++) {
        new_array[i] = array[lowest_depth_idx + i + 1];
    }

    for (int i=0; i<lowest_depth_idx; i++) {
        new_array[i+(length-lowest_depth_idx-1)] = array[i];
    }

    return new_array;
}