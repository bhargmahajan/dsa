/*
    @author: Bharg Mahajan
    @description: This file contains various queue problems solutions implemented in C++.
*/
#include <bits/stdc++.h>
using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains various queue problems solutions implemented in C++.
*/
class MyQueue
{
    /*
        @description: This function finds the maximum element in each sliding window of size k.
        @param: nums - The input array of integers.
        @param: k - The size of the sliding window.
        @return: A vector containing the maximum element in each sliding window.
        Time Complexity: O(n) where n is the number of elements in the array.
        Space Complexity: O(k) where k is the size of the sliding window.
    */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main()
{
    MyQueue queue;

    return 0;
}