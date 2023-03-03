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
            v.x= atoi(x.c_str());
            v.y = atoi(y.c_str());
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

int int_vector::magnitude_calc()
{  
    return sqrt(pow(x, 2) + pow(y, 2));
}

int vector_pair::dot_product()
{

}

int vector_pair::cosign_angle()
{

}

void sort_vector_of_vp_bv2_cosine_closeness(const vector<vector_pair> & vect) 
{
    
}

void print_vector_pairs(const vector<vector_pair> & vect)
{
    for (auto vp: vect) {
        cout << "magnitude: " << vp.magnitude() 
             << " v1.to: " << vp.v1.to 
             << " v2.to: " << vp.v2.to 
             << endl;
    }
}