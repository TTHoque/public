#include "queue.h"
#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

queue<int> get_int_queue(const int n)
{   
    queue<int> s;
    for (int i=0; i<n; i++) {
        s.push(i);
    }
    return s;
}

queue<int> int_queue_from_file(string file) 
{   
    ifstream input {file};
    queue<int> queue;
    int sum = 0;

    if (input) {
        string buffer;
        int x;
        while (!input.eof()) {
            input >> buffer;
            try
            {
                x = stoi(buffer);
                sum += x;
                queue.push(x);
            }
            catch(const exception& e)
            {
                cerr << "buffer doesn't hold integer: " << buffer << " " << '\n';
            }   
        }
    }
    try
    {
        if (sum < 0) 
            throw exception();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n' << "sum of queue elements is negative\n";
                        
        std::queue<int> empty;
        return empty;
    }

    return queue;
}

int pop_and_print_queue(queue<int> queue) 
{
    int sum = 0;
    cout << "printing queue: ";
    while (!queue.empty()) {
        sum += queue.front();
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
    return sum;
}

queue<struct node> get_node_queue(const int n)
{
    queue<struct node> queue;
    struct node * cur = double_linked_list(n);

    for (int i=0; i<n; i++) {
        queue.push(*cur);
        cur = cur->next;
    }
    return queue;
}

queue<struct node> node_queue_from_file(string file)
{
    ifstream input {file};
    queue<struct node> queue;
    int sum = 0;

    if (input) {
        string buffer;
        int x;
        struct node * cur = new node;
        struct node * last = cur; 
        int count = 0;

        while (!input.eof()) {
            input >> buffer;
            try
            {   
                x = stoi(buffer);
                sum += x;
                cur->value = x;
                cur->prev = last;
                cur->next = new node;
                last = cur;
                queue.push(*last);
                cur = cur->next;
                count++;

            }
            catch(const exception& e)
            {
                cerr << "buffer doesn't hold integer: " << buffer << " " << '\n';
            }   
        }
        if (count == 0) delete cur;
        else {
            delete cur;
            last->next = last;
        }
    }
    
    try
    {
        if (sum < 0) 
            throw exception();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n' << "sum of queue elements is negative:\n";
        
        std::cout.setstate(std::ios_base::failbit);
        pop_and_print_nodes(queue);
        std::cout.clear();
        std::queue<node> empty;
        return empty;
    }
    
    return queue;
}

int pop_and_print_nodes(queue<struct node> queue) 
{
    int sum = 0;
    cout << "printing queue of nodes: ";
    if (queue.empty()) {
        cout << endl;
        return sum;
    }

    int size = queue.size();
    struct node * cur = queue.front().prev;
    cout << queue.front().value << " ";
    
    queue.pop();
    while (!queue.empty()) {
        cout << queue.front().value << " ";
        queue.pop();    
    }   
    cout << endl;

    struct node * last = cur;
    for (int i=0; i<size; i++) {
        cur = cur->next; 
        delete last;
        last = cur;
    }
    return sum;
}