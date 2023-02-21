#ifndef __QUEUE_H
#define __QUEUE_H

#include "stl.h"
#include <queue>
#include <string>

using namespace std;

queue<int> get_int_queue(const int n);
queue<int> int_queue_from_file(string file);
int pop_and_print_queue(queue<int>);

queue<struct node> get_node_queue(const int n);
queue<struct node> node_queue_from_file(string file);
int pop_and_print_nodes(queue<struct node> queue);

#endif