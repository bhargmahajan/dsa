/*
    @author: Bharg Mahajan
    @description: This file contains various array problems solutions implemented in C++.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains various array problems solutions implemented in C++.
*/
class ArrayProblems
{
    int arr[10] = {0};
    int n = 0, n2 = 0;
    int arr2[10] = {0};

public:
    ArrayProblems(int arr[10], int n, int arr2[10], int n2);

    void printArray(int n);
    void reverseArray(int left, int right);
    void swap(int &a, int &b);

    /*
        Function to find the maximum element in the array
        Time Complexity: O(n)
        Space Complexity: O(1)
        Line Number: 169
    */
    int findMax();
    /*
        Function to find the second maximum element in the array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int findSecondMax();
    /*
        Function to check if the array is sorted
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int checkIfSorted();
    /*
        Function to remove duplicate elements in the sorted array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    void removeDuplicatesSortedArray();
    /*
        Function to remove duplicate elements in the unsorted array
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    void removeDuplicatesUnsortedArray();
    /*
        Function to left rotate the array by one position
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    void rotateByOnePlace();
    /*
        Function to left rotate the array by k position
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    void rotateByKPlace(int k);
    /*
        Function to move zeros to the end
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    void moveZeros();
    /*
        Function to move zeros to the end
        Time Complexity: O(m+n)
        Space Complexity: O(m+n)
    */
    void unionSortedArray();
    /*
        Function to find the missing number
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int missingNumberInUnsortedArray();
    /*
        Function to find the missing number
        Time Complexity: O(n), O(1) for best case
        Space Complexity: O(1)
    */
    int missingNumberInSortedArray();
    /*
        Function to find the missing number
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int consecutiveOnes();
    /*
        Function to find the single number
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int singleElement();
    /*
        Function to find longest subarray with sum k
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int longestSubarrayWithKSum(int k);
    /*
        Function to find the indices with target sum
        Time Complexity: O(n+(n*log n))
        Space Complexity: O(n)
    */
    pair<int, int> targetSum(int k);
    /*
        Function to sort an array of 0s, 1s and 2s
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    void sortOnesTwosAndZeroes();
    /*
        Function to find majority element in an array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int majorityElement();
    /*
        Function to find majority element in an array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int maxSumForSubarray();
    /*
        Function to find maximum profit from stock prices
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int maxProfit();
    /*
        Function to rearrange the array in alternate positive and negative items
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    void alternativePosNeg();
    /*
        Function to find the next permutation of the array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    void nextPermutation(vector<int> &nums);
    /*
        Function to find the leaders in an array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    vector<int> leaders(vector<int> &nums);
    /*
        Function to add 0s in matrix rows and columns
        Time Complexity: O(m*n)
        Space Complexity: O(1)
    */
    void setZeroes(vector<vector<int>> &matrix);
    /*
        Function to find the length of longest consecutive elements sequence
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    int longestConsecutive(vector<int> &nums);
    /*
        Function to rotate an array by 90 degrees clockwise
        Time Complexity: O(n^2)
        Space Complexity: O(1)
    */
    void rotateByNinty(vector<vector<int>> &matrix);
    /*
        Function to print the elements of the matrix in spiral order
        Time Complexity: O(m*n)
        Space Complexity: O(1)
    */
    vector<int> spiralOrder(vector<vector<int>> &matrix);
    /*
        Function to find the total number of subarrays with sum equal to k
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    int subarraySum(vector<int> &nums, int k);
    /*
        Function to generate Pascal's Triangle
        Time Complexity: O(n^2)
        Space Complexity: O(n)
    */
    vector<vector<int>> pascalTriangle(int numRows);
    /*
        Function to find majority elements in an array (appearing more than n/3 times)
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    vector<int> majorityElement(vector<int> &nums);
    /*
        Function to find all unique triplets in the array which gives the sum of zero
        Time Complexity: O(n*log n + n^2)
        Space Complexity: O(1)
    */
    vector<vector<int>> threeSum(vector<int> &nums);
    /*
        Function to find all unique quardlets in the array which gives the target sum
        Time Complexity: O(n*log n + n^3)
        Space Complexity: O(1)
    */
    vector<vector<int>> fourSum(vector<int> &nums, int target);
    /*
        Function to find subarray sum
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int subArraySum(vector<int> &nums);
    /*
        Function to find subarray xor
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int subArrayXor(vector<int> &nums, int k);
    /*
        Function to merge intervals
        Time Complexity: O(n)
        Space Complexity: O(n)
    */
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals);
    /*
        Function to merge two sorted arrays
        Time Complexity: O(m+n)
        Space Complexity: O(1)
    */
    void mergeArrays(vector<int> &nums1, int m, vector<int> &nums2, int n);
    /*
        Function to find missing and duplicate number in an array
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    vector<int> repeatingAndMissingNumber(vector<int> &nums);
    /*
        Function to count inversions in an array
        Time Complexity: O(n log n)
        Space Complexity: O(n)
    */
    int inversions(vector<int> &nums, int low, int high);
    int merge(vector<int> &nums, int low, int mid, int high);
    /*
        Function to count reverse pairs in an array
        Time Complexity: O(n log n)
        Space Complexity: O(n)
    */
    int reversePairs(vector<int> &nums);
    int divideArrayForPairs(vector<int> &nums, int low, int high);
    int countPairs(vector<int> &nums, int low, int mid, int high);
    void mergeArrayForPairs(vector<int> &nums, int left, int mid, int right);
    /*
        Function to get the maximum subarray product
        Time Complexity: O(2n*log n)
        Space Complexity: O(1)
    */
    int maxProduct(vector<int> &nums);
    /*
        Function to find the lower bound of a target in a sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int lowerBound(vector<int> &nums, int target);
    /*
        Function to find the upper bound of a target in a sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int upperBound(vector<int> &nums, int target);
    /*
        Function to find floor and ceil of a target in a sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    vector<int> floorAndCeil(vector<int> &nums, int target);
    /*
        Function to search for a range of target in a sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    vector<int> searchRange(vector<int> &nums, int target);
    int findBoundIndex(vector<int> &nums, int target);
    /*
        Function to find frequency of a target in a sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int frequency(vector<int> &nums, int target);
    /*
        Function to search for a target in a rotated sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int searchInRotatedArrayOne(vector<int> &nums, int target);
    /*
        Function to find minimum in a rotated sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int findMin(vector<int> &nums);
    /*
        Function to find the rotation count in a rotated sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int rotationCount(vector<int> &nums);
    /*
        Function to find the single non-duplicate element in a sorted array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int singleNonDuplicate(vector<int> &nums);
    /*
        Function to find a peak element in an array
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int findPeakElement(vector<int> &nums);
    /*
        Function to find the square root of a number
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int squareRoot(int x);
    /*
        Function to find the nth root of a number
        Time Complexity: O(log n)
        Space Complexity: O(1)
    */
    int nthRoot(int num1, int num2);
    /*
        Function to find the minimum eating speed to finish piles of bananas in h hours
        Time Complexity: O(n log m) where m is the maximum number of bananas in a pile
        Space Complexity: O(1)
    */
    int minEatingSpeed(vector<int> &piles, int h);
    /*
        Function to find the minimum number of days to make m bouquets
        Time Complexity: O(n log m) where m is the maximum number of days in bloomDay
        Space Complexity: O(1)
    */
    int minDays(vector<int> &bloomDay, int m, int k);
    /*
        Function to find the smallest divisor such that the sum of the division results is less than or equal to threshold
        Time Complexity: O(n log m) where m is the maximum number in nums
        Space Complexity: O(1)
    */
    int ArrayProblems::smallestDivisor(vector<int> &nums, int threshold);
    /*
        Function to find the least weight capacity of a ship to ship all packages within days
        Time Complexity: O(n log m) where m is the sum of weights
        Space Complexity: O(1)
    */
    int shipWithinDays(vector<int> &weights, int days);
    /*
        Function to find the kth missing positive number
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    int findKthPositive(vector<int> &arr, int k);
    /*
        Function to split an array into k subarrays with minimum maximum sum
        Time Complexity: O(n log sum(arr[])-max(arr[])+1)) where m is the sum of elements
        Space Complexity: O(1)
    */
    int splitArray(vector<int> &nums, int k);
    /*
        Function to find the median of two sorted arrays
        Time Complexity: O(log(min(n, m)))
        Space Complexity: O(1)
    */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
    /*
        Function to search for a target in a 2D matrix
        Time Complexity: O(log(m*n))
        Space Complexity: O(1)
    */
    bool searchMatrix(vector<vector<int>> &matrix, int target);

    ~ArrayProblems();
};

