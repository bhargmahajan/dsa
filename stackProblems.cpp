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
    char *stk;
    int size, topv;

public:
    MyStack(int size = 1000)
    {
        this->size = size;
        stk = new char[this->size];
        topv = -1;
    }

    /*
        @description: Pushes an element onto the stack.
        @param: x - The element to be pushed onto the stack.
        @return: void
        Time Complexity: O(n)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    void push(int x)
    {
        if (topv == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        stk[++topv] = x;
    }

    /*
        @description: Removes the element on top of the stack and returns that element.
        @return: The element on top of the stack.
        Time Complexity: O(1)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int s = stk[topv];
        topv--;

        return s;
    }

    /*
        @description: Get the top element of the stack.
        @return: The top element of the stack.
        Time Complexity: O(1)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stk[topv];
    }

    /*
        @description: Returns whether the stack is empty.
        @return: true if the stack is empty, false otherwise.
        Time Complexity: O(1)
        Space Complexity: O(k) where k is the number of elements in the stack.
    */
    bool isEmpty() { return topv == -1; }

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

    int precedence(char c)
    {
        if (c == '^')
            return 3;
        if (c == '*' || c == '/')
            return 2;
        if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    /*
        @description: Converts an infix expression to a postfix expression.
        @param: s - The input infix expression.
        @return: void
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are operators.
    */
    void infixToPostfix(string s)
    {
        stack<char> st;
        string res = "";
        for (char c : s)
        {
            if (isalnum(c))
                res += c;
            else if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                while (!st.empty() && precedence(c) <= precedence(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        cout << "postfix expression: " << res << endl;
    }

    /*
        @description: Converts a postfix expression to an infix expression.
        @param: s - The input postfix expression.
        @return: The resulting infix expression.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are operands.
    */
    string postfixToInfix(string s)
    {
        stack<string> st;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (isalnum(c))
                st.push(string(1, c));
            else
            {
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                st.push('(' + op1 + c + op2 + ')');
            }
        }

        return st.top();
    }

    /*
        @description: Converts an infix expression to a prefix expression.
        @param: s - The input infix expression.
        @return: The resulting prefix expression.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are operators.
    */
    string infixToPrefix(string infix)
    {
        reverse(infix.begin(), infix.end());

        for (int i = 0; i < infix.size(); i++)
        {
            if (infix[i] == '(')
            {
                infix[i] = ')';
                i++;
            }

            else if (infix[i] == ')')
            {
                infix[i] = '(';
                i++;
            }
        }

        infix = '(' + infix + ')';
        stack<char> st;
        string res;

        for (char c : infix)
        {
            if (isalnum(c))
                res += c;
            else if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                if (c == '^')
                {
                    while (precedence(c) <= precedence(st.top()))
                    {
                        res += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (precedence(c) < precedence(st.top()))
                    {
                        res += st.top();
                        st.pop();
                    }
                }

                st.push(c);
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    /*
        @description: Converts a prefix expression to an infix expression.
        @param: prefix - The input prefix expression.
        @return: The resulting infix expression.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are operands.
    */
    string prefixToInfix(string prefix)
    {
        stack<string> st;

        for (int i = prefix.size() - 1; i >= 0; i--)
        {
            if (isalnum(prefix[i]))
                st.push(string(1, prefix[i]));
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();

                st.push('(' + op1 + prefix[i] + op2 + ')');
            }
        }

        return st.top();
    }

    /*
        @description: Converts a prefix expression to a postfix expression.
        @param: prefix - The input prefix expression.
        @return: The resulting postfix expression.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are operands.
    */
    string prefixToPostfix(string prefix)
    {
        stack<string> st;

        for (int i = prefix.size() - 1; i >= 0; i--)
        {
            if (isalnum(prefix[i]))
                st.push(string(1, prefix[i]));
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();

                st.push(op1 + op2 + prefix[i]);
            }
        }

        return st.top();
    }

    /*
        @description: Converts a postfix expression to a prefix expression.
        @param: postfix - The input postfix expression.
        @return: The resulting prefix expression.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) in the worst case when all characters are operands.
    */
    string postfixToPrefix(string postfix)
    {
        stack<string> st;

        for (int i = 0; i < postfix.size(); i++)
        {
            char c = postfix[i];
            if (isalnum(c))
                st.push(string(1, c));
            else
            {
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                st.push(c + op1 + op2);
            }
        }

        return st.top();
    }

    /*
        @description: Finds the next greater element for each element in a circular array.
        @param: nums - The input vector of integers representing the circular array.
        @return: A vector of integers where each element is the next greater element of the corresponding input element, or -1 if there is no greater element.
        Time Complexity: O(n) where n is the number of elements in the input vector.
        Space Complexity: O(n) in the worst case when all elements are in decreasing order.
    */
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int ind = i % n, currEle = nums[ind];

            while (!st.empty() && st.top() <= currEle)
                st.pop();

            if (i < n)
            {
                if (st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }

            st.push(currEle);
        }

        return ans;
    }

    /*
        @description: Calculates the total amount of rainwater that can be trapped between the bars represented by the input vector.
        @param: height - The input vector of integers representing the height of the bars.
        @return: The total amount of rainwater that can be trapped.
        Time Complexity: O(n) where n is the number of elements in the input vector.
        Space Complexity: O(1) as we are using only a constant amount of extra space.
    */
    int trap(vector<int> &height)
    {
        int res = 0, left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;

        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    res += leftMax - height[left];
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    res += rightMax - height[right];
                right--;
            }
        }

        return res;
    }

    /*
        @description: Simulates the collision of asteroids represented by the input vector and returns the state of the asteroids after all collisions.
        @param: asteroids - The input vector of integers representing the asteroids, where positive values indicate asteroids moving to the right and negative values indicate asteroids moving to the left.
        @return: A vector of integers representing the state of the asteroids after all collisions.
        Time Complexity: O(n) where n is the number of elements in the input vector.
        Space Complexity: O(n) in the worst case when all asteroids are moving in the same direction and do not collide.
    */
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;

        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0)
                res.push_back(asteroids[i]);
            else
            {
                while (!res.empty() && res.back() > 0 &&
                       res.back() < abs(asteroids[i]))
                    res.pop_back();

                if (!res.empty() && res.back() == abs(asteroids[i]))
                    res.pop_back();
                else if (res.empty() || res.back() < 0)
                    res.push_back(asteroids[i]);
            }
        }

        return res;
    }

    /*
        @description: Removes k digits from the given number string to make the smallest possible number.
        @param: num - The input string representing a number.
        @param: k - The number of digits to remove.
        @return: The smallest possible number after removing k digits.
        Time Complexity: O(n) where n is the length of the input string.
        Space Complexity: O(n) for the stack used to store digits.
    */
    string removeKdigits(string num, int k)
    {
        stack<int> st;

        for (int i = 0; i < num.size(); i++)
        {
            char c = num[i];

            while (!st.empty() && k > 0 && st.top() > c)
            {
                st.pop();
                k--;
            }

            st.push(c);
        }

        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        while (res.size() > 0 && res.back() == '0')
            res.pop_back();

        reverse(res.begin(), res.end());

        if (res.empty())
            return "0";

        return res;
    }

    /*
        @description: Calculates the largest rectangle area in a histogram.
        @param: heights - The input vector of integers representing the heights of bars in a histogram.
        @return: The maximum area of a rectangle in the histogram.
        Time Complexity: O(n) where n is the number of elements in the input vector.
        Space Complexity: O(n) for the stack used to store indices.
    */
    int largestRectangleArea(vector<int> &heights)
    {
        int left[heights.size()], right[heights.size()], maxRect = 0;
        stack<int> st;
        int n = heights.size();

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int h = heights[st.top()];
                st.pop();

                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                maxRect = max(maxRect, w * h);
            }

            st.push(i);
        }

        return maxRect;
    }
};

int main()
{
    MyStack sp;
    sp.infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
    cout << "infix expression: " << sp.postfixToInfix("ab+c*") << endl;
    cout << "Prefix Expression: " << sp.infixToPrefix("x+y*z/w+u") << endl;
    cout << "Infix Expression: " << sp.prefixToInfix("+ab") << endl;
    cout << "Postfix Expression: " << sp.prefixToPostfix("*+ab-cd") << endl;
    cout << "Prefix Expression: " << sp.postfixToPrefix("abc*+d-") << endl;

    return 0;
}