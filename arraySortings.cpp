#include <iostream>
#include <vector>

using namespace std;

class ArraySortings
{
    int arr[10] = {0};
    int n = 0;

public:
    ArraySortings(int arr[10], int n);

    void printArray();
    void swap(int &a, int &b);
    void split(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);
    void partition(int arr[], int left, int right);
    int pivot(int arr[], int left, int right);

    void selectionSort();
    void bubbleSort();
    void insertionSort();
    void mergesort();
    void quickSort();

    ~ArraySortings();
};

ArraySortings::ArraySortings(int arr[10], int n)
{
    this->n = n;

    for (int i = 0; i < this->n; i++)
    {
        this->arr[i] = arr[i];
    }

    cout << "Constructor called." << endl;
}

void ArraySortings::printArray()
{
    if (this->n <= 0)
    {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array is:" << endl;
    for (int i = 0; i <= this->n; i++)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}

void ArraySortings::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ArraySortings::split(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    split(arr, left, mid);
    split(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void ArraySortings::merge(int arr[], int left, int mid, int right)
{
    int temp[10];
    int a = left, b = mid + 1;
    int i = 0;

    while (a <= mid && b <= right)
    {
        if (arr[a] <= arr[b])
            temp[i++] = arr[a++];
        else
            temp[i++] = arr[b++];
    }

    while (a <= mid)
        temp[i++] = arr[a++];

    while (b <= right)
        temp[i++] = arr[b++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];
}

void ArraySortings::partition(int arr[], int left, int right)
{
    if (left < right)
    {
        int p = pivot(arr, left, right);
        partition(arr, left, p - 1);
        partition(arr, p + 1, right);
    }
}

int ArraySortings::pivot(int arr[], int left, int right)
{
    int p = arr[left], i = left + 1, j = right;
    while (i < j)
    {
        if (arr[i] >= p && arr[j] <= p)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if (arr[i] <= p)
            i++;
        if (arr[j] >= p)
            j--;
    }
    swap(arr[left], arr[j]);
    return j;
}

void ArraySortings::selectionSort()
{
    for (int i = 0; i < this->n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < this->n; j++)
        {
            if (this->arr[minIndex] > this->arr[j])
            {
                minIndex = j;
            }
        }
        swap(this->arr[i], this->arr[minIndex]);
    }
    printArray();
}

void ArraySortings::bubbleSort()
{
    for (int i = 0; i < this->n - 1; i++)
    {
        int swapped = 0;

        for (int j = i + 1; j < this->n; j++)
        {
            if (this->arr[i] > this->arr[j])
            {
                swap(this->arr[i], this->arr[j]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
    printArray();
}

void ArraySortings::insertionSort()
{
    for (int i = 1; i < this->n; i++)
    {
        int key = this->arr[i];
        int j = i - 1;

        while (j >= 0 && this->arr[j] > key)
        {
            this->arr[j + 1] = this->arr[j];
            j--;
        }
        this->arr[j + 1] = key;
    }
    printArray();
}

void ArraySortings::mergesort()
{
    split(this->arr, 0, this->n - 1);
    printArray();
}

void ArraySortings::quickSort()
{
    partition(this->arr, 0, this->n - 1);
    printArray();
}

ArraySortings::~ArraySortings()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {23, -23, 32, -1, -1, 5, 62, 5};

    ArraySortings obj1(arr, 8);
    obj1.selectionSort();

    ArraySortings obj2(arr, 8);
    obj2.bubbleSort();

    ArraySortings obj3(arr, 8);
    obj3.insertionSort();

    ArraySortings obj4(arr, 8);
    obj4.mergesort();

    ArraySortings obj5(arr, 8);
    obj5.quickSort();

    return 0;
}