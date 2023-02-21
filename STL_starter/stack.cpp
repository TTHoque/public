#include "stack.h"
#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

stack<int> get_int_stack(const int n)
{   
    stack<int> s;
    for (int i=0; i<n; i++) {
        s.push(i);
    }
    return s;
}

stack<int> int_stack_from_file(string file) 
{   
    ifstream input {file};
    stack<int> stack;
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
                stack.push(x);
            }
            catch(const exception& e)
            {
                cerr << "buffer doesn't hold integer: " << buffer << " " << '\n';
            }   
        }
    }
    try
    {
        if (sum < 0) {
            throw exception();
        }
            
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n' << "sum of stack elements is negative\n";
        
        std::stack<int> empty;
        return empty;
    }
    
    return stack;
}

int pop_and_print_stack(stack<int> stack) 
{
    int sum = 0;
    cout << "printing stack: ";
    while (!stack.empty()) {
        sum += stack.top();
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    return sum;
}

stack<struct node> get_node_stack(const int n)
{
    stack<struct node> stack;
    struct node * cur = double_linked_list(n);

    for (int i=0; i<n; i++) {
        stack.push(*cur);
        cur = cur->next;
    }
    return stack;
}

stack<struct node> node_stack_from_file(string file)
{
    ifstream input {file};
    stack<struct node> stack;
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
                stack.push(*last);
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
        if (sum < 0) {
            throw exception();
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n' << "sum of stack elements is negative:\n";
        std::cout.setstate(std::ios_base::failbit);
        pop_and_print_nodes(stack);
        std::cout.clear();
        std::stack<node> empty;
        return empty;
    }
    
    return stack;
}

int pop_and_print_nodes(stack<struct node> stack) 
{
    int sum = 0;
    cout << "printing stack of nodes: ";
    if (stack.empty()) {
        cout << endl;
        return sum;
    }

    int size = stack.size();
    cout << stack.top().value << " ";
    
    stack.pop();
    while (stack.size()>1) {
        cout << stack.top().value << " ";
        stack.pop();    
    }

    cout << stack.top().value << " ";
    cout << endl;

    struct node * cur = stack.top().prev;
    struct node * last = cur;
    for (int i=0; i<size; i++) {
        cur = cur->next; 
        delete last;
        last = cur;
    }
    stack.pop();

    return sum;
}