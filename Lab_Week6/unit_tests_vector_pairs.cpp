#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector_calc.h"

TEST_CASE("Testing vector_calc") 
{
    SUBCASE("Testing creation of vector pairs") 
    {
        cout << "vect_pair (default)------------" << endl;
        vector_pair vp1;
        cout << "v1 x : " << vp1.v1.x << ", v1 y: " << vp1.v1.y << ", v1 magnitude: " << vp1.v1.magnitude << endl;
        cout << "v2 x: " << vp1.v2.x << ", v2 y: " << vp1.v2.y << ", v2 magnitude: " << vp1.v2.magnitude << endl;
        
        cout << "vectors from text--------------" << endl;
        vector<int_vector> vect1 = vectors_from_file("vector_pairs.txt");
        print_vectors_from_vector(vect1);

        cout << "vect_pair ---------------------" << endl;
        vector_pair vp2;
        
    }
}