ArrayProblems::ArrayProblems(int arr[10], int n, int arr2[10], int n2)
{
    this->n = n;
    this->n2 = n2;

    for (int i = 0; i < this->n; i++)
        this->arr[i] = arr[i];

    for (int i = 0; i < this->n2; i++)
        this->arr2[i] = arr2[i];

    cout << "Constructor called." << endl;
}

void ArrayProblems::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ArrayProblems::reverseArray(int left, int right)
{
    while (left <= right)
    {
        swap(this->arr[left], this->arr[right]);
        left++;
        right--;
    }
}

void ArrayProblems::printArray(int n = 10)
{
    if (n <= 0)
    {
        cout << "Array is empty." << endl;
        return;
    }

    cout << "Array is:" << endl;
    for (int i = 0; i < n; i++)
        cout << this->arr[i] << " ";
    cout << endl;
}

int ArrayProblems::findMax()
{
    if (this->n < 1)
        return -1;

    int max = this->arr[0];
    for (int i = 1; i < this->n; i++)
    {
        if (this->arr[i] > max)
            max = this->arr[i];
    }
    return max;
}

int ArrayProblems::findSecondMax()
{
    if (this->n < 2)
        return -1;

    int max = this->arr[0];
    int secondMax = max;

    for (int i = 1; i < this->n; i++)
    {
        if (this->arr[i] > max)
        {
            secondMax = max;
            max = this->arr[i];
        }
        else if (this->arr[i] > secondMax && this->arr[i] < max)
            secondMax = this->arr[i];
    }
    return secondMax;
}

