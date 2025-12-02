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

ArrayProblems::~ArrayProblems()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    int arr2[10] = {2, 3, 4, 4, 5, 11, 12};
    int n2 = 7;

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
    cout << "Maximum sum for subarray: " << obj1.maxSumForSubarray() << endl;
    cout << "Maximum profit from stock prices: " << obj1.maxProfit() << endl;

    return 0;
}