#include <bits/stdc++.h>
using namespace std;

// Recursion class to solve recursion problems
class Recursion
{
public:
    double power(double x, long n)
    {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n % 2 == 0)
            return power(x * x, n / 2);

        return x * power(x, n - 1);
    }

    /* @description: calculate x raised to the power n
     * @param {double} x - the base
     * @param {int} n - the exponent
     * @return {double} - the result of x raised to the power n
     * @time complexity: O(log n)
     * @space complexity: O(log n) due to recursion stack
     */
    double myPow(double x, int n)
    {
        long num = n;
        if (num < 0)
            return (1.0 / power(x, -1 * num));

        return power(x, num);
    }

    int helper(const string &s, int i, long long num, int sign)
    {
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        num = num * 10 + (s[i] - '0');

        if (sign * num >= INT_MAX)
            return INT_MAX;
        if (sign * num <= INT_MIN)
            return INT_MIN;

        return helper(s, i + 1, num, sign);
    }

    /* @description: convert a string to a 32-bit signed integer
     * @param {string} s - the input string
     * @return {int} - the converted integer
     * @time complexity: O(n)
     * @space complexity: O(n) due to recursion stack
     */
    int myAtoi(string s)
    {
        int i = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }

    void backtrack(string curr, int open, int close, int n,
                   vector<string> &res)
    {
        if (curr.length() == 2 * n)
        {
            res.push_back(curr);
            return;
        }

        if (open < n)
            backtrack(curr + '(', open + 1, close, n, res);
        if (close < open)
            backtrack(curr + ')', open, close + 1, n, res);
    }

    /* @description: generate all combinations of well-formed parentheses
     * @param {int} n - number of pairs of parentheses
     * @return {vector<string>} - list of all combinations
     * @time complexity: O(((2n)! / (n!(n+1)!))*n)
     * @space complexity: O(((2n)! / (n!(n+1)!))*n) for storing the result
     */
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        backtrack("", 0, 0, n, res);

        return res;
    }
};

int main()
{
    Recursion sol;
    double x = 2.0;
    int n = 10;

    // Calculate x raised to n
    double result = sol.myPow(x, n);

    // Print the result
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}