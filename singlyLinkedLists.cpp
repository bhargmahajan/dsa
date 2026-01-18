#include <bits/stdc++.h>

using namespace std;

/*
    @description: class to create nodes for linked list
*/
class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

/*
    @description: class to solve linked list related problems
*/
class LinkedListSolutions
{
public:
    /*
        @description: insert a new node at the head of the linked list
        @param: head - pointer to the head of the linked list
        @param: data - integer data for the new node
        @return: Node* - pointer to the new head of the linked list
        @time complexity: O(1), for inserting at the head
        @space complexity: O(1), for the new node
    */
    Node *insertNodeAtHead(Node *head, int data)
    {
        Node *newNode = new Node(data, head);
        return newNode;
    }

    /*
        @description: prints the linked list
        @param: head - pointer to the head of the linked list
        @return: void
        @time complexity: O(n), where n is the number of nodes in the linked list
        @space complexity: O(1), for the temporary pointer
    */
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    /*
        @description: delete a node in a linked list given only access to that node
        @param: node - pointer to the node to be deleted
        @return: void
        @time complexity: O(1), for deleting the node
        @space complexity: O(1), for temporary variables
    */
    void deleteNode(Node *node)
    {
        node->data = node->next->data;
        node->next->data = node->data;
        node->next = node->next->next;
    }

    /*
        @description: get the length of the linked list
        @param: head - pointer to the head of the linked list
        @return: int - length of the linked list
        @time complexity: O(n), where n is the number of nodes in the linked list
        @space complexity: O(1), for the temporary pointer and length counter
    */
    int getListLength(Node *head)
    {
        int len = 0;
        Node *temp = head;

        while (temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    /*
        @description: search for a value in the linked list
        @param: head - pointer to the head of the linked list
        @param: key - integer value to search for
        @return: bool - true if the value is found, false otherwise
        @time complexity: O(n), where n is the number of nodes in the linked list
        @space complexity: O(1), for the temporary pointer
    */
    bool searchValue(Node *head, int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == key)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }

    /*
        @description: find the middle node of the singly linked list
        @param: head - pointer to the head of the singly linked list
        @return: Node* - pointer to the middle node of the singly linked list
        @time complexity: O(n/2), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the two pointers
    */
    Node *middleNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    /*
        @description: reverse the singly linked list
        @param: head - pointer to the head of the singly linked list
        @return: Node* - pointer to the new head of the reversed singly linked list
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the three pointers
    */
    Node *reverseList(Node *head)
    {
        Node *curr = head;
        Node *previous = nullptr;
        while (curr)
        {
            Node *temp = curr->next;
            curr->next = previous;
            previous = curr;
            curr = temp;
        }

        return previous;
    }

    /*
        @description: detect if there is a cycle in the singly linked list
        @param: head - pointer to the head of the singly linked list
        @return: bool - true if there is a cycle, false otherwise
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the two pointers
    */
    bool hasCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }

        return false;
    }

    /*
        @description: detect the starting node of the cycle in the singly linked list
        @param: head - pointer to the head of the singly linked list
        @return: Node* - pointer to the starting node of the cycle, nullptr if there is no cycle
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the two pointers
    */
    Node *detectCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};

int main()
{
    Node *head = new Node(2);
    head->next = new Node(3);

    LinkedListSolutions sol;
    sol.printList(head);

    head = sol.insertNodeAtHead(head, 1);
    sol.printList(head);

    cout << "Length of the linked list: " << sol.getListLength(head) << endl;
    cout << "Searching for value 3: " << (sol.searchValue(head, 1) ? "Found" : "Not Found") << endl;

    return 0;
};