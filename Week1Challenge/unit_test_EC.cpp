#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ECNumbers.h"

TEST_CASE("testing remove value function") 
{

    int nums_0[] = {};
    int nums_1[] = {1};
    int nums_2[] = {3, 2, 2, 3};
    int nums_3[] = {0, 1, 2, 2, 3, 0, 4, 2};

    ECRemoveSpace(nums_0, 0, 1);
    ECRemoveSpace(nums_1, 1, 1);
    ECRemoveSpace(nums_2, 4, 3);
    ECRemoveSpace(nums_3, 8, 2);

    CHECK(nums_1[0] == '\0');
    CHECK(nums_2[2] == '\0');
    CHECK(nums_3[5] == '\0');
}