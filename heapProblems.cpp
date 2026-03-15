#include <bits/stdc++.h>

using namespace std;

/*
    @description: structure for a node in a linked list
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    @description: comparator class for ListNode pointers to be used in the priority queue
*/
class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

/*
    @description: class to solve heap related problems
*/
class HeapProblems
{
public:
    /*
        @description: find the kth largest element in the array
        @param: nums - vector of integers, k - position of the desired largest element
        @return: kth largest element
        @time complexity: O(n log k)
        @space complexity: O(k)
    */
    int kthLargestElement(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < k; i++)
            minHeap.push(nums[i]);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }

    /*
        @description: sort a nearly sorted array using a min heap
        @param: arr - vector of integers, k - maximum distance an element can be from its sorted position
        @return: sorted vector of integers
        @time complexity: O(n log k)
        @space complexity: O(k)
    */
    vector<int> sortNearlySortedArray(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> res;

        for (int i = 0; i <= k && i < arr.size(); i++)
            minHeap.push(arr[i]);

        for (int i = k + 1; i < arr.size(); i++)
        {
            if (arr[i] > minHeap.top())
            {
                res.push_back(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }

        while (!minHeap.empty())
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
    }

    /*
        @description: merge k sorted linked lists
        @param: lists - vector of pointers to ListNode
        @return: pointer to the merged sorted linked list
        @time complexity: O(N log k)
        @space complexity: O(k)
    */
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;

        for (auto x : lists)
        {
            if (x != NULL)
                minHeap.push(x);
        }

        ListNode *res = new ListNode(0);
        ListNode *tail = res;
        while (!minHeap.empty())
        {
            ListNode *s = minHeap.top();
            minHeap.pop();
            tail->next = s;
            tail = tail->next;

            if (tail->next)
                minHeap.push(s->next);
        }

        return res->next;
    }

    /*
        @description: replace each element in the array with its rank
        @param: arr - vector of integers
        @return: vector of integers with ranks
        @time complexity: O(n log n)
        @space complexity: O(n)
    */
    vector<int> replaceWithRank(vector<int> &arr)
    {
        vector<int> sortedArr = sortNearlySortedArray(arr, arr.size() - 1);
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int i = 0; i < sortedArr.size(); i++)
        {
            if (rankMap.find(sortedArr[i]) == rankMap.end())
            {
                rankMap[sortedArr[i]] = rank;
                rank++;
            }
        }

        for (int i = 0; i < arr.size(); i++)
            arr[i] = rankMap[arr[i]];

        return arr;
    }

    /*
        @description: find the minimum number of intervals required to complete all tasks
        @param: tasks - vector of characters representing tasks, n - cooldown period
        @return: minimum number of intervals required
        @time complexity: O(n log k)
        @space complexity: O(k)
    */
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        for (char c : tasks)
            freq[c]++;

        priority_queue<int> h;
        for (auto e : freq)
            h.push(e.second);

        int time = 0;
        while (!h.empty())
        {
            vector<int> temp;
            int i = 0, cycle = n + 1;

            while (i < cycle && !h.empty())
            {
                int cnt = h.top();
                h.pop();
                cnt--;

                if (cnt > 0)
                    temp.push_back(cnt);
                time++;
                i++;
            }

            for (int val : temp)
                h.push(val);
            if (h.empty())
                break;
            time += (cycle - i);
        }

        return time;
    }
};

int main()
{
    HeapProblems h;
    vector<int> nums = {20, 15, 26, 2, 98, 6};
    int k = 3;
    cout << "The " << k << "rd largest element is: " << h.kthLargestElement(nums, k) << endl;

    vector<int> sortedArr = h.sortNearlySortedArray(nums, k);

    for (int num : sortedArr)
        cout << num << " ";

    cout << endl;
    vector<int> res = h.replaceWithRank(nums);
    for (int x : res)
        cout << x << " ";

    return 0;
}