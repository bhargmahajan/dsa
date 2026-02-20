/*
    @author: Bharg Mahajan
    @description: This file contains various stack problems solutions implemented in C++.
*/
#include <bits/stdc++.h>
using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains various stack problems solutions implemented in C++.
*/
class MyStack
{
private:
    queue<int> q;

public:
    MyStack() {}

    /*
        @description: Pushes an element onto the stack.
        @param: x - The element to be pushed onto the stack.
        @return: void
        Time Complexity: O(n)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    void push(int x)
    {
        int s = q.size();
        q.push(x);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /*
        @description: Removes the element on top of the stack and returns that element.
        @return: The element on top of the stack.
        Time Complexity: O(1)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    int pop()
    {
        int s = q.front();
        q.pop();

        return s;
    }

    /*
        @description: Get the top element of the stack.
        @return: The top element of the stack.
        Time Complexity: O(1)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    int top() { return q.front(); }

    /*
        @description: Returns whether the stack is empty.
        @return: true if the stack is empty, false otherwise.
        Time Complexity: O(1)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    bool empty() { return q.empty(); }

    /*
        @description: Determines if the input string of parentheses is valid.
        @param: s - The input string containing parentheses.
        @return: true if the string is valid, false otherwise.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are opening parentheses.
    */
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if (st.empty())
                    return false;

                char ch = st.top();
                st.pop();

                if (ch == '(' && c == ')' || ch == '{' && c == '}' || ch == '[' && c == ']')
                    continue;
                else
                    return false;
            }
        }

        return st.empty();
    }
};

int main()
{
    MyStack sp;
    return 0;
}