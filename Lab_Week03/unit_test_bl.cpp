#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "balanced_lists.h"
#include "wb_lists.h"
#include "prefix_sum.h"
#include <iostream>

const int array_0_length = 0;
int * array_0 = generator(0);

const int array_1_length = 3;
int * array_1 = generator(1);

const int array_2_length = 7;
int * array_2 = generator(3);

const int array_3_length = 11;
int * array_3 = generator(5);

const int array_4_length = 5;
int array_4[array_4_length] = {-1, 1, -1, -1, 1};

const int array_5_length = 13;
int array_5[array_5_length] = {-1, 1, 1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1};

TEST_CASE("testing new_balanced_list") 
{
    using namespace std;

    CHECK(lowest_depth_index(array_4, array_4_length) == 3);
    CHECK(lowest_depth_index(array_5, array_5_length) == 5);

    CHECK(array_0 == nullptr);
    int * balanced_array_0 = new_balanced_list(array_0, array_0_length);
    CHECK(balanced_array_0 == nullptr);

    int * balanced_array_1 = new_balanced_list(array_1, array_1_length);
    print_array(array_1, array_1_length);
    print_array(balanced_array_1, array_1_length-1);
    cout<<"-------------------------" << endl;

    bool array_1_is_balanced = non_negative_sum(balanced_array_1, array_1_length-1) || non_positive_sum(balanced_array_1, array_1_length-1);
    CHECK(array_1_is_balanced);

    int * balanced_array_2 = new_balanced_list(array_2, array_2_length);
    bool array_2_is_balanced = non_negative_sum(balanced_array_2, array_2_length-1) || non_positive_sum(balanced_array_2, array_2_length-1);
    CHECK(array_2_is_balanced);

    int * balanced_array_3 = new_balanced_list(array_3, array_3_length);
    bool array_3_is_balanced = non_negative_sum(balanced_array_3, array_3_length-1) || non_positive_sum(balanced_array_3, array_3_length-1);
    CHECK(array_3_is_balanced);
    print_array(array_3, array_3_length);
    print_array(balanced_array_3, array_3_length-1);

    int * balanced_array_4 = new_balanced_list(array_4, array_4_length);
    bool array_4_is_balanced = non_negative_sum(balanced_array_4, array_4_length-1) || non_positive_sum(balanced_array_4, array_4_length-1);
    CHECK(array_4_is_balanced);

    int * balanced_array_5 = new_balanced_list(array_5, array_5_length);
    bool array_5_is_balanced = non_negative_sum(balanced_array_5, array_5_length-1) || non_positive_sum(balanced_array_5, array_5_length-1);
    CHECK(array_5_is_balanced);

    delete[] array_0;
    delete[] balanced_array_0;
    delete[] array_1;
    delete[] balanced_array_1;
    delete[] array_2;
    delete[] balanced_array_2;
    delete[] array_3;
    delete[] balanced_array_3;
    delete[] balanced_array_4;
    delete[] balanced_array_5;
}