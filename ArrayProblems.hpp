#ifndef ARRAYPROBLEMS_H
#define ARRAYPROBLEMS_H

#include <bits/stdc++.h>

using namespace std;

/*
 * @author: Bharg Mahajan
 * @description: This class contains array functions.
 */
class ArrayProblems
{
public:
    /*
     * @brief Calculates the sum of elements in an array.
     * @param arr The array of integers.
     * @param n The number of elements in the array.
     * @return The sum of the elements in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int sum(int arr[], int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += arr[i];

        return sum;
    }

    /*
     * @brief Counts the number of odd elements in an array.
     * @param arr The array of integers.
     * @param n The number of elements in the array.
     * @return The count of odd elements in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int countOdd(int arr[], int n)
    {
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
                cnt++;
        }

        return cnt;
    }

    /*
     * @brief Checks if an array is sorted in non-decreasing order.
     * @param arr The array of integers.
     * @param n The number of elements in the array.
     * @return True if the array is sorted, false otherwise.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    bool arraySortedOrNot(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                return false;
        }

        return true;
    }

    /*
     * @brief Reverses the elements of an array in place.
     * @param arr The array of integers.
     * @param n The number of elements in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    void reverseArray(int arr[], int n)
    {
        int i = 0, j = n - 1;

        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    /*
     * @brief Performs a linear search for a target value in an array.
     * @param nums The array of integers.
     * @param target The value to search for.
     * @return The index of the target value if found, otherwise -1.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int linearSearch(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }

        return -1;
    }

    /*
     * @brief Finds the largest element in an array.
     * @param nums The array of integers.
     * @return The largest element in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int largestElement(vector<int> &nums)
    {
        int res = INT_MIN;

        for (int it : nums)
        {
            if (it > res)
                res = it;
        }

        return res;
    }

    /*
     * @brief Finds the second largest element in an array.
     * @param nums The array of integers.
     * @return The second largest element in the array. If there is no second largest element, returns -1.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int secondLargestElement(vector<int> &nums)
    {
        int scnd = INT_MIN, first = INT_MIN;

        for (int it : nums)
        {
            if (it > first)
            {
                scnd = first;
                first = it;
            }
            else if (it < first && it > scnd)
                scnd = it;
        }

        return scnd == INT_MIN ? -1 : scnd;
    }

    /*
     * @brief Finds the maximum number of consecutive 1's in a binary array.
     * @param nums The binary array (containing only 0's and 1's).
     * @return The maximum number of consecutive 1's in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0, cnt = 0;

        for (int it : nums)
        {
            if (it == 1)
            {
                cnt++;
                res = max(res, cnt);
            }
            else
                cnt = 0;
        }

        return res;
    }

    /*
     * @brief Rotates an array to the left by one position.
     * @param nums The array of integers.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    void rotateArrayByOne(vector<int> &nums)
    {
        int temp = nums[0];

        for (int i = 1; i < nums.size(); i++)
            nums[i - 1] = nums[i];

        nums[nums.size() - 1] = temp;
    }

    /*
     * @brief Rotates an array to the right by k positions.
     * @param nums The array of integers.
     * @param k The number of positions to rotate the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    void rotateArray(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }

    /*
     * @brief Moves all zeroes in an array to the end while maintaining the relative order of non-zero elements.
     * @param nums The array of integers.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }

    /*
     * @brief Removes duplicates from a sorted array in place and returns the new length of the array.
     * @param nums The sorted array of integers.
     * @return The new length of the array after removing duplicates.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int removeDuplicates(vector<int> &nums)
    {
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }

    /*
     * @brief Finds the missing number in an array containing numbers from 0 to n.
     * @param nums The array of integers containing numbers from 0 to n with one number missing.
     * @return The missing number in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int nSum = n * (n + 1) / 2, sum = 0;
        for (int it : nums)
            sum += it;

        return nSum - sum;
    }

    /*
     * @brief Finds the union of two sorted arrays and returns it as a new array.
     * @param nums1 The first sorted array of integers.
     * @param nums2 The second sorted array of integers.
     * @return A new array containing the union of the two input arrays.
     * @time_complexity: O(n + m), where n and m are the sizes of the two input arrays.
     * @space_complexity: O(n + m) for the result array.
     */
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2)
        {
            int curr;
            if (nums1[i] < nums2[j])
            {
                curr = nums1[i];
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                curr = nums2[j];
                j++;
            }
            else
            {
                curr = nums1[i];
                j++;
                i++;
            }

            if (res.empty() || res.back() != curr)
                res.push_back(curr);
        }

        while (i < n1)
        {
            if (res.empty() || res.back() != nums1[i])
                res.push_back(nums1[i]);
            i++;
        }

        while (j < n2)
        {
            if (res.empty() || res.back() != nums2[j])
                res.push_back(nums2[j]);
            j++;
        }

        return res;
    }

    /*
     * @brief Finds the intersection of two sorted arrays and returns it as a new array.
     * @param nums1 The first sorted array of integers.
     * @param nums2 The second sorted array of integers.
     * @return A new array containing the intersection of the two input arrays.
     * @time_complexity: O(n + m), where n and m are the sizes of the two input arrays.
     * @space_complexity: O(min(n, m)) for the result array.
     */
    vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return res;
    }
};

#endif