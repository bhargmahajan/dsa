#include <bits/stdc++.h>

using namespace std;

/*
    @description: class to solve heap related problems
*/
class HeapProblems
{
public:
    int capacity, size, *arr;

    HeapProblems(int cap = 10)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    /*
        @description: return parent of current node
        @param: i - index of current node
        @return: index of parent node
        @time complexity: O(1)
        @space complexity: O(1)
    */
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    /*
        @description: swap two elements in the heap
        @param: x, y - pointers to the elements to be swapped
        @return: void
        @time complexity: O(1)
        @space complexity: O(1)
    */
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    /*
        @description: print the elements of the heap
        @return: void
        @time complexity: O(n)
        @space complexity: O(1)
    */
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    /*
        @description: insert an element in the heap
        @param: x - element to be inserted
        @return: void
        @time complexity: O(log n)
        @space complexity: O(1)
    */
    void Insert(int x)
    {
        if (size == capacity)
        {
            cout << "Binary Heap Overflow" << endl;
            return;
        }

        arr[size] = x;
        int k = size;
        size++;

        while (k != 0 && arr[parent(k)] < arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    /*
        @description: get the minimum element from the heap
        @return: minimum element
        @time complexity: O(1)
        @space complexity: O(1)
    */
    int getMin()
    {
        return arr[0];
    }

    /*
        @description: return index of left child of current node
        @param: i - index of current node
        @return: index of left child node
        @time complexity: O(1)
        @space complexity: O(1)
    */
    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    /*
        @description: return index of right child of current node
        @param: i - index of current node
        @return: index of right child node
        @time complexity: O(1)
        @space complexity: O(1)
    */
    int rightChild(int i)
    {
        return 2 * i + 2;
    }

    /*
        @description: heapify the subtree rooted at index ind
        @param: ind - index of the root of the subtree to be heapified
        @return: void
        @time complexity: O(log n)
        @space complexity: O(1)
    */
    void Heapify(int ind)
    {
        int r = rightChild(ind);
        int l = leftChild(ind);
        int smallest = ind;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;

        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != ind)
        {
            swap(&arr[smallest], &arr[ind]);
            Heapify(smallest);
        }
    }

    /*
        @description: extract the minimum element from the heap
        @return: minimum element
        @time complexity: O(log n)
        @space complexity: O(1)
    */
    int ExtractMin()
    {
        if (size <= 0)
            return INT_MAX;

        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int mini = arr[0];
        arr[0] = arr[size - 1];
        size--;
        Heapify(0);

        return mini;
    }

    /*
        @description: decrease the value of an element in the heap
        @param: k - index of the element to be decreased, val - new value of the element
        @return: void
        @time complexity: O(log n)
        @space complexity: O(1)
    */
    void Decreasekey(int k, int val)
    {
        arr[k] = val;
        while (k != 0 && arr[parent(k)] < arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }

    /*
        @description: delete an element from the heap
        @param: i - index of the element to be deleted
        @return: void
        @time complexity: O(log n)
        @space complexity: O(1)
    */
    void Delete(int i)
    {
        Decreasekey(i, INT_MIN);
        ExtractMin();
    }

    /*
        @description: check if the given array represents a min heap
        @param: nums - vector of integers representing the heap
        @return: true if the array represents a min heap, false otherwise
        @time complexity: O(n)
        @space complexity: O(1)
    */
    bool isMinHeap(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i <= (n / 2) - 1; i++)
        {
            int l = leftChild(i);
            if (l < n && nums[i] > nums[l])
                return false;

            int r = rightChild(i);
            if (r < n && nums[i] > nums[r])
                return false;
        }
        return true;
    }
};

int main()
{
    HeapProblems h(20);
    vector<int> nums = {10, 20, 30, 25, 15};

    // Output result
    cout << (h.isMinHeap(nums) ? "true" : "false") << endl;

    return 0;
}