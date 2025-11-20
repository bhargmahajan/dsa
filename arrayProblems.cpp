/*
    @author: Bharg Mahajan
    @description: This file contains various array problems solutions implemented in C++.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class ArrayProblems
{
    /*
        @author: Bharg Mahajan
        @description: This class contains various array problems solutions implemented in C++.
    */
    int arr[10] = {0};
    int n = 0;

public:
    ArrayProblems(int arr[10], int n);

    void printArray(int n);

    /*
        Function to find the maximum element in the array
        Time Complexity: O(n)
        Space Complexity: O(1)
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

    ~ArrayProblems();
};

ArrayProblems::ArrayProblems(int arr[10], int n)
{
    this->n = n;

    for (int i = 0; i < this->n; i++)
    {
        this->arr[i] = arr[i];
    }

    cout << "Constructor called." << endl;
}

void ArrayProblems::printArray(int n = 10)
{
    if (n <= 0)
    {
        cout << "Array is empty." << endl;
        return;
    }

    cout << "Array is:" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << this->arr[i] << " ";
    }
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
    printArray(i);
}

void ArrayProblems::removeDuplicatesUnsortedArray()
{
    if (n < 2)
    {
        printArray(n - 1);
        return;
    }

    unordered_map<int, bool> uniques;
    for (int j = 0; j < n; j++)
    {
        uniques[this->arr[j]]++;
    }

    int i = 0;
    for (auto it : uniques)
    {
        this->arr[i] = it.first;
        i++;
    }

    printArray(i - 1);
}

ArrayProblems::~ArrayProblems()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {1000, -726, 5550, 6200, -726, 5550};
    int n = 0;

    ArrayProblems obj1(arr, n);
    cout << "Maximum element is: " << obj1.findMax() << endl;
    cout << "Second Maximum element is: " << obj1.findSecondMax() << endl;

    bool sorted = obj1.checkIfSorted();
    if (sorted)
        cout << "The array is sorted." << endl;
    else
        cout << "The array is not sorted." << endl;

    obj1.removeDuplicatesSortedArray();
    obj1.removeDuplicatesUnsortedArray();

    return 0;
}