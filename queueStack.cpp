/*
    @author: Bharg Mahajan
    @description: This file contains various queue problems solutions implemented in C++.
*/
#include <bits/stdc++.h>
using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains various queue problems solutions implemented in C++.
*/
class MyQueue
{
private:
    stack<int> st1, st2;

public:
    MyQueue() {}

    /*
        @description: This function adds an element to the end of the queue. It uses two stacks to maintain the order of elements.
        @param: x - The element to be pushed onto the stack.
        @return: void
        Time Complexity: O(n) where n is the number of elements in the queue.
        Space Complexity: O(n) where n is the number of elements in the queue.
    */
    void push(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    /*
        @description: This function removes and returns the element at the front of the queue. If the queue is empty, it returns -1.
        @return: The element at the front of the queue, or -1 if the queue is empty.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    int pop()
    {
        if (st1.empty())
            return -1;

        int res = st1.top();
        st1.pop();

        return res;
    }

    /*
        @description: This function returns the element at the front of the queue without removing it. If the queue is empty, it returns -1.
        @return: The element at the front of the queue, or -1 if the queue is empty.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    int peek()
    {
        if (st1.empty())
            return -1;

        return st1.top();
    }

    /*
        @description: This function checks if the queue is empty.
        @return: true if the queue is empty, false otherwise.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    bool empty() { return st1.size() == 0; }
};

int main()
{
    MyQueue queue;

    vector<string> commands = {"ArrayQueue", "push", "push", "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            queue.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << queue.pop() << " ";
        }
        else if (commands[i] == "peek")
        {
            cout << queue.peek() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (queue.empty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayQueue")
        {
            cout << "null ";
        }
    }
    return 0;
}