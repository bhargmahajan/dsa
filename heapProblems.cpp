#include <bits/stdc++.h>

using namespace std;

/*
    @description: class to find the kth largest element in a stream of numbers
*/
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> h;
    int r;

public:
    /**
     * @description: constructor to initialize the class with k and the initial stream of numbers
     * @param: k - position of the desired largest element, nums - vector of integers representing the initial stream
     * @return: void
     * @time complexity: O(n log k)
     * @space complexity: O(k)
     */
    KthLargest(int k, vector<int> &nums)
    {
        r = k;
        for (auto i : nums)
        {
            h.push(i);
            if (h.size() > k)
                h.pop();
        }
    }

    /**
     * @description: add a new value to the stream and return the kth largest element
     * @param: val - new value to be added
     * @return: kth largest element
     * @time complexity: O(1)
     * @space complexity: O(1)
     */
    int add(int val)
    {
        h.push(val);
        if (h.size() > r)
            h.pop();

        return h.top();
    }
};

/*
    @description: class to find the median of a stream of numbers
*/
class MedianFinder
{
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

public:
    MedianFinder() {}

    /*
        @description: add a new number to the stream
        @param: num - new number to be added
        @return: void
        @time complexity: O(log n)
        @space complexity: O(1)
    */
    void addNum(int num)
    {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();

        if (minh.size() > maxh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    /*
        @description: find the median of the current stream of numbers
        @param: void
        @return: median value
        @time complexity: O(1)
        @space complexity: O(1)
    */
    double findMedian()
    {
        if (minh.size() == maxh.size())
            return (minh.top() + maxh.top()) / 2.0;
        return maxh.top();
    }
};

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

    /*
        @description: check if the given hand of cards can be rearranged into groups of consecutive numbers
        @param: hand - vector of integers representing card values, groupSize - size of each group
        @return: true if the hand can be rearranged, false otherwise
        @time complexity: O(n log n)
        @space complexity: O(n)
    */
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> h;
        for (auto i : hand)
            h[i]++;

        auto it = h.begin();

        while (it != h.end())
        {
            if (it->second == 0)
            {
                ++it;
                continue;
            }

            int start = it->first, count = it->second;
            for (int i = 0; i < groupSize; ++i)
            {
                if (h[start + i] < count)
                    return false;

                h[start + i] -= count;
            }

            it++;
        }

        return true;
    }

    /*
        @description: find the maximum k combinations of elements from two arrays
        @param: nums1, nums2 - vectors of integers, k - number of combinations to find
        @return: vector of integers with maximum k combinations
        @time complexity: O(k log k)
        @space complexity: O(k)
    */
    vector<int> maxCombinations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());

        priority_queue<tuple<int, int, int>> h;
        set<pair<int, int>> visited;
        h.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0, 0});

        vector<int> res;
        while (k-- && !h.empty())
        {
            int sum = get<0>(h.top());
            int i = get<1>(h.top());
            int j = get<2>(h.top());

            h.pop();
            res.push_back(sum);

            if (i + 1 < nums1.size() && !visited.count({i + 1, j}))
            {
                h.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            if (j + 1 < nums2.size() && !visited.count({i, j + 1}))
            {
                h.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return res;
    }

    /*
        @description: find the top k frequent elements in an array
        @param: nums - vector of integers, k - number of top frequent elements to find
        @return: vector of integers with top k frequent elements
        @time complexity: O(n log n)
        @space complexity: O(n)
    */
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        for (auto it : nums)
            freq[it]++;

        priority_queue<pair<int, int>> h;

        for (auto it : freq)
        {
            h.push({it.second, it.first});
        }

        vector<int> res;
        while (k-- && !h.empty())
        {
            res.push_back(h.top().second);
            h.pop();
        }

        return res;
    }
};

int main()
{
    HeapProblems h;

    return 0;
}