int ArrayProblems::checkIfSorted()
{
    bool isSorted = true;

    for (int i = 0; i < this->n - 1; i++)
    {
        if (this->arr[i] > this->arr[i + 1])
        {
            isSorted = false;
            break;
        }
    }

    return isSorted;
}

void ArrayProblems::removeDuplicatesSortedArray()
{
    if (n < 2)
    {
        printArray(n);
        return;
    }

    int i = 0, j = 1;
    while (j < n)
    {
        if (this->arr[i] != this->arr[j])
        {
            i++;
            this->arr[i] = this->arr[j];
        }
        j++;
    }
    printArray(i + 1);
}

void ArrayProblems::removeDuplicatesUnsortedArray()
{
    if (n < 2)
    {
        printArray(n);
        return;
    }

    unordered_map<int, bool> uniques;
    for (int j = 0; j < n; j++)
        uniques[this->arr[j]]++;

    int i = 0;
    for (auto it : uniques)
    {
        this->arr[i] = it.first;
        i++;
    }

    printArray(i);
}

void ArrayProblems::rotateByOnePlace()
{
    if (n < 2)
    {
        printArray(n);
        return;
    }

    int first = this->arr[0];
    for (int i = 0; i < n; i++)
        this->arr[i] = this->arr[i + 1];

    this->arr[n - 1] = first;

    printArray(n);
}

void ArrayProblems::rotateByKPlace(int k)
{
    if (n < 2)
    {
        printArray(this->n);
        return;
    }

    k = k % this->n;

    reverseArray(0, k - 1);
    reverseArray(k, this->n - 1);
    reverseArray(0, this->n - 1);

    printArray(this->n);
}

void ArrayProblems::moveZeros()
{
    if (n == 0)
        return;

    if (n == 1)
    {
        printArray(this->n);
        return;
    }

    int i = 0, j = 1;
    while (j < this->n)
    {
        if (this->arr[i] == 0 && this->arr[j] != 0)
        {
            swap(this->arr[i], this->arr[j]);
            i++;
        }

        if (this->arr[i] != 0)
            i++;
        j++;
    }

    printArray(this->n);
}

void ArrayProblems::unionSortedArray()
{
    int i = 0, j = 0;
    vector<int> Union;

    while (i < this->n && j < this->n2)
    {
        if (this->arr[i] <= this->arr2[j])
        {
            if (Union.size() == 0 || Union.back() != this->arr[i])
                Union.push_back(this->arr[i]);
            i++;
        }
        else
        {
            if (Union.size() == 0 || Union.back() != this->arr2[j])
                Union.push_back(this->arr2[j]);
            j++;
        }
    }
    while (i < this->n)
    {
        if (Union.back() != this->arr[i])
            Union.push_back(this->arr[i]);
        i++;
    }
    while (j < this->n2)
    {
        if (Union.back() != this->arr2[j])
            Union.push_back(this->arr2[j]);
        j++;
    }

    for (int i = 0; i < Union.size(); i++)
        cout << Union[i] << " ";
    cout << endl;
}

int ArrayProblems::missingNumberInUnsortedArray()
{
    int sum = 0;

    for (int i = 0; i < this->n; i++)
        sum += this->arr[i];
    int totalSum = (this->n * (this->n + 1)) / 2;
    return totalSum - sum;
}

int ArrayProblems::missingNumberInSortedArray()
{
    for (int i = 1; i <= this->n; i++)
    {
        if (i != this->arr[i - 1])
            return i;
    }

    return -1;
}

