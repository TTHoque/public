#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector.h"
#include <iostream>

TEST_CASE("testing vector functions") {

    cout << "vect1----------------" << endl;
    vector<int_vector> vect1 = get_int_vectors_from_file("vectors_1.txt");
    int id = vect1.size() - 1;
    for (auto v: vect1) {
        CHECK(v.id == id--);
        print_int_vector(v);
    }

    cout << "vect2----------------" << endl;
    vector<int_vector> vect2 = get_int_vectors_from_file("bad input");
    id = vect2.size() - 1;    
    for (auto v: vect2) {
        CHECK(v.id == id--);
        print_int_vector(v);
    }

    cout << "vect3----------------" << endl;
    vector<int_vector> vect3 = get_int_vectors_from_file("empty_file.txt");
    id = vect3.size() - 1;
    for (auto v: vect3) {
        CHECK(v.id == id--);
        print_int_vector(v);
    }

    cout << "vect4----------------" << endl;
    vector<int_vector> vect4;
    for (auto v: vect1) {
        vect4.push_back(v);
    }
    for (auto v: vect4) print_int_vector(v);

    int_vector iv;
    CHECK(iv.id == -1);
    CHECK(iv.from == 0);
    CHECK(iv.to == 0);

    int iv_id = 99, iv_from = -2, iv_to = 2;
    iv.id = iv_id;
    iv.from = iv_from;
    iv.to = iv_to;

    print_int_vector(iv);

    int_vector new_iv = iv;
    CHECK(new_iv.id == iv_id);
    CHECK(new_iv.from == iv_from);
    CHECK(new_iv.to == iv_to);
}