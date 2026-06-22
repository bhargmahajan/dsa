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
};

int main()
{
    DP dp;
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;

    cout << dp.solve(n, height, k) << endl;
    return 0;
}