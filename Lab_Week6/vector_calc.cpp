#include "vector_calc.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <cmath>

vector<int_vector> vectors_from_file(string filename)
{
    vector<int_vector> vect;
    ifstream input {filename};
    try
    {
        if (!input) throw exception();
        string x, y;
        int_vector v;
        if (!(input >> x >> y)) throw exception();
        do {
            v.x= atof(x.c_str());
            v.y = atof(y.c_str());
            v.magnitude = v.magnitude_calc();

            vect.push_back(v);
        } while (input >> x >> y);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": bad input" << '\n';
    }
    
    return vect;
}

double int_vector::magnitude_calc()
{  
    return sqrt(pow(x, 2) + pow(y, 2));
}

double vector_pair::dot_product()
{
    if (v1.magnitude == -1) v1.magnitude = v1.magnitude_calc();
    if (v2.magnitude == -1) v2.magnitude = v2.magnitude_calc();
    
    
}

double vector_pair::cosign_angle()
{

}

void sort_vector_of_vp_bv2_cosine_closeness(const vector<vector_pair> & vect) 
{
    
}

void print_vectors_from_vector(const vector<int_vector> & vect)
{
    for (auto v: vect) {
        cout << "v.x: " << v.x 
             << ",   v.y: " << v.y  
             << ",   v.magnitude: " << v.magnitude 
             << endl;
    }
}