int ArrayProblems::consecutiveOnes()
{
    int count = 0, maxCount = 0;
    for (int i = 0; i < this->n; i++)
    {
        if (this->arr[i] == 0)
            count = 0;
        else
            count++;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int ArrayProblems::singleElement()
{
    int xr = 0;
    for (int i = 0; i <= this->n; i++)
        xr ^= this->arr[i];
    return xr;
}

int ArrayProblems::longestSubarrayWithKSum(int k)
{
    if (this->n == 0)
        return 0;

    int i = 0, j = 1, sum = this->arr[0], res = 0;
    while (j <= this->n)
    {
        if (sum == k)
            res = max(res, j - i);

        if (sum > k)
        {
            sum -= this->arr[i];
            i++;
            if (sum == k)
                res = max(res, j - i);
        }

        sum += this->arr[j];
        j++;
    }

    return res;
}

pair<int, int> ArrayProblems::targetSum(int k)
{
    pair<int, int> res = {-1, -1};
    vector<pair<int, int>> numMap;
    for (int i = 0; i < this->n; i++)
        numMap.push_back({this->arr[i], i});

    sort(numMap.begin(), numMap.end());

    int i = 0, j = this->n - 1;
    while (i < j)
    {
        if (numMap[i].first + numMap[j].first == k)
            return {numMap[i].second, numMap[j].second};
        else if (numMap[i].first + numMap[j].first > k)
            j--;
        else if (numMap[i].first + numMap[j].first < k)
            i++;
    }

    return {-1, -1};
}

void ArrayProblems::sortOnesTwosAndZeroes()
{
    if (this->n == 0)
        return;

    if (this->n == 1)
    {
        printArray(this->n);
        return;
    }

    int low = 0, mid = 0, high = this->n - 1;
    while (mid <= high)
    {
        if (this->arr[mid] == 0)
        {
            swap(this->arr[low], this->arr[mid]);
            low++;
            mid++;
        }
        else if (this->arr[mid] == 1)
        {
            mid++;
        }
        else if (this->arr[mid] == 2)
        {
            swap(this->arr[mid], this->arr[high]);
            high--;
        }
    }

    for (int i = 0; i < this->n; i++)
        cout << this->arr[i] << " ";
    cout << endl;
}

int ArrayProblems::majorityElement()
{
    if (this->n < 2)
        return -1;

    int count = 0, ele;
    for (int i = 0; i < this->n; i++)
    {
        if (count == 0)
        {
            ele = this->arr[i];
            count = 1;
        }
        else if (ele == this->arr[i])
            count++;
        else
            count--;
    }
    return ele;
}

int ArrayProblems::maxSumForSubarray()
{
    if (this->n == 0)
        return 0;
    if (this->n == 1)
        return this->arr[0];

    int maxSum = INT_MIN, sum = 0, i = 0, start = -1, end = -1;
    for (int k = 0; k < this->n; k++)
    {
        if (sum == 0)
            i = k;
        sum += this->arr[k];
        if (sum > maxSum)
        {
            maxSum = sum;
            start = i;
            end = k;
        }
        if (sum < 0)
            sum = 0;
    }

    for (int k = start; k <= end; k++)
        cout << this->arr[k] << " ";
    cout << endl;

    return maxSum;
}

int ArrayProblems::maxProfit()
{
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < this->n; i++)
    {
        if (this->arr[i] < minPrice)
            minPrice = this->arr[i];
        else
            maxProfit = max(maxProfit, this->arr[i] - minPrice);
    }
    return maxProfit;
}

void ArrayProblems::alternativePosNeg()
{
    int j = 0, k = 1;
    vector<int> res(this->n);

    for (int i = 0; i < this->n; i++)
    {
        if (this->arr[i] > 0)
        {
            res[j] = this->arr[i];
            j += 2;
        }
        else
        {
            res[k] = this->arr[i];
            k += 2;
        }
    }

    for (int i = 0; i < this->n; i++)
        cout << res[i] << " ";
    cout << endl;
}

void ArrayProblems::nextPermutation(vector<int> &nums)
{
    int j = nums.size() - 2;
    while (j >= 0)
    {
        if (nums[j + 1] > nums[j])
            break;
        j--;
    }

    if (j == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size() - 1; i > j; i--)
    {
        if (nums[i] > nums[j])
        {
            swap(nums[i], nums[j]);
            break;
        }
    }

    reverse(nums.begin() + j + 1, nums.end());

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

vector<int> ArrayProblems::leaders(vector<int> &nums)
{
    vector<int> result;
    if (nums.empty())
        return result;

    int maxEle = nums[nums.size() - 1];
    result.push_back(maxEle);

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > maxEle)
        {
            maxEle = nums[i];
            result.push_back(maxEle);
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

void ArrayProblems::setZeroes(vector<vector<int>> &matrix)
{
    bool row = false, col = false;
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            col = true;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (matrix[0][i] == 0)
        {
            row = true;
            break;
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    if (row == true)
    {
        for (int i = 0; i < n; i++)
            matrix[0][i] = 0;
    }

    if (col == true)
    {
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }
}

int ArrayProblems::longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    unordered_set<int> temp;
    for (int i = 0; i < nums.size(); i++)
        temp.insert(nums[i]);

    int maxi = 1;
    for (auto itr : nums)
    {
        if (temp.find(itr - 1) == temp.end())
        {
            int count = 1;
            int x = itr;
            while (temp.find(x + 1) != temp.end())
            {
                x++;
                count++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}

void ArrayProblems::rotateByNinty(vector<vector<int>> &matrix)
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

vector<int> ArrayProblems::spiralOrder(vector<vector<int>> &matrix)
{
    int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
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

int ArrayProblems::subarraySum(vector<int> &nums, int k)
{
    int total = 0, sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int rem = sum - k;
        total += mp[rem];
        mp[sum]++;
    }

    return total;
}

vector<vector<int>> ArrayProblems::pascalTriangle(int numRows)
{
    vector<vector<int>> res;
    for (int i = 1; i <= numRows; i++)
    {
        vector<int> temp;
        temp.push_back(1);

        int x = 1;
        for (int j = 1; j < i; j++)
        {
            x = (x * (i - j)) / j;
            temp.push_back(x);
        }
        res.push_back(temp);
    }

    return res;
}

vector<int> ArrayProblems::majorityElement(vector<int> &nums)
{
    int n = nums.size() / 3, el1 = 0, el2 = 0, cnt1 = 0, cnt2 = 0;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            el1 = nums[i];
            cnt1++;
        }
        else if (cnt2 == 0 && nums[i] != el1)
        {
            el2 = nums[i];
            cnt2++;
        }
        else if (el1 == nums[i])
            cnt1++;
        else if (el2 == nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (el1 == nums[i])
            cnt1++;
        if (el2 == nums[i])
            cnt2++;
    }

    if (cnt1 > n)
        res.push_back(el1);
    if (cnt2 > n && el1 != el2)
        res.push_back(el2);

    return res;
}

vector<vector<int>> ArrayProblems::threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum > 0)
                right--;
            else
                left++;
        }
    }
    return res;
}

vector<vector<int>> ArrayProblems::fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1, right = nums.size() - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum > target)
                    right--;
                else
                    left++;
            }
        }
    }
    return res;
}

