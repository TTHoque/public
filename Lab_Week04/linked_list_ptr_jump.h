#ifndef __LINKED_LIST_PTR_JUMP_H
#define __LINKED_LIST_PTR_JUMP_H

struct node {
    int num;
    struct node * next;
    struct node * jumper;
};

struct node * linked_list_init(const int n);
struct node * ptr_jump_algorithm(struct node * root, const int n);

int printLL(struct node * list, const int elements);
int deleteLL(struct node * list, const int elements);

int sum_values_in_LL(struct node * list, const int elements);
struct node * array_ptrs_to_each_element_in_LL(struct node * list, const int elements);

int advance_jumpers_by_1(struct node * array_ptrs, const int elements);
int print_jumpers_array(struct node * array_ptrs, const int elements);
int print_jumpers_LL(struct node * root, const int n);

#endif