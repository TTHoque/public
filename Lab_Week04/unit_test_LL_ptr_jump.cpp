#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list_ptr_jump.h"

const int length_0 = 0;
struct node * LL_0  = linked_list_init(length_0);

const int length_1 = 1;
struct node * LL_1 = linked_list_init(length_1);

const int length_2 = 2;
struct node * LL_2 = linked_list_init(length_2);

const int length_10 = 10;
struct node * LL_10 = linked_list_init(length_10);

struct node * array = array_ptrs_to_each_element_in_LL(LL_10, length_10);

TEST_CASE("testing LL ptr jump") 
{
    print_jumpers_array(array, length_10);

    printLL(LL_0, length_0);
    printLL(LL_1, length_1);
    printLL(LL_2, length_2);
    printLL(LL_10, length_10);

    CHECK(sum_values_in_LL(LL_2, length_2) == 1);
    CHECK(sum_values_in_LL(LL_10, length_10) == 45);

    advance_jumpers_by_1(array, length_10);
    print_jumpers_array(array, length_10);
    for (int i=0; i<length_10; i++){
        advance_jumpers_by_1(array,length_10);
    }
    print_jumpers_array(array, length_10);
    print_jumpers_LL(LL_10, length_10);
    ptr_jump_algorithm(LL_10, length_10);
    print_jumpers_LL(LL_10, length_10);

    delete array;
    deleteLL(LL_0, length_0);
    deleteLL(LL_1, length_1);
    deleteLL(LL_2, length_2);
    deleteLL(LL_10, length_10);
}