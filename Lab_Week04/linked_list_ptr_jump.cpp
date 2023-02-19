#include "linked_list_ptr_jump.h"
#include <iostream>

using namespace std;

struct node * linked_list_init(const int n) 
{
    struct node * LL = new node;
    struct node * cur = LL;
    struct node * last = cur;
    for (int i=0; i<n; i++) {
        last = cur;
        cur->num = i;
        cur->next = new node;
        cur->jumper = cur->next;
        cur = cur->next;
    }
    cur = last;
    cur->next = cur;
    cur->jumper = cur;

    return LL;
}

int printLL(struct node * list, const int elements) 
{
    struct node * cur = list;
    int sum = 0;
    cout << "Printing Linked List: ";
    for (int i=0; i<elements; i++) {
        sum += cur->num;
        cout << cur->num << " ";
        cur = cur->next;
    }
    cout << endl;
    return sum;
}

int deleteLL(struct node * root, const int n) 
{
    struct node * cur = root;
    struct node * last = cur;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += cur->num;
        cur = cur->next;
        delete last;
        last = cur;
    }
    return sum;
}  

int sum_values_in_LL(struct node * list, const int elements)
{
    int sum = 0;
    struct node * cur = list;
    for (int i=0; i<elements; i++) {
        sum += cur->num;
        cur = cur->next;
    }
    return sum;
}

struct node * array_ptrs_to_each_element_in_LL(struct node * list, const int elements) 
{   
    int k = 0;
    struct node * array_of_elements_LL = new node[elements];
    struct node * cur = list;

    for (int i=0; i<elements; i++) {
        array_of_elements_LL[i].num = cur->num;
        array_of_elements_LL[i].jumper = cur->jumper;
        array_of_elements_LL[i].next = cur->next;
        cur = cur->next;
    }

    return array_of_elements_LL;
}

int print_jumpers_array(struct node * array_ptrs, const int elements) 
{
    int sum = 0;
    struct node * cur = array_ptrs;
    cout << "Printing values of jumpers: ";
    for (int i=0; i<elements; i++) {
        struct node * ptr = array_ptrs[i].jumper;
        int number = ptr->num;
        sum += number;
        cout << number << " ";
    }
    cout << endl;
    return sum;
}

int advance_jumpers_by_1(struct node * array_ptrs, const int elements) 
{
    int sum = 0;
    //cout << "advance_jumpers_by_1 start" << endl;
    for (int i=0; i<elements; i++) {
        array_ptrs[i].jumper = array_ptrs[i].jumper->jumper;
        int number = array_ptrs[i].num;
        sum += number;
        //cout << number << " ";       
    }
    //cout << endl << "advance_jumpers_by_1 end" << endl;
    return sum;
}

struct node * ptr_jump_algorithm(struct node * root, const int n) 
{
    struct node * array_of_elements = array_ptrs_to_each_element_in_LL(root, n);
    struct node last_node = array_of_elements[n-1];
    struct node * cur = root;
    for (int i=0; i<n; i++) { 
        cur->jumper = &last_node;
        cur = cur->next;   
    }

    delete array_of_elements;
    return root;
}

int print_jumpers_LL(struct node * root, const int n)
{
    int sum = 0;
    struct node * cur = root;
    cout << "Printing values of jumpers: ";
    for (int i=0; i<n; i++) {
        sum += cur->jumper->num;
        cout << cur->jumper->num << " ";
        cur = cur->next;
    }
    cout << endl;
    return sum;
}