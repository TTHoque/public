#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector_calc.h"

TEST_CASE("Testing vector_calc") 
{
    SUBCASE("Testing creation of vector pairs") 
    {
        cout << "vect_pair (default)------------" << endl;
        vector_pair vp1;
        cout << "x from: " << vp1.x.from << ", x to: " << vp1.x.to << endl;
        cout << "y from: " << vp1.y.from << ", y to: " << vp1.y.to << endl;
        
        cout << "vect_pairs from text------------" << endl;
        vector<vector_pair> vect1 = vector_pairs_from_file("vector_pairs.txt");
        print_vector_pairs(vect1);
    }
}