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

    void reverse(int arr[], int n)
    {
        int i = 0, j = n - 1;

        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

#endif