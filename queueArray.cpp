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
public:
    int *arr, start, end, cSize, mSize;

    MyQueue(int s = 10)
    {
        arr = new int[s];
        cSize = 0;
        mSize = s;
        start = -1;
        end = -1;
    }

    /*
        @description: This function adds an element to the end of the queue. If the queue is full, it prints a message and returns.
        @param: x - The element to be pushed onto the stack.
        @return: void
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    void push(int x)
    {
        if (cSize == mSize)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % mSize;

        arr[end] = x;
        cSize++;
    }

    /*
        @description: This function removes and returns the element at the front of the queue. If the queue is empty, it prints a message and exits.
        @return: The element at the front of the queue.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    int pop()
    {
        if (cSize == 0)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }

        int res = arr[start];

        if (cSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
            start = (start + 1) % mSize;

        cSize--;
        return res;
    }

    /*
        @description: This function returns the element at the front of the queue without removing it. If the queue is empty, it prints a message and exits.
        @return: The element at the front of the queue.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    int peek()
    {
        if (cSize == 0)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    /*
        @description: This function checks if the queue is empty.
        @return: true if the queue is empty, false otherwise.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    bool isEmpty()
    {
        return cSize == 0;
    }
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
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayQueue")
        {
            cout << "null ";
        }
    }
    return 0;
}