int ArrayProblems::subArraySum(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == 0)
            maxLen = i + 1;

        else
        {
            if (mp.find(sum) != mp.end())
                maxLen = max(maxLen, i - mp[sum]);
            else
                mp[sum] = i;
        }
    }
    return maxLen;
}

int ArrayProblems::subArrayXor(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int x = 0, count = 0;
    mp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        x ^= nums[i];
        int target = k ^ x;
        if (mp.find(x) != mp.end())
            count++;

        mp[x]++;
    }
    return count;
}

vector<vector<int>> ArrayProblems::mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    for (auto interval : intervals)
    {
        if (res.empty() || res.back()[1] < interval[0])
            res.push_back({interval[0], interval[1]});
        if (res.back()[1] >= interval[0])
            res.back()[1] = max(res.back()[1], interval[1]);
    }
    return res;
}

void ArrayProblems::mergeArrays(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}

vector<int> ArrayProblems::repeatingAndMissingNumber(vector<int> &nums)
{
    vector<int> res(2);
    int nSum = (nums.size() * (nums.size() + 1)) / 2, nSquareSum = (nums.size() * (nums.size() + 1) * (2 * nums.size() + 1)) / 6;
    int tSum = 0, tSquareSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        tSquareSum += (nums[i] * nums[i]);
        tSum += nums[i];
    }

    int diff = tSum - nSum, squareDiff = (tSquareSum - nSquareSum) / diff;
    res[0] = (diff + squareDiff) / 2;
    res[1] = res[0] - diff;

    return res;
}

int ArrayProblems::merge(vector<int> &nums, int left, int mid, int right)
{
    int temp[10];
    int a = left, b = mid + 1, cnt = 0;
    int i = 0;

    while (a <= mid && b <= right)
    {
        if (nums[a] <= nums[b])
            temp[i++] = nums[a++];
        else
        {
            temp[i++] = nums[b++];
            cnt += (mid - a + 1);
        }
    }

    while (a <= mid)
        temp[i++] = nums[a++];

    while (b <= right)
        temp[i++] = nums[b++];

    for (int s = left; s <= right; s++)
        nums[s] = temp[s - left];

    return cnt;
}

