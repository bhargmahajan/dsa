/*
    @author: Bharg Mahajan
    @description: This file contains LRU cache problem solutions implemented in C++.
*/
#include <bits/stdc++.h>
using namespace std;

/*
    @author: Bharg Mahajan
    @description: This class contains LRU cache problem solutions implemented in C++.
*/
class LRUCache
{
public:
    class Node
    {
    public:
        int key, value;
        Node *prev, *next;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            prev = next = nullptr;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node)
    {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return node->value;
        }

        return -1;
    }

    int put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp.erase(key);
            deleteNode(mp[key]);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

int main()
{
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl;

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl;

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl;

    // Key 3 should be present
    cout << cache.get(3) << endl;

    // Key 4 should be present
    cout << cache.get(4) << endl;
    return 0;
}