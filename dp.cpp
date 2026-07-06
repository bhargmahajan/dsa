#include <bits/stdc++.h>

using namespace std;

/*
    @author: bhargmahajan
    @description: Solve DP problems
*/
class DP
{
public:
    /*
     * @brief Solves the climb stairs problem using dynamic programming
     * @param n The number of stairs
     * @return The number of distinct ways to reach the top
     * @time complexity: O(n)
     * @space complexity: O(1)
     */
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;

        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++)
        {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }

        return curr;
    }

    /*
     * @brief Solves the frog jump problem using dynamic programming
     * @param height Vector containing the heights of the platforms
     * @return The minimum energy required to reach the last platform
     * @time complexity: O(n) where n is the number of platforms
     * @space complexity: O(1) as we are using only a constant amount of space to store the previous two results
     */
    int frogJump(vector<int> &height)
    {
        if (height.empty())
            return 0;

        int n = height.size();
        if (n == 1)
            return 0;

        int prev = 0, prev2 = 0;
        for (int ind = 1; ind < n; ind++)
        {
            int jumpOne = prev + abs(height[ind] - height[ind - 1]), jumpTwo = INT_MAX;

            if (ind > 1)
                jumpTwo = prev2 + abs(height[ind] - height[ind - 2]);

            prev2 = prev;
            prev = min(jumpOne, jumpTwo);
        }

        return prev;
    }

    int solveUtil(int n, vector<int> &height, vector<int> &dp, int k)
    {
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int steps = INT_MAX;

            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                {
                    int jump = dp[i - j] + abs(height[i] - height[i - j]);
                    steps = min(steps, jump);
                }
            }

            dp[i] = steps;
        }

        return dp[n - 1];
    }

    /*
     * @brief Solves the frog jump problem with a variable jump distance using dynamic programming
     * @param n The number of platforms
     * @param height Vector containing the heights of the platforms
     * @param k The maximum jump distance
     * @return The minimum energy required to reach the last platform
     * @time complexity: O(n * k) where n is the number of platforms and k is the maximum jump distance
     * @space complexity: O(n) for the dp array
     */
    int solve(int n, vector<int> &height, int k)
    {
        vector<int> dp(n, -1);

        return solveUtil(n, height, dp, k);
    }

    /*
     * @brief Solves the house robber problem using dynamic programming
     * @param nums Vector containing the amount of money in each house
     * @return The maximum amount of money that can be robbed without alerting the police
     * @time complexity: O(n) where n is the number of houses
     * @space complexity: O(1) as we are using only a constant amount of space to store the previous two results
     */
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    long long int solveRobbery(vector<int> arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];

        long long int prev = arr[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            long long int curr = max(arr[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    /*
     * @brief Solves the house robber problem with a circular arrangement using dynamic programming
     * @param nums Vector containing the amount of money in each house
     * @return The maximum amount of money that can be robbed without alerting the police
     * @time complexity: O(n) where n is the number of houses
     * @space complexity: O(1) as we are using only a constant amount of space to store the previous two results
     */
    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> ar1, ar2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                ar1.push_back(nums[i]);
            if (i != n - 1)
                ar2.push_back(nums[i]);
        }

        long long int ans1 = solveRobbery(ar1), ans2 = solveRobbery(ar2);
        return max(ans1, ans2);
    }

    /*
     * @brief Solves the unique paths problem using dynamic programming
     * @param m The number of rows in the grid
     * @param n The number of columns in the grid
     * @return The number of unique paths from the top-left corner to the bottom-right corner of the grid
     * @time complexity: O(m * n) where m is the number of rows and n is the number of columns
     * @space complexity: O(n) for the previous row array
     */
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];

                temp[j] = up + left;
            }

            prev = temp;
        }

        return prev[n - 1];
    }

    /*
     * @brief Solves the unique paths with obstacles problem using dynamic programming
     * @param obstacleGrid The grid representing the maze with obstacles
     * @return The number of unique paths from the top-left corner to the bottom-right corner of the grid
     * @time complexity: O(m * n) where m is the number of rows and n is the number of columns
     * @space complexity: O(n) for the previous row array
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);

            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    curr[j] = 0;
                    continue;
                }

                if (i == 0 && j == 0)
                {
                    curr[j] = 1;
                    continue;
                }

                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }

            prev = curr;
        }

        return prev[n - 1];
    }

    /*
     * @brief Solves the minimum path sum problem using dynamic programming
     * @param grid The grid representing the cost of each cell
     * @return The minimum path sum from the top-left corner to the bottom-right corner of the grid
     * @time complexity: O(m * n) where m is the number of rows and n is the number of columns
     * @space complexity: O(n) for the previous row array
     */
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;

                    int left = grid[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;

                    temp[j] = min(up, left);
                }
            }

            prev = temp;
        }

        return prev[n - 1];
    }

    /*
     * @brief Solves the minimum total path in a triangle
     * @param triangle The triangle grid
     * @return The minimum total path sum from top to bottom
     * @time complexity: O(n^2) where n is the number of rows
     * @space complexity: O(n) for the previous row array
     */
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> front(n, 0);

        for (int i = 0; i < n; i++)
            front[i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j], diag = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diag);
            }

            front = curr;
        }

        return front[0];
    }

    /*
     * @brief Checks if there exists a subset with the given target sum
     * @param n The number of elements in the array
     * @param k The target sum
     * @param arr The array of integers
     * @return True if a subset with the given target sum exists, false otherwise
     * @time complexity: O(n * k)
     * @space complexity: O(k)
     */
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<bool> prev(k + 1, false);
        prev[0] = true;

        if (arr[0] <= k)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> curr(k + 1, false);
            curr[0] = true;

            for (int target = 1; target <= k; target++)
            {
                bool notTake = prev[target], take = false;
                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        return prev[k];
    }

    /*
     * @brief Checks if the array can be partitioned into two subsets with equal sum
     * @param nums The array of integers
     * @return True if the array can be partitioned into two subsets with equal sum, false otherwise
     * @time complexity: O(n * k) where n is the number of elements and k is half of the total sum
     * @space complexity: O(k)
     */
    bool canPartition(vector<int> &nums)
    {
        int tot = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            tot += nums[i];

        if (tot % 2 == 1)
            return false;

        int k = tot / 2;
        vector<bool> prev(k + 1, false);
        prev[0] = true;
        if (nums[0] <= k)
            prev[nums[0]] = true;

        for (int index = 1; index < n; index++)
        {
            vector<bool> curr(k + 1, false);
            curr[0] = true;
            for (int target = 1; target <= k; target++)
            {
                bool notTaken = prev[target], taken = false;
                if (nums[index] <= target)
                    taken = prev[target - nums[index]];

                curr[target] = taken || notTaken;
            }

            prev = curr;
        }

        return prev[k];
    }

    /*
     * @brief Counts the number of subsets with the given target sum
     * @param arr The array of integers
     * @param k The target sum
     * @return The number of subsets with the given target sum
     * @time complexity: O(n * k)
     * @space complexity: O(k)
     */
    int countSubsets(vector<int> &arr, int k)
    {
        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        if (arr[0] <= k)
            dp[arr[0]] += 1;

        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> curr(k + 1, 0);
            curr[0] = 1;

            for (int j = 1; j <= k; j++)
            {
                int notTake = dp[j], take = 0;
                if (arr[i] <= j)
                    take = dp[j - arr[i]];
                curr[j] = take + notTake;
            }
            dp = curr;
        }

        return dp[k];
    }

    /*
     * @brief Counts the number of partitions with the given target difference
     * @param arr The array of integers
     * @param d The target difference
     * @return The number of partitions with the given target difference
     * @time complexity: O(n * k)
     * @space complexity: O(k)
     */
    int countPartitions(vector<int> &arr, int d)
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if ((totalSum + d) % 2 != 0 || d > totalSum)
            return 0;

        int k = (totalSum + d) / 2;
        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        if (arr[0] <= k)
            dp[arr[0]] += 1;

        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> curr(k + 1, 0);
            curr[0] = 1;

            for (int j = 1; j <= k; j++)
            {
                int notTake = dp[j], take = 0;
                if (arr[i] <= j)
                    take = dp[j - arr[i]];
                curr[j] = take + notTake;
            }
            dp = curr;
        }

        return dp[k];
    }

    /*
     * @brief Counts the number of ways with the given target sum
     * @param nums The array of integers
     * @param target The target sum
     * @return The number of ways with the given target sum
     * @time complexity: O(n * k)
     * @space complexity: O(k)
     */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total + target) % 2 != 0 || abs(target) > total)
            return 0;

        int newTarget = (total + target) / 2;
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            for (int j = newTarget; j >= num; j--)
                dp[j] += dp[j - num];
        }

        return dp[newTarget];
    }

    /*
     * @brief Counts the number of ways with the given target amount
     * @param coins The array of integers
     * @param amount The target amount
     * @return The number of ways with the given target amount
     * @time complexity: O(n * k)
     * @space complexity: O(k)
     */
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(amount + 1, 0);
            for (int j = 0; j <= amount; j++)
            {
                long notTake = prev[j], take = 0;
                if (coins[i] <= j)
                    take = curr[j - coins[i]];

                curr[j] = notTake + take;
            }

            prev = curr;
        }

        return prev[amount];
    }

    /*
     * @brief Counts the number of items the thief can rob at max
     * @param n The size of array of items
     * @param W The total size of knapsack
     * @param val The array that stores the profit of each item
     * @param wt The array that stores the weights of each object
     * @return The maximum profit the thief can obtain by stealing
     * @time complexity: O(n * W)
     * @space complexity: O(W)
     */
    int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt)
    {
        vector<int> curr(W + 1, 0);
        for (int i = wt[0]; i <= W; i++)
            curr[i] = (i / wt[0]) * val[0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                int notTake = curr[j], take = INT_MIN;
                if (wt[i] <= j)
                    take = val[i] + curr[j - wt[i]];

                curr[j] = max(take, notTake);
            }
        }

        return curr[W];
    }

    /*
     * @brief Print the longest common subsequence
     * @param text1 first string
     * @param text2 Second string
     * @return LCS
     * @time complexity: O(n * n) + O(n + m)
     * @space complexity: O(n * m)
     */
    string longestCommonSubsequence(string &text1, string &text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = n, j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                ans += text1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    /*
     * @brief Calculates the length of the longest common substring
     * @param str1 First string
     * @param str2 Second string
     * @return Length of the longest common substring
     * @time complexity: O(n * m)
     * @space complexity: O(m)
     */
    int longestCommonSubstr(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return ans;
    }

    int lcs(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }

    /*
     * @brief Calculates the length of the longest palindromic subsequence
     * @param s Input string
     * @return Length of the longest palindromic subsequence
     * @time complexity: O(n*m)
     * @space complexity: O(m)
     */
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());

        return lcs(s, t);
    }

    int lcs(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }

    /*
     * @brief Calculates the minimum number of insertions needed to make a string palindrome
     * @param s Input string
     * @return Minimum number of insertions
     * @time complexity: O(n*n)
     * @space complexity: O(n)
     */
    int minInsertions(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());
        return s.size() - lcs(s, t);
    }

    /*
     * @brief Calculates the maximum profit from buying and selling stocks
     * @param prices Vector of stock prices
     * @return Maximum profit
     * @time complexity: O(2n)
     * @space complexity: O(1)
     */
    int maxProfit(vector<int> &prices)
    {
        vector<long> ahead(2, 0), curr(2, 0);
        ahead[0] = ahead[1] = 0;

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                if (j == 0)
                    curr[j] = max(0 + ahead[0], -prices[i] + ahead[1]);
                if (j == 1)
                    curr[j] = max(0 + ahead[1], prices[i] + ahead[0]);
            }
            ahead = curr;
        }

        return curr[0];
    }

    /*
     * @brief Calculates the maximum profit from buying and selling stocks with at most two transactions
     * @param prices Vector of stock prices
     * @return Maximum profit
     * @time complexity: O(6n)
     * @space complexity: O(1)
     */
    int maxProfit2(vector<int> &prices)
    {
        vector<vector<int>> ahead(2, vector<int>(3, 0)),
            curr(2, vector<int>(3, 0));

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int c = 1; c <= 2; c++)
                {
                    if (j == 0)
                        curr[j][c] =
                            max(0 + ahead[0][c], -prices[i] + ahead[1][c]);
                    if (j == 1)
                        curr[j][c] =
                            max(0 + ahead[1][c], prices[i] + ahead[0][c - 1]);
                }
            }
            ahead = curr;
        }

        return curr[0][2];
    }
};

int main()
{
    DP dp;
    string s1 = "abcjklp";
    string s2 = "acjkp";

    cout << "The Length of Longest Common Substring is " << dp.longestCommonSubstr(s1, s2) << endl;

    return 0;
}