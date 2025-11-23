/*
    @author: Bharg Mahajan
    @description: This file contains various array problems solutions implemented in C++.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

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

    ~ArrayProblems();
};

ArrayProblems::ArrayProblems(int arr[10], int n, int arr2[10], int n2)
{
    this->n = n;
    this->n2 = n2;

    for (int i = 0; i < this->n; i++)
    {
        this->arr[i] = arr[i];
    }

    for (int i = 0; i < this->n2; i++)
    {
        this->arr2[i] = arr2[i];
    }

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
    {
        uniques[this->arr[j]]++;
    }

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
    {
        this->arr[i] = this->arr[i + 1];
    }

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
    {
        cout << Union[i] << " ";
    }
    cout << endl;
}

ArrayProblems::~ArrayProblems()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    int arr2[10] = {2, 3, 4, 4, 5, 11, 12};
    int n2 = 7;

    ArrayProblems obj1(arr, n, arr2, n2);
    cout << "Maximum element is: " << obj1.findMax() << endl;
    cout << "Second Maximum element is: " << obj1.findSecondMax() << endl;

    bool sorted = obj1.checkIfSorted();
    if (sorted)
        cout << "The array is sorted." << endl;
    else
        cout << "The array is not sorted." << endl;

    obj1.removeDuplicatesSortedArray();
    obj1.removeDuplicatesUnsortedArray();
    obj1.rotateByOnePlace();
    obj1.rotateByKPlace(9);
    obj1.moveZeros();
    obj1.unionSortedArray();

    return 0;
}