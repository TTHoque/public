#include "vector.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>

void print_int_vector(const struct int_vector & i_v)
{
    cout << i_v.id << ": " << i_v.from << " " << i_v.to << endl;
}

vector<int_vector> get_int_vectors_from_file(string filename)
{
    vector<int_vector> vect;
    ifstream input {filename};
    try
    {   
        if (!input) throw exception();
        string from, to;
        int_vector iv;
        int id{0};
        if (!(input >> from >> to)) throw exception();
        do {
            iv.id = id++;
            iv.from = atoi(from.c_str());
            iv.to = atoi(to.c_str());
            vect.push_back(iv);
        } while (input >> from >> to);

        sort(vect.begin(), 
            vect.end(), 
            [](const int_vector & left, const int_vector & right) 
            {return left.id > right.id;}
        );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": bad input" << '\n';
    }
    
    return vect;
}