int ArrayProblems::inversions(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += inversions(nums, low, mid);
    cnt += inversions(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);

    return cnt;
}

void ArrayProblems::mergeArrayForPairs(vector<int> &nums, int left, int mid, int right)
{
    int a = left, b = mid + 1, i = 0;
    vector<int> temp;
    while (a <= mid && b <= right)
    {
        if (nums[a] <= nums[b])
        {
            temp.push_back(nums[a]);
            a++;
        }
        else
        {
            temp.push_back(nums[b]);
            b++;
        }
    }

    while (a <= mid)
    {
        temp.push_back(nums[a]);
        a++;
    }
    while (b <= right)
    {
        temp.push_back(nums[b]);
        b++;
    }
    for (int s = left; s <= right; s++)
        nums[s] = temp[s - left];
}

int ArrayProblems::countPairs(vector<int> &nums, int low, int mid, int high)
{
    int cnt = 0, right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2 * (long long)nums[right])
            right++;
        cnt += (right - (mid + 1));
    }

    return cnt;
}

int ArrayProblems::divideArrayForPairs(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += divideArrayForPairs(nums, low, mid);
    cnt += divideArrayForPairs(nums, mid + 1, high);
    cnt += countPairs(nums, low, mid, high);
    mergeArrayForPairs(nums, low, mid, high);

    return cnt;
}

int ArrayProblems::reversePairs(vector<int> &nums)
{
    return divideArrayForPairs(nums, 0, nums.size() - 1);
}

int ArrayProblems::maxProduct(vector<int> &nums)
{
    int maxProduct = INT_MIN, start = 1, end = 1, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (start == 0)
            start = 1;
        if (end == 0)
            end = 1;

        start *= nums[i];
        end *= nums[n - i - 1];
        maxProduct = max(maxProduct, max(start, end));
    }

    return maxProduct;
}

int ArrayProblems::lowerBound(vector<int> &nums, int target)
{
    int index = -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] >= target)
        {
            right = mid - 1;
            index = mid;
        }
        else if (nums[mid] < target)
            left = mid + 1;
    }
    return index;
}

int ArrayProblems::upperBound(vector<int> &nums, int target)
{
    int index = nums.size(), left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] > target)
        {
            index = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return index;
}

vector<int> ArrayProblems::floorAndCeil(vector<int> &nums, int target)
{
    int xfloor = nums.size(), xceil = nums.size(), left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] >= target)
        {
            right = mid - 1;
            xceil = nums[mid];
        }
        if (nums[mid] <= target)
        {
            left = mid + 1;
            xfloor = nums[mid];
        }
    }
    vector<int> index = {xfloor, xceil};
    return index;
}

