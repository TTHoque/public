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
        cout << "vp1 angle: " << vp1.angle << endl;        

        cout << "vectors from text--------------" << endl;
        vector<int_vector> vect1 = vectors_from_file("vector_pairs.txt");
        print_vectors_from_vector(vect1);

        cout << "vectors from bad input---------" << endl;
        vector<int_vector> vect2 = vectors_from_file("bad input");
        print_vectors_from_vector(vect2);

        cout << "vectors from empty file--------" << endl;
        vector<int_vector> vect3 = vectors_from_file("empty_file.txt");
        print_vectors_from_vector(vect3);

        cout << "vect_pair----------------------" << endl;
        vector_pair vp2;
        vp2.v1 = vect1.front();
        vp2.v2 = vect1.back();
        print_int_vector(vp2.v1);
        print_int_vector(vp2.v2);
        cout << "vp2 angle: " << vp2.angle << endl;
    }

    SUBCASE("Testing magnitude calculation") 
    {
        cout << "iv1-------------------------" << endl;
        int_vector iv1;
        iv1.x = 2;
        iv1.y = 3;
        iv1.magnitude = iv1.magnitude_calc();
        CHECK(iv1.magnitude == doctest::Approx(3.60555));
        print_int_vector(iv1);

        cout << "iv2-------------------------" << endl;
        int_vector iv2;
        iv2.x = 0.075;
        iv2.y = 0.12312;
        iv2.magnitude = iv2.magnitude_calc();
        CHECK(iv2.magnitude == doctest::Approx(0.14416));
        print_int_vector(iv2);

        cout << "iv3 (3, 7)------------------" << endl;
        int_vector iv3;
        iv3.x = 3;
        iv3.y = 7;
        iv3.magnitude = iv3.magnitude_calc();
        CHECK(iv3.magnitude == doctest::Approx(7.615773));
        print_int_vector(iv3);
    }

    SUBCASE("Testing dot product calculation")
    {
        cout << "vp1--------------------" << endl;
        vector_pair vp1;

        int_vector v1;
        v1.x = 3; v1.y = 7; v1.magnitude = v1.magnitude_calc();
        int_vector v2;
        v2.x = 10; v2.y = 6; v2.magnitude = v2.magnitude_calc();
        
        vp1.v1 = v1; vp1.v2 = v2;

        double dot_product_value = vp1.dot_product();
        CHECK(dot_product_value == doctest::Approx(72));
        print_vector_pair(vp1);
    }

    SUBCASE("Testing cosine angle calculation")
    {
        cout << "vp1--------------------" << endl;
        vector_pair vp1;

        int_vector v1;
        v1.x = 3; v1.y = 7; v1.magnitude = v1.magnitude_calc();
        int_vector v2;
        v2.x = 10; v2.y = 6; v2.magnitude = v2.magnitude_calc();
        
        vp1.v1 = v1; vp1.v2 = v2;

        vp1.angle = vp1.angle_calc();
        CHECK(vp1.angle == doctest::Approx(0.625485));
        print_vector_pair(vp1);

        cout << "vp2-------------------" << endl;
        vector_pair vp2 = vp1;
        vp2.v2 = vp2.v1;
        vp2.angle = vp2.angle_calc();
        CHECK(vp2.angle == doctest::Approx(0));
        print_vector_pair(vp2);
    }

    SUBCASE("Sorting vectors pairs by cosine closeness")
    {
        cout << "vect1---------------------------" << endl;
        vector<int_vector> vect1 = vectors_from_file("vector_pairs.txt");
        print_vectors_from_vector(vect1);

        cout << "vect_vp-------------------------" << endl;
        vector<vector_pair> vect_vp = sort_vector_pairs_by_cosine_closeness(vect1);
        print_vector_pairs_from_vector(vect_vp);

        cout << "empty vectors-------------------" << endl;
        vector<int_vector> vect_empty;
        print_vectors_from_vector(vect_empty);
        vector<vector_pair> vect_vp_empty = sort_vector_pairs_by_cosine_closeness(vect_empty);
        print_vector_pairs_from_vector(vect_vp_empty); 
    }
}