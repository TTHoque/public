#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "queue.h"

using namespace std;

TEST_CASE("Testing stl containers")
{
    SUBCASE("Testing stack implementation") 
    {
        cout << "stack1----------------------------" << endl;
        stack<int> stack1 = get_int_stack(4);
        for (int i=3; i>=0; i--) {
            CHECK(stack1.top() == i);
            cout << stack1.top() << endl;
            stack1.pop();
        }

        cout << "stack2----------------------------" << endl;
        stack<int> stack2 = int_stack_from_file("bad input");
        CHECK(stack2.empty());
        pop_and_print_stack(stack2);

        cout << "stack3----------------------------" << endl;
        stack<int> stack3 = int_stack_from_file("nums1.txt");
        pop_and_print_stack(stack3);

        cout << "stack4----------------------------" << endl;
        stack<int> stack4 = int_stack_from_file("nums2.txt");
        pop_and_print_stack(stack4);

        cout << "stack5----------------------------" << endl;
        stack<struct node> stack5 = get_node_stack(5);
        pop_and_print_nodes(stack5);

        cout << "stack6----------------------------" << endl;
        stack<struct node> stack6 = get_node_stack(6);
        struct node last = stack6.top();
        CHECK(last.next->value == last.value);
        delete last.next;
        stack6.pop();
        struct node cur = stack6.top();
        while(stack6.size() > 1) {
            last = cur;
            stack6.pop();
            cur = stack6.top();
            CHECK(cur.value == last.prev->value);
            delete cur.next;
        }
        delete cur.prev;   

        cout << "stack7----------------------------" << endl;
        stack<struct node> stack7 = node_stack_from_file("bad input");
        pop_and_print_nodes(stack7);

        cout << "stack8----------------------------" << endl;
        stack<struct node> stack8 = node_stack_from_file("nums1.txt");
        pop_and_print_nodes(stack8);
        
        cout << "stack9----------------------------" << endl;
        stack<struct node> stack9 = node_stack_from_file("negative_elements.txt");
        pop_and_print_nodes(stack9);

        cout << "stack10---------------------------" << endl;
        stack<int> stack10 = int_stack_from_file("negative_elements.txt");
        pop_and_print_stack(stack10);

        cout << endl;
    }

    SUBCASE("Testing queue implementation")
    {
        cout << "queue1---------------------------" << endl;
        queue<int> queue1 = get_int_queue(4);
        for (int i=0; i<4; i++) {
            CHECK(queue1.front() == i);
            cout << queue1.front() << endl;
            queue1.pop();
        }

        cout << "queue2---------------------------" << endl;
        queue<int> queue2 = int_queue_from_file("nums1.txt");
        pop_and_print_queue(queue2);

        cout << "queue3---------------------------" << endl;
        queue<int> queue3 = int_queue_from_file("nums2.txt");
        pop_and_print_queue(queue3);

        cout << "queue4---------------------------" << endl;
        queue<int> queue4 = int_queue_from_file("negative_elements.txt");
        pop_and_print_queue(queue4);

        cout << "queue5---------------------------" << endl;
        queue<node> queue5 = get_node_queue(6);
        pop_and_print_nodes(queue5);

        cout << "queue6---------------------------" << endl;
        queue<node> queue6 = node_queue_from_file("nums1.txt");
        pop_and_print_nodes(queue6);

        cout << "queue7---------------------------" << endl;
        queue<node> queue7 = node_queue_from_file("nums2.txt");
        pop_and_print_nodes(queue7);

        cout << "queue8---------------------------" << endl;
        queue<node> queue8 = node_queue_from_file("negative_elements.txt");
        pop_and_print_nodes(queue8);

    }
}