int ArrayProblems::findBoundIndex(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

vector<int> ArrayProblems::searchRange(vector<int> &nums, int target)
{
    vector<int> res;
    res.push_back(findBoundIndex(nums, target));
    res.push_back(findBoundIndex(nums, target + 1) - 1);
    if (res[0] < nums.size() && nums[res[0]] == target)
        return res;

    return {-1, -1};
}

int ArrayProblems::frequency(vector<int> &nums, int target)
{
    vector<int> r = searchRange(nums, target);
    return r[1] - r[0] + 1;
}

int ArrayProblems::searchInRotatedArrayOne(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++;
            right--;
            continue;
        }

        if (nums[left] <= nums[mid])
        {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target <= nums[right] && target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int ArrayProblems::findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;

        if (nums[right] > nums[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return nums[left - 1];
}

int ArrayProblems::rotationCount(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[right] > nums[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}

int ArrayProblems::singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];
    int left = 1, right = nums.size() - 2;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int ArrayProblems::findPeakElement(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int ArrayProblems::squareRoot(int num)
{
    if (num < 2)
        return num;

    int left = 1, right = num / 2;
    int ans = 0;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (mid * mid <= num)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}

int ArrayProblems::nthRoot(int num1, int num2)
{
    int left = 1, right = num2;
    int ans = 0;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        int power = 1;
        for (int i = 1; i <= num1; i++)
        {
            power *= mid;
            if (power > num2)
                break;
        }

        if (power == num2)
            return mid;
        else if (power < num2)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int ArrayProblems::minEatingSpeed(vector<int> &piles, int h)
{
    int maxPile = *max_element(piles.begin(), piles.end());
    int left = 1, right = maxPile, ans = maxPile;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        long long sum = 0;

        for (int p : piles)
            sum += ceil((double)p / mid);

        if (sum <= h)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int ArrayProblems::minDays(vector<int> &bloomDay, int m, int k)
{
    long long flowers = (long long)m * k;

    if (flowers > bloomDay.size())
        return -1;

    int left = *min_element(bloomDay.begin(), bloomDay.end()),
        right = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = right;
    while (left <= right)
    {
        int mid = (right + left) / 2;

        int cnt = 0, noOfBoq = 0;
        for (auto bloom : bloomDay)
        {
            if (bloom <= mid)
                cnt++;
            else
            {
                noOfBoq += cnt / k;
                cnt = 0;
            }
        }
        noOfBoq += cnt / k;
        if (noOfBoq >= m)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return left;
}

int ArrayProblems::smallestDivisor(vector<int> &nums, int threshold)
{
    int left = 1, right = *max_element(nums.begin(), nums.end()), ans = threshold;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        long long sum = 0;

        for (int p : nums)
            sum += ceil((double)p / mid);

        if (sum <= threshold)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int ArrayProblems::shipWithinDays(vector<int> &weights, int days)
{
    int right = accumulate(weights.begin(), weights.end(), 0),
        left = *max_element(weights.begin(), weights.end());

    while (left < right)
    {
        int mid = (right + left) / 2;

        int wSum = 0, d = 1;
        for (int w : weights)
        {
            if (wSum + w > mid)
            {
                wSum = w;
                d++;
            }
            else
                wSum += w;
        }

        if (d <= days)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int ArrayProblems::findKthPositive(vector<int> &arr, int k)
{
    int right = arr.size(), left = 0;

    while (left < right)
    {
        int mid = (right + left) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left + k;
}

int ArrayProblems::splitArray(vector<int> &nums, int k)
{
    int left = *max_element(nums.begin(), nums.end()), right = 0;
    for (int w : nums)
    {
        right += w;
    }

    while (left <= right)
    {
        int mid = (right + left) / 2;

        int wSum = 0, d = 1;
        for (int w : nums)
        {
            if (wSum + w > mid)
            {
                wSum = w;
                d++;
            }
            else
                wSum += w;
        }

        if (d > k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int left = 0, right = nums1.size();

    while (left <= right)
    {
        int mid1 = (left + right) / 2;
        int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == nums1.size()) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == nums2.size()) ? INT_MAX : nums2[mid2];
        if (l1 <= r2 && l2 <= r1)
        {
            if ((nums1.size() + nums2.size()) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }
        else if (l1 > l2)
            right = mid1 - 1;
        else
            left = mid1 + 1;
    }
    return 0.0;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int left = 0, right = matrix.size() * matrix[0].size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int r = mid / matrix[0].size();
        int c = mid % matrix[0].size();

        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

ArrayProblems::~ArrayProblems()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {3, 1, 2, -5, 2, -4};
    int n = 6;

    int arr2[10] = {2, 3, 4, 4, 5, 11, 12};
    int n2 = 7;

    vector<int> nums = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 4, 6, 8};
    vector<int> nums1 = {1, 2, 3, 0, 0, 0, 0};

    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    ArrayProblems obj1(arr, n, arr2, n2);

    // cout << "Maximum element is: " << obj1.findMax() << endl;
    // cout << "Second Maximum element is: " << obj1.findSecondMax() << endl;
    // bool sorted = obj1.checkIfSorted();
    // if (sorted)
    //     cout << "The array is sorted." << endl;
    // else
    //     cout << "The array is not sorted." << endl;

    // obj1.removeDuplicatesSortedArray();
    // obj1.removeDuplicatesUnsortedArray();
    // obj1.rotateByOnePlace();
    // obj1.rotateByKPlace(9);
    // obj1.moveZeros();
    // obj1.unionSortedArray();
    // cout << "Missing element in sorted array is: " << obj1.missingNumberInSortedArray() << endl;
    // cout << "Missing element in unsorted array is: " << obj1.missingNumberInUnsortedArray() << endl;
    // cout << "Maximum number of consecutive ones is: " << obj1.consecutiveOnes() << endl;
    // cout << "Single element is: " << obj1.singleElement() << endl;
    // cout << "Lenght of longest subarray: " << obj1.longestSubarrayWithKSum(5) << endl;
    // cout << "Indices of elements whose sum is: " << obj1.targetSum(6).first << ", " << obj1.targetSum(6).second << endl;
    // obj1.sortOnesTwosAndZeroes();
    // cout << "Majority element: " << obj1.majorityElement() << endl;
    // cout << "Maximum sum for subarray: " << obj1.maxSumForSubarray() << endl;
    // cout << "Maximum profit from stock prices: " << obj1.maxProfit() << endl;
    // cout << "Array rearranged in alternate positive and negative items: "<<endl;
    // obj1.alternativePosNeg();
    // // obj1.nextPermutation(nums);
    // vector<int> leaders = obj1.leaders(nums);
    // cout << "Leaders in the array are: ";
    // for (int i = 0; i < leaders.size(); i++)
    //     cout << leaders[i] << " ";
    // cout << endl;
    // obj1.setZeroes(matrix);
    // for (auto row : matrix)
    // {
    //     for (auto val : row)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Length of longest consecutive elements sequence is: " << obj1.longestConsecutive(nums) << endl;
    // cout << "Matrix after rotating by 90 degrees clockwise:" << endl;
    // obj1.rotateByNinty(matrix);
    // for (auto row : matrix)
    // {
    //     for (auto val : row)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // cout << "Spiral order of the matrix is: ";
    // vector<int> spiral = obj1.spiralOrder(matrix);
    // for (auto val : spiral)
    //     cout << val << " ";
    // cout << endl;
    // cout << "Total number of subarrays with sum equal to k is: " << obj1.subarraySum(nums, 5) << endl;
    // vector<vector<int>> pascal = obj1.pascalTriangle(5);
    // cout << "Pascal's Triangle:" << endl;
    // for(auto row : pascal)
    // {
    //     for (auto val : row)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // for (auto val : obj1.majorityElement(nums))
    //     cout << val << " ";
    // cout << endl;
    // vector<vector<int>> triplets = obj1.threeSum(nums);
    // cout << "Unique triplets in the array which gives the sum of zero are: " << endl;
    // for (auto row : triplets)
    // {
    //     for (auto val : row)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // vector<vector<int>> quadret = obj1.fourSum(nums, 2);
    // cout << "Unique quardlets in the array which gives the target sum are: " << endl;
    // for (auto row : quadret)
    // {
    //     for (auto val : row)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // cout << "Length of longest subarray with sum zero is: " << obj1.subArraySum(nums) << endl;
    // cout << "Total subarrays with given xor is: " << obj1.subArrayXor(nums, 2) << endl;
    // vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    // vector<vector<int>> mergedIntervals = obj1.mergeIntervals(intervals);
    // cout << "Merged Intervals are: " << endl;
    // for (auto row : mergedIntervals)
    // {
    //     for (auto val : row)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // cout << "Merged sorted array is: " << endl;
    // obj1.mergeArrays(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    // for (auto val : nums1)
    //     cout << val << " ";
    // cout << endl;
    // vector<int> ar = obj1.repeatingAndMissingNumber(nums);
    // cout << "Missing number is: " << ar[1] << ", Repeating number is: " << ar[0] << endl;
    // cout << "Total inversions in the array are: " << obj1.inversions(nums, 0, nums.size() - 1) << endl;
    // cout << "Total reverse pairs in the array are: " << reversePairs(nums) << endl;
    // cout << "Maximum product subarray is: " << obj1.maxProduct(nums) << endl;
    // cout << "Lower bound array is: " << obj1.lowerBound(nums, 6) << endl;
    // cout << "Upper bound array is: " << obj1.upperBound(nums, 9) << endl;
    // cout << "Floor and Ceil indices are: " << obj1.floorAndCeil(nums, 5)[0] << ", " << obj1.floorAndCeil(nums, 5)[1] << endl;
    // cout << "First and Last indices are: " << obj1.searchRange(nums, 4)[0] << ", " << obj1.searchRange(nums, 4)[1] << endl;
    // cout << "Frequency of target element is: " << obj1.frequency(nums, 3) << endl;
    // cout<< "Index of target element in rotated sorted array is: " << obj1.searchInRotatedArrayOne(nums, 3) << endl;
    // cout << "Minimum element in rotated sorted array is: " << obj1.findMin(nums) << endl;
    // cout << "Rotation count of rotated sorted array is: " << obj1.rotationCount(nums) << endl;
    // cout << "Single element in sorted array is: " << obj1.singleNonDuplicate(nums) << endl;
    // cout << "Peak element in the array is at index: " << obj1.findPeakElement(nums) << endl;
    // cout << "Square root of the number is: " << obj1.squareRoot(4) << endl;
    // cout << "Nth root of the number is: " << obj1.nthRoot(4, 69) << endl;
    // cout << "Minimum eating speed to finish the piles in given hours is: " << obj1.minEatingSpeed(nums2, 8) << endl;
    cout << "Minimum days to make m bouquets is: " << obj1.minDays(nums2, 3, 6) << endl;

    return 0;
}