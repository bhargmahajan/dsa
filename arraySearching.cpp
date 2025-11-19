#include <iostream>

using namespace std;

class ArraySearching
{
    int arr[10] = {0};
    int n = 0;

public:
    ArraySearching(int arr[10], int n);

    int linearSearch(int key);
    int binarySearch(int key);
    ~ArraySearching();
};

ArraySearching::ArraySearching(int arr[10], int n)
{
    this->n = n;

    for (int i = 0; i < this->n; i++)
    {
        this->arr[i] = arr[i];
    }

    cout << "Constructor called." << endl;
}

int ArraySearching::linearSearch(int key)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (this->arr[i] == key)
        {
            index = i;
            break;
        }
    }
    return index;
}

int ArraySearching::binarySearch(int key)
{
    int index = -1;
    int left = 0, right = this->n - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (this->arr[mid] == key)
        {
            index = mid;
            break;
        }
        else if (this->arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return index;
}

ArraySearching::~ArraySearching()
{
    cout << "Destructor called." << endl;
}

int main()
{
    int arr[10] = {-1, 0, 5, 23, 62, 100};
    int n = 5;

    ArraySearching obj(arr, n);
    int result = obj.linearSearch(0);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    ArraySearching obj2(arr, n);
    result = obj2.binarySearch(-15);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}
