#include "simulation.h"
#include "wb_lists.h"
#include "prefix_sum.h"
#include <iostream>

using namespace std;

double average_iterations(int n, int num_lists)
{
    double count = 0;
    for (int i=0; i<num_lists; i++) {
        count += counter(n);
    }

    return count/num_lists;
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        cout << "usage: <executable> <size of list> <number of lists>" << endl;
    }

    int n = atoi(argv[1])/2;
    int num_lists = atoi(argv[2]);
    cout 
        << "size of each list: " << 2*n << endl
        << "number of lists: " << num_lists << endl
        << "average number of iterations needed: " << average_iterations(n, num_lists) << endl;

    return 0;
}