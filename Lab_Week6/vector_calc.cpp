#include "vector_calc.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <cmath>

using namespace std;

vector<int_vector> vectors_from_file(string filename)
{
    vector<int_vector> vect;
    ifstream input {filename};
    try
    {
        if (!input) throw exception();
        string x, y;
        int_vector v;
        if (!(input >> x >> y)) return vect;
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
    return v1.x * v2.x + v1.y * v2.y;
}

double vector_pair::angle_calc()
{
    if (v1.magnitude == -1) v1.magnitude = v1.magnitude_calc();
    if (v2.magnitude == -1) v2.magnitude = v2.magnitude_calc();

    if (v1.x == v2.x && v1.y == v2.y) return 0; // angle of overlapping vectors is 0
    return acos(dot_product() / (v1.magnitude * v2.magnitude));
}

vector<vector_pair> sort_vector_pairs_by_cosine_closeness(const vector<int_vector> & vect) 
{
    vector<vector_pair> vect_vp;
    vector_pair vp;
    for (auto v1: vect) {
        for (auto v2: vect) {
            vp.v1 = v1;
            vp.v2 = v2;
            vp.angle = vp.angle_calc();
            vect_vp.push_back(vp);
        }
    }

    sort(vect_vp.begin(),
         vect_vp.end(),
         [](const vector_pair & left, const vector_pair & right)
         {
            return cos(left.angle) < cos(right.angle);
         }
    );

    return vect_vp;
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

void print_int_vector(const int_vector & iv) 
{
    cout << "   int_vector: "
         << "x = " << iv.x << ", y = " << iv.y 
         << ", magnitude: " << iv.magnitude << endl;
}

void print_vector_pair(const vector_pair & vp)
{
    cout << "vector_pair: " << endl;
    print_int_vector(vp.v1);
    print_int_vector(vp.v2);
    cout << "   angle between vectors: " << vp.angle << endl;
}

void print_vector_pairs_from_vector(const vector<vector_pair> & vect)
{
    for (auto vp: vect) {
        print_vector_pair(vp);
    }   
}