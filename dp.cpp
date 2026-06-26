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
};

int main()
{
    DP dp;
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (dp.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}