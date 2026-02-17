/*
    @author: Bharg Mahajan
    @description: This file contains various min stack problems solutions implemented in C++.
*/
#include <bits/stdc++.h>
using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains various min stack problems solutions implemented in C++.
*/
class MinStack
{
    stack<long> st;
    long mini;

public:
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            st.push(val);
            return;
        }

        if (val > mini)
        {
            st.push(val);
        }
        else
        {
            long temp = 2 * (long)val - mini;
            st.push(temp);
            mini = val;
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        if (mini > st.top())
            mini = 2 * mini - st.top();
        st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;

        if (mini < st.top())
            return st.top();

        return mini;
    }

    int getMin() { return mini; }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << minStack.top() << endl;    // Returns 0
    cout << minStack.getMin() << endl; // Returns -2

    return 0;
}