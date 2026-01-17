#include <bits/stdc++.h>

using namespace std;

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

class LinkedListSolutions
{
public:
    Node *insertNodeAtHead(Node *head, int data)
    {
        Node *newNode = new Node(data, head);
        return newNode;
    }

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
};

int main()
{
    Node *head = new Node(2);
    head->next = new Node(3);

    LinkedListSolutions sol;
    sol.printList(head);

    head = sol.insertNodeAtHead(head, 1);
    sol.printList(head);

    return 0;
};