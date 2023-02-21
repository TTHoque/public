#ifndef __STL_H
#define __STL_H

struct node {
    struct node * next;
    struct node * prev;
    int value;
};

struct node * double_linked_list(const int n);

#endif