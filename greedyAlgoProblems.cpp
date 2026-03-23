#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

/*
    @description: class to solve greedy algorithm related problems
*/
class GreedyAlgorithmProblems
{
public:
    /*
        @description: find the maximum number of children that can be content with the given cookies
        @param: g: vector of integers representing the greed factor of each child
        @param: s: vector of integers representing the size of each cookie
        @return: maximum number of content children
        @time complexity: O(n log n + m log m) where n is the size of g and m is the size of s
        @space complexity: O(1)
    */
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
                i++;
            j++;
        }

        return i;
    }

    /*
        @description: find the maximum value that can be put in a knapsack of given capacity
        @param: val: vector of integers representing the value of each item
        @param: wt: vector of integers representing the weight of each item
        @param: cap: integer representing the capacity of the knapsack
        @return: maximum value that can be put in the knapsack
        @time complexity: O(n log n) where n is the size of val and wt
        @space complexity: O(n)
    */
    double fractionalKnapsack(vector<int> val, vector<int> wt, int cap)
    {
        vector<pair<double, int>> ratio;
        for (int i = 0; i < val.size(); i++)
            ratio.push_back({(double)val[i] / wt[i], i});

        sort(ratio.begin(), ratio.end());

        double totalValue = 0.0;
        for (int i = ratio.size() - 1; i >= 0; i--)
        {
            int idx = ratio[i].second;
            if (cap >= wt[idx])
            {
                totalValue += val[idx];
                cap -= wt[idx];
            }
            else
            {
                totalValue += ratio[i].first * cap;
                break;
            }
        }
        return totalValue;
    }

    /*
        @description: find the minimum number of coins needed to make up a given amount
        @param: coins: vector of integers representing the denominations of the coins
        @param: amount: integer representing the total amount to be made up
        @return: minimum number of coins needed to make up the amount, or -1 if it is not possible
        @time complexity: O(n * amount) where n is the size of coins
        @space complexity: O(amount)
    */
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = prev[target];
                int take = 1e9;

                if (coins[ind] <= target)
                    take = 1 + cur[target - coins[ind]];
                cur[target] = min(notTake, take);
            }

            prev = cur;
        }

        int ans = prev[amount];
        if (ans >= 1e9)
            return -1;

        return ans;
    }

    /*
        @description: determine if we can provide correct change for each customer at a lemonade stand
        @param: bills: vector of integers representing the bills given by customers
        @return: true if we can provide correct change for all customers, false otherwise
        @time complexity: O(n) where n is the size of bills
        @space complexity: O(1)
    */
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10)
            {
                if (five > 0)
                {
                    ten++;
                    five--;
                }
                else
                    return false;
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }

        return true;
    }

    /*
        @description: check if a string of parentheses and asterisks is valid
        @param: s: string representing the input
        @return: true if the string is valid, false otherwise
        @time complexity: O(n) where n is the length of s
        @space complexity: O(1)
    */
    bool checkValidString(string s)
    {
        int minOp = 0, maxOp = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                minOp++;
                maxOp++;
            }
            else if (c == ')')
            {
                minOp--;
                maxOp--;
            }
            else
            {
                minOp--;
                maxOp++;
            }

            if (maxOp < 0)
                return false;

            minOp = max(minOp, 0);
        }

        return minOp == 0;
    }

    /*
        @description: find the maximum number of meetings that can be attended given their start and end times
        @param: start: vector of integers representing the start times of the meetings
        @param: end: vector of integers representing the end times of the meetings
        @return: vector of integers representing the indices of the meetings that can be attended
        @time complexity: O(n log n) where n is the size of start and end
        @space complexity: O(n)
    */
    vector<int> maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<tuple<int, int, int>> meets;
        for (int i = 0; i < start.size(); i++)
            meets.push_back({end[i], start[i], i + 1});

        vector<int> ans;
        sort(meets.begin(), meets.end());
        int lastOccu = -1;

        for (auto m : meets)
        {
            int s = get<1>(m), e = get<0>(m), idx = get<2>(m);

            if (s > lastOccu)
            {
                ans.push_back(idx);
                lastOccu = e;
            }
        }

        return ans;
    }

    /*
        @description: determine if we can jump to the last index of an array given the maximum jump length at each index
        @param: nums: vector of integers representing the maximum jump length at each index
        @return: true if we can reach the last index, false otherwise
        @time complexity: O(n) where n is the size of nums
        @space complexity: O(1)
    */
    bool canJump(vector<int> &nums)
    {
        int maxInd = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (maxInd < i)
                return false;

            maxInd = max(maxInd, i + nums[i]);
        }

        return true;
    }

    /*
        @description: find the minimum number of jumps needed to reach the last index of an array given the maximum jump length at each index
        @param: nums: vector of integers representing the maximum jump length at each index
        @return: minimum number of jumps needed to reach the last index
        @time complexity: O(n) where n is the size of nums
        @space complexity: O(1)
    */
    int jump(vector<int> &nums)
    {
        int maxFar = 0, currEnd = 0, jumps = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxFar = max(maxFar, i + nums[i]);
            if (i == currEnd)
            {
                jumps++;
                currEnd = maxFar;
            }
        }

        return jumps;
    }

    int countPlatforms(int n, int arr[], int dep[])
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms = 1, result = 1, i = 1, j = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            else
            {
                platforms--;
                j++;
            }
            result = max(result, platforms);
        }

        return result;
    }

    /*
        @description: find the maximum profit that can be earned by scheduling jobs with given deadlines and profits
        @param: arr: array of Job structures representing the jobs to be scheduled
        @param: n: integer representing the number of jobs
        @return: pair of integers representing the number of jobs done and the total profit earned
        @time complexity: O(n log n) where n is the number of jobs
        @space complexity: O(n)
    */
    pair<int, int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });

        int maxD = 0;
        for (int i = 0; i < n; i++)
            maxD = max(maxD, arr[i].dead);

        int slot[maxD + 1];
        for (int i = 0; i <= maxD; i++)
            slot[i] = -1;

        int jobs = 0, profit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    jobs++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }

        cout << jobs << " " << profit << endl;
        return make_pair(jobs, profit);
    }

    /**
        @description: find the minimum number of candies needed to distribute to children based on their ratings
        @param: ratings: vector of integers representing the ratings of the children
        @return: minimum number of candies needed to distribute
        @time complexity: O(n) where n is the size of ratings
        @space complexity: O(1)
    */
    int candy(vector<int> &ratings)
    {
        int n = ratings.size(), res = n, i = 1;

        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                i++;
                continue;
            }

            int peak = 0;

            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                res += peak;
                i++;
            }

            int val = 0;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                val++;
                res += val;
                i++;
            }

            res -= min(peak, val);
        }

        return res;
    }

    /**
     * @description: calculate the average waiting time for a list of jobs
     * @param: jobs: vector of integers representing the processing times of the jobs
     * @return: float representing the average waiting time
     * @time complexity: O(n log n) where n is the number of jobs
     * @space complexity: O(1)
     */
    float calculateAverageWaitTime(vector<int> &jobs)
    {
        sort(jobs.begin(), jobs.end());
        int wait = 0, total = 0;

        for (int i = 0; i < jobs.size(); i++)
        {
            wait += total;
            total += jobs[i];
        }

        return (float)wait / jobs.size();
    }

    /**
        @description: insert a new interval into a list of non-overlapping intervals and merge if necessary
        @param: intervals: vector of vectors of integers representing the existing intervals
        @param: newInterval: vector of integers representing the new interval to be inserted
        @return: vector of vectors of integers representing the merged intervals after insertion
        @time complexity: O(n) where n is the number of existing intervals
        @space complexity: O(n) for the result vector
    */
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }

    /**
        @description: find the minimum number of intervals to remove to make the rest of the intervals non-overlapping
        @param: intervals: vector of vectors of integers representing the intervals
        @return: integer representing the minimum number of intervals to remove
        @time complexity: O(n log n) where n is the number of intervals
        @space complexity: O(1)
    */
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (end > intervals[i][0])
                res++;
            else
                end = intervals[i][1];
        }

        return res;
    }
};

int main()
{
    GreedyAlgorithmProblems gap;

    return 0;
}