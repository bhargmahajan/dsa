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

    void selectionSort();
    void bubbleSort();
    void insertionSort();

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
    cout << "Array is:" << endl;

    for (int i = 0; i < this->n; i++)
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

ArraySortings::~ArraySortings()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {23, -23, 32, -1, -1, 5, 62, 5};

    ArraySortings obj1(arr, 10);
    obj1.selectionSort();

    ArraySortings obj2(arr, 8);
    obj2.bubbleSort();

    ArraySortings obj3(arr, 8);
    obj3.insertionSort();

    return 0;
}