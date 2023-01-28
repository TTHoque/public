#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};

TEST_CASE("Testing functions") {

    SUBCASE("non-negative prefix sums") {
        CHECK(non_negative_sum(nums_0, sizeof(nums_0)/sizeof(nums_0[0])) == false);
        CHECK(non_negative_sum(nums_1, sizeof(nums_1)/sizeof(nums_1[0])) == false);
        CHECK(non_negative_sum(nums_2, sizeof(nums_2)/sizeof(nums_2[0])) == true);
        CHECK(non_negative_sum(nums_3, sizeof(nums_3)/sizeof(nums_3[0])) == false);
        CHECK(non_negative_sum(nums_4, sizeof(nums_4)/sizeof(nums_4[0])) == true);
        CHECK(non_negative_sum(nums_5, sizeof(nums_5)/sizeof(nums_5[0])) == false);
    };

    SUBCASE("non-positive prefix sums") {
        CHECK(non_positive_sum(nums_0, sizeof(nums_0)/sizeof(nums_0[0])) == false);
        CHECK(non_positive_sum(nums_1, sizeof(nums_1)/sizeof(nums_1[0])) == true);
        CHECK(non_positive_sum(nums_2, sizeof(nums_2)/sizeof(nums_2[0])) == false);
        CHECK(non_positive_sum(nums_3, sizeof(nums_3)/sizeof(nums_3[0])) == false);
        CHECK(non_positive_sum(nums_4, sizeof(nums_4)/sizeof(nums_4[0])) == false);
        CHECK(non_positive_sum(nums_5, sizeof(nums_5)/sizeof(nums_5[0])) == true);
    };
}