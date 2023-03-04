#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct int_vector {
    int id; 
    int from;
    int to;
    int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; // copy constructor
    int_vector() : id(-1), from(0), to(0) {}; // basic constructor
};

int main() 
{
    ifstream in_file;
    in_file.open("vectors_1.txt");

    vector<int_vector> vect;

    int id{0};
    string from, to;
    while (in_file >> from >> to) {
        cout << from << " " << to << " " << endl;
        int_vector int_v;
        int_v.from = atoi(from.c_str());
        int_v.to = atoi(to.c_str());
        int_v.id = id++;
        vect.push_back(int_v);
    }
    cout << endl;
    cout << "---------------------------" << endl;

    for (auto v: vect) {
        cout << v.id << ": " << v.from << " to " << v.to << endl;
    }

    cout << "-----------------------" << endl;
    cout << "Sorted:" << endl;

    sort(   vect.begin(), 
            vect.end(), 
            [](const int_vector & left, const int_vector & right) 
        
        {return left.id > right.id;}
    );

    for (auto v: vect) {
        cout << v.id << ": (" << v.from << ", " << v.to << ") " << endl;
    }

    in_file.close();

    vector<int_vector> vect2;
    for (auto v: vect) {
        vect2.push_back(v);
    }
    cout << "--------vect2----------------" << endl;
    for (auto v: vect2) {
        cout << v.id << ": (" << v.from << ", " << v.to << ") " << endl;
    }

    cout << "-------------int_vector_default-------------" << endl;
    int_vector i_v;
    cout << i_v.id << ": (" << i_v.from << ", " << i_v.to << ") " << endl;
    
    return 0;
}   