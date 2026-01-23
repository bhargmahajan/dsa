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

    void helper(vector<int> &nums, int index, vector<int> &curr,
                vector<vector<int>> &result)
    {
        if (index == nums.size())
        {
            result.push_back(curr);
            return;
        }

        helper(nums, index + 1, curr, result);
        curr.push_back(nums[index]);
        helper(nums, index + 1, curr, result);
        curr.pop_back();
    }

    /* @description: generate all possible subsets of a set of distinct integers
     * @param {vector<int>} nums - input set of distinct integers
     * @return {vector<vector<int>>} - list of all possible subsets
     * @time complexity: O(n*2^n)
     * @space complexity: O(n*2^n) for storing the result
     */
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        helper(nums, 0, curr, res);
        return res;
    }

    void findCombination(int index, int target, vector<int> &nums,
                         vector<vector<int>> &ans, vector<int> &ds)
    {
        if (index == nums.size())
        {
            if (target == 0)
                ans.push_back(ds);
            return;
        }

        if (nums[index] <= target)
        {
            ds.push_back(nums[index]);
            findCombination(index, target - nums[index], nums, ans, ds);
            ds.pop_back();
        }

        findCombination(index + 1, target, nums, ans, ds);
    }

    /* @description: find all unique combinations in candidates where the candidate numbers sum to target
     * @param {vector<int>} candidates - input set of candidate numbers
     * @param {int} target - target sum
     * @return {vector<vector<int>>} - list of all unique combinations
     * @time complexity: O(2^t * k) where t is target and k is average length of combination
     * @space complexity: O(k*x), where x is the number of combinations and k is their average length.
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }

    void findCombination2(int index, int target, vector<int> &nums,
                          vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            ds.push_back(nums[i]);
            findCombination2(i + 1, target - nums[i], nums, ans, ds);
            ds.pop_back();
        }
    }

    /* @description: find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates mayonly be used once in the combination.
     * @param {vector<int>} candidates - input set of candidate numbers
     * @param {int} target - target sum
     * @return {vector<vector<int>>} - list of all unique combinations
     * @time complexity: O(2^t * k) where t is target and k is average length of combination
     * @space complexity: O(k*x), where x is the number of combinations and k is their average length.
     */
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination2(0, target, candidates, ans, ds);
        return ans;
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