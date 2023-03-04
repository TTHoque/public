#ifndef __VECTOR_H
#define __VECTOR_H

#include <vector>
#include <string>
using namespace std; 

struct int_vector {
    int id; 
    int from;
    int to;
    int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; // copy constructor
    int_vector() : id(-1), from(0), to(0) {}; // basic constructor
};

void print_int_vector(const struct int_vector & i_v);
vector<int_vector> get_int_vectors_from_file(string filename);

#endif