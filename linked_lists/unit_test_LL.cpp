#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_lists.h"

const int LL_0 = 0;
const int LL_0_sum = 0;
struct node * linked_list_0 = build_linked_list(LL_0);

const int LL_1 = 1;
const int LL_1_sum = 0;
struct node * linked_list_1 = build_linked_list(LL_1);

const int LL_2 = 10;
const int LL_2_sum = 45;
struct node * linked_list_2  = build_linked_list(LL_2);

const int LL_2a= 2;
const int LL_2a_sum = 1;
struct node * linked_list_2a  = build_linked_list(LL_2a);

const int LL_3 = 3;
const int LL_3_sum = 3;
struct node * linked_list_3 = build_linked_list(LL_3);

TEST_CASE("Testing build linked lists") 
{
    CHECK(linked_list_0 == nullptr);

    print_linked_list(linked_list_0, LL_0);
    print_linked_list(linked_list_1, LL_1);
    print_linked_list(linked_list_2, LL_2);
    print_linked_list(linked_list_2a, LL_2a);
    print_linked_list(linked_list_3, LL_3);

    struct node * node = linked_list_3;
    for (int i=0; i<LL_3; i++) {
        CHECK(node->number==i);
        node = node->next;
    }

    CHECK(sum_values_in_linked_list(linked_list_0, LL_0) == LL_0_sum);
    CHECK(sum_values_in_linked_list(linked_list_1, LL_1) == LL_1_sum);
    CHECK(sum_values_in_linked_list(linked_list_2, LL_2) == LL_2_sum);
    CHECK(sum_values_in_linked_list(linked_list_2a, LL_2a) == LL_2a_sum);
    CHECK(sum_values_in_linked_list(linked_list_3, LL_3) == LL_3_sum);

    CHECK(delete_linked_list(linked_list_0, LL_0) == LL_0);
    CHECK(delete_linked_list(linked_list_1, LL_1) == LL_1);
    CHECK(delete_linked_list(linked_list_2, LL_2) == LL_2);
    CHECK(delete_linked_list(linked_list_2a, LL_2a) == LL_2a);
    CHECK(delete_linked_list(linked_list_3, LL_3) == LL_3);

}