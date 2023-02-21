#include "stl.h"
#include <exception>
#include <iostream>
using namespace std;

struct node * double_linked_list(const int n)
{   
    if (n<=0) return NULL;
    
    struct node * start = new node;
    struct node * last = start;
    struct node * cur = start;
    int i;
    for (i=0; i<n-1; i++) {
        cur->value = i;
        cur->prev = last;
        cur->next = new node;
        last = cur;
        cur = cur->next;
    }
    cur->value = i;
    last = cur;
    cur->next = cur;
    cur->prev = last;

    return start;
}