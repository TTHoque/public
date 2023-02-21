#ifndef __STACK_H
#define __STACK_H

#include "stl.h"
#include <stack>
#include <string>

using namespace std;

stack<int> get_int_stack(const int n);
stack<int> int_stack_from_file(string file);
int pop_and_print_stack(stack<int>);

stack<struct node> get_node_stack(const int n);
stack<struct node> node_stack_from_file(string file);
int pop_and_print_nodes(stack<struct node> stack);

#endif