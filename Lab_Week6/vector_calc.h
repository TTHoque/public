#ifndef __VECTOR_CALC_H
#define __VECTOR_CALC_H

#include <vector>
#include <string>
using namespace std;

struct int_vector {
    double x; // from represents the origin, from = 0
    double y;
    double magnitude;
    int_vector(const int_vector & i_v) : x(i_v.x), y(i_v.y) , magnitude(i_v.magnitude){}; 
    int_vector() : x(0), y(0), magnitude(-1){}; 
    double magnitude_calc();
};

struct vector_pair {
    int_vector v1;
    int_vector v2;
    vector_pair(const vector_pair & vp) : v1(vp.v1), v2(vp.v2) {};
    vector_pair(): v1(int_vector()), v2(int_vector()) {};
    double dot_product();
    double cosign_angle();
};

vector<int_vector> vectors_from_file(string filename);
void sort_vector_of_vp_by_cosine_closeness(const vector<vector_pair> & vect);
void print_vectors_from_vector(const vector<int_vector> & vect);


#endif