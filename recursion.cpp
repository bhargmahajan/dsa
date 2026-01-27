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

    void helper(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &result)
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

    void findCombination(int index, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
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

    void findCombination2(int index, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
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

    /*
    @description: find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates mayonly be used once in the combination.
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

    void helperSubset(vector<int> &nums, int index, vector<int> &curr,
                      vector<vector<int>> &result)
    {
        result.push_back(curr);

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            helperSubset(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }

    /*
     * @description: generate all possible subsets of a set of integers that may contain duplicates
     * @param {vector<int>} nums - input set of integers that may contain duplicates
     * @return {vector<vector<int>>} - list of all possible subsets
     * @time complexity: O(2^n)
     * @space complexity: O(n) for storing the result
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helperSubset(nums, 0, curr, res);
        return res;
    }

    void findCombination3(int index, int target, int k, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }

        if (target <= 0 || ds.size() > k)
            return;

        for (int i = index; i <= 9; i++)
        {
            if (i <= target)
            {
                ds.push_back(i);
                findCombination3(i + 1, target - i, k, ans, ds);
                ds.pop_back();
            }
            else
                break;
        }
    }

    /*
     * @description: find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers
     * @param {int} k - number of elements in each combination
     * @param {int} n - target sum
     * @return {vector<vector<int>>} - list of all unique combinations
     * @time complexity: O(2^9 * k)
     * @space complexity: O(k) for storing the current combination
     */
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination3(1, n, k, ans, ds);
        return ans;
    }

    void func(int ind, string digits, string s, vector<string> &ans, string combos[])
    {
        if (ind == digits.size())
        {
            ans.push_back(s);
            return;
        }

        int digit = digits[ind] - '0';
        for (int i = 0; i < combos[digit].size(); i++)
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
    }

    /*
     * @description: generate all possible letter combinations that the number could represent on a phone keypad
     * @param {string} digits - input string of digits
     * @return {vector<string>} - list of all possible letter combinations
     * @time complexity: O(4^n*n) where n is the number of digits mapping to 3 letters and m is the number of digits mapping to 4 letters
     * @space complexity: O(n) for storing the result
     */
    vector<string> letterCombinations(string digits)
    {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s = "";
        func(0, digits, s, ans, combos);
        return ans;
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void backtrack(int index, string &s, vector<string> &path, vector<vector<string>> &res)
    {
        if (index == s.length())
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    /*
     * @description: partition a string such that every substring of the partition is a palindrome
     * @param {string} s - input string
     * @return {vector<vector<string>>} - list of all possible palindrome partitions
     * @time complexity: O(n * 2^n)
     * @space complexity: O(2^N * N) + O(N) for storing the current partition
     */
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int idx)
    {
        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);
        board[i][j] = temp;

        return found;
    }

    /*
     * @description: determine if a given word exists in a 2D board of characters
     * @param {vector<vector<char>>} board - 2D board of characters
     * @param {string} word - target word to search for
     * @return {bool} - true if the word exists in the board, false otherwise
     * @time complexity: O(m * n * 4^L) where N is the number of cells in the board and L is the length of the word
     * @space complexity: O(L) for the recursion stack
     */
    bool exist(vector<vector<char>> &board, string word)
    {
        int r = board.size(), c = board[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }

    void solve(int col, vector<string> &board, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int r = 0; r < n; r++)
        {
            if (leftRow[r] == 0 && lowerDiagonal[r + col] == 0 && upperDiagonal[n - 1 + col - r] == 0)
            {
                board[r][col] = 'Q';
                leftRow[r] = 1;
                lowerDiagonal[r + col] = 1;
                upperDiagonal[n - 1 + col - r] = 1;

                solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                board[r][col] = '.';
                leftRow[r] = 0;
                lowerDiagonal[r + col] = 0;
                upperDiagonal[n - 1 + col - r] = 0;
            }
        }
    }

    /*
     * @description: solve the N-Queens problem and return all distinct solutions
     * @param {int} n - size of the chessboard and number of queens
     * @return {vector<vector<string>>} - list of all distinct solutions
     * @time complexity: O(N!)
     * @space complexity: O(N) for storing the board and auxiliary arrays
     */
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

        return ans;
    }
};

int main()
{
    Recursion sol;
    double x = 2.0;
    int n = 10;

    double result = sol.myPow(x, n);
    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}