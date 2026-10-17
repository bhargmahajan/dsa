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

    /*
     * @brief Finds the majority element in an array (the element that appears more than n/2 times).
     * @param nums The array of integers.
     * @return The majority element in the array. If no majority element exists, returns -1.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int majorityElement(vector<int> &nums)
    {
        int res = 0, freq = 0;

        for (int it : nums)
        {
            if (freq == 0)
                res = it;

            if (it == res)
                freq++;
            else
                freq--;
        }

        return res;
    }

    /*
     * @brief Finds all the leaders in an array (elements that are greater than all elements to their right).
     * @param nums The array of integers.
     * @return A vector containing all the leaders in the array.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(k), where k is the number of leaders found.
     */
    vector<int> leaders(vector<int> &nums)
    {
        int n = nums.size();
        int leader = nums[n - 1];
        vector<int> res;
        res.push_back(leader);

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > leader)
            {
                leader = nums[i];
                res.push_back(leader);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }

    /*
     * @brief Rearranges an array such that positive and negative numbers are placed alternatively.
     * @param nums The array of integers.
     * @return A new array with positive and negative numbers arranged alternately.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(n) for the result array.
     */
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int odd = 1, even = 0;
        vector<int> res(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                res[even] = nums[i];
                even += 2;
            }
            else
            {
                res[odd] = nums[i];
                odd += 2;
            }
        }

        return res;
    }

    /*
     * @brief Print matrix in spiral order.
     * @param matrix The 2D vector representing the matrix.
     * @return A vector containing the elements of the matrix in spiral order.
     * @time_complexity: O(m * n), where m is the number of rows and n is the number of columns.
     * @space_complexity: O(m * n) for the result array.
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int top = 0, bottom = matrix.size() - 1, left = 0,
            right = matrix[0].size() - 1;
        vector<int> res;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }

        return res;
    }

    /*
     * @brief Calculates the value at a specific position in Pascal's Triangle.
     * @param r The row number (1-indexed).
     * @param c The column number (1-indexed).
     * @return The value at the specified position in Pascal's Triangle.
     * @time_complexity: O(c), where c is the column number.
     * @space_complexity: O(1)
     */
    int pascalTriangleI(int r, int c)
    {
        r--;
        c--;
        int res = 1;

        for (int i = 0; i < c; i++)
            res = (res * (r - i)) / (i + 1);

        return res;
    }

    /*
     * @brief Finds two indices in an array such that the elements at those indices add up to a specific target.
     * @param nums The array of integers.
     * @param target The target sum.
     * @return A vector containing the two indices. If no such indices exist, returns {-1, -1}.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(n) for the hash map.
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];

            if (mp.find(temp) != mp.end()) return {mp[temp], i};

            mp[nums[i]] = i;
        }

        return {-1, -1};
    }

    /*
     * @brief Finds all unique triplets in an array that sum up to zero.
     * @param nums The array of integers.
     * @return A vector of vectors containing all unique triplets that sum up to zero.
     * @time_complexity: O(n^2), where n is the number of elements in the array.
     * @space_complexity: O(1) for the result array (not counting the space used for the output).
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return res;
    }

    /*
     * @brief Finds all unique quadruplets in an array that sum up to a specific target.
     * @param nums The array of integers.
     * @param target The target sum.
     * @return A vector of vectors containing all unique quadruplets that sum up to the target.
     * @time_complexity: O(n^3), where n is the number of elements in the array.
     * @space_complexity: O(1) for the result array (not counting the space used for the output).
     */
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int k = 0; k < n - 3; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;

            for (int i = k + 1; i < n - 2; i++)
            {
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;

                int left = i + 1, right = n - 1;
                while (left < right)
                {
                    int sum = nums[k] + nums[i] + nums[left] + nums[right];

                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        res.push_back({nums[k], nums[i], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1])
                            left++;

                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }

        return res;
    }

    /*
     * @brief Sorts an array containing only 0's, 1's, and 2's in place.
     * @param nums The array of integers containing only 0's, 1's, and 2's.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    void sortZeroOneTwo(vector<int> &nums)
    {
        int left = 0, i = 0, right = nums.size() - 1;

        while (i <= right)
        {
            if (nums[i] == 0)
            {
                swap(nums[left], nums[i]);
                i++;
                left++;
            }
            else if (nums[i] == 1)
                i++;
            else
            {
                swap(nums[i], nums[right]);
                right--;
            }
        }
    }

    /*
     * @brief Finds the contiguous subarray with the largest sum in an array.
     * @param nums The array of integers.
     * @return The largest sum of any contiguous subarray.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0], sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            res = max(res, sum);
        }

        return res;
    }

    /*
     * @brief Rearranges an array into its next lexicographical permutation.
     * @param nums The array of integers.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int pivot = n - 2;

        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1])
            pivot--;

        if (pivot < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int i = n - 1;
        while (nums[i] <= nums[pivot])
            i--;

        swap(nums[pivot], nums[i]);
        reverse(nums.begin() + pivot + 1, nums.end());
    }

    /*
     * @brief Finds all elements in an array that appear more than n/3 times.
     * @param nums The array of integers.
     * @return A vector containing all elements that appear more than n/3 times.
     * @time_complexity: O(n), where n is the number of elements in the array.
     * @space_complexity: O(1)
     */
    vector<int> majorityElementTwo(vector<int> &nums)
    {
        int el1 = nums[0], el2 = nums[0], cnt1 = 0, cnt2 = 0;

        for (int it : nums)
        {
            if (el1 == it)
                cnt1++;
            else if (el2 == it)
                cnt2++;
            else if (cnt1 == 0)
            {
                el1 = it;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                el2 = it;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        int verify1 = 0, verify2 = 0;
        for (int it : nums)
        {
            if (it == el1)
                verify1++;
            else if (it == el2)
                verify2++;
        }

        int thresh = nums.size() / 3;
        vector<int> res;
        if (verify1 > thresh)
            res.push_back(el1);
        if (el1 != el2 && verify2 > thresh)
            res.push_back(el2);

        return res;
    }

    /*
     * @brief Rotates a square matrix by 90 degrees clockwise in place.
     * @param matrix The 2D vector representing the square matrix.
     * @time_complexity: O(n^2), where n is the number of rows (or columns) in the matrix.
     * @space_complexity: O(1)
     */
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }

    /*
     * @brief Sets entire row and column to zero if an element in the matrix is zero.
     * @param matrix The 2D vector representing the matrix.
     * @time_complexity: O(m * n), where m is the number of rows and n is the number of columns.
     * @space_complexity: O(1)
     */
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        bool rowZero = false, colZero = false;

        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == 0)
                rowZero = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                colZero = true;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (rowZero)
        {
            for (int i = 0; i < m; i++)
                matrix[0][i] = 0;
        }

        if (colZero)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};

#endif