#ifndef HASHPROBLEMS_H
#define HASHPROBLEMS_H

#include <bits/stdc++.h>

using namespace std;

/*
 * @author: Bharg Mahajan
 * @description: This class contains hash functions.
 */
class HashProblems
{
    /*
     * @brief Finds the most frequent element in a vector of integers.
     * @param nums The vector of integers.
     * @return The most frequent element in the vector. If there are multiple elements with the same frequency, returns the smallest one.
     * @time_complexity: O(n), where n is the number of elements in the vector.
     * @space_complexity: O(n), where n is the number of unique elements in the vector.
     */
    int mostFrequentElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int res = nums[0], maxFreq = 0;

        for (int it : nums)
        {
            int curr = ++mp[it];

            if (curr > maxFreq || (curr == maxFreq && it < res))
            {
                maxFreq = curr;
                res = it;
            }
        }

        return res;
    }

    /*
     * @brief Finds the second most frequent element in a vector of integers.
     * @param nums The vector of integers.
     * @return The second most frequent element in the vector. If there is no second most frequent element, returns -1.
     * @time_complexity: O(n), where n is the number of elements in the vector.
     * @space_complexity: O(n), where n is the number of unique elements in the vector.
     */
    int secondMostFrequentElement(vector<int> &nums)
    {
        if (nums.empty())
            return -1;

        unordered_map<int, int> mp;

        for (int it : nums)
            mp[it]++;

        int firstFreq = 0, scndFreq = 0, firstEl = 0, scndEl = 0;
        bool hasFirst = false, hasScnd = false;

        for (auto it : mp)
        {
            int curEl = it.first, curFreq = it.second;

            if (!hasFirst)
            {
                firstFreq = curFreq;
                firstEl = curEl;
                hasFirst = true;
            }
            else if (curFreq > firstFreq)
            {
                scndFreq = firstFreq;
                scndEl = firstEl;
                hasScnd = true;
                firstEl = curEl;
                firstFreq = curFreq;
            }
            else if (curFreq == firstFreq)
            {
                if (curEl < firstEl)
                    firstEl = curEl;
            }
            else if (!hasScnd || curFreq > scndFreq || (curFreq == scndFreq && curEl < scndEl))
            {
                scndFreq = curFreq;
                scndEl = curEl;
                hasScnd = true;
            }
        }

        if (!hasScnd)
            return -1;

        return scndEl;
    }

    /*
     * @brief Calculates the sum of the highest and lowest frequency elements in a vector of integers.
     * @param nums The vector of integers.
     * @return The sum of the highest and lowest frequency elements in the vector.
     * @time_complexity: O(n), where n is the number of elements in the vector.
     * @space_complexity: O(n), where n is the number of unique elements in the vector.
     */
    int sumHighestAndLowestFrequency(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int it : nums)
            mp[it]++;

        int maxFreq = INT_MIN, minFreq = INT_MAX;

        for (auto it : mp)
        {
            int freq = it.second;

            if (freq > maxFreq)
                maxFreq = freq;

            if (freq < minFreq)
                minFreq = freq;
        }

        return maxFreq + minFreq;
    }

    /*
     * @brief Finds the maximum frequency of an element in a vector of integers after performing at most k increment operations.
     * @param nums The vector of integers.
     * @param k The maximum number of increment operations allowed.
     * @return The maximum frequency of an element in the vector after performing at most k increment operations.
     * @time_complexity: O(n log n), where n is the number of elements in the vector.
     * @space_complexity: O(1)
     */
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int l = 0, maxFreq = 0;
        long long sum = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];

            while (sum + k < (long long)nums[r] * (r - l + 1))
                sum -= nums[l++];

            maxFreq = max(maxFreq, r - l + 1);
        }

        return maxFreq;
    }
};

#endif