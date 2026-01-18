#include <bits/stdc++.h>

using namespace std;

/*
    @description: class to create nodes for doubly linked list
*/
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data, Node *prev, Node *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

/*
    @description: class to solve doubly linked list related problems
*/
class doublyLinkedLists
{
public:
    /*
        @description: prints the doubly linked list
        @param: head - pointer to the head of the doubly linked list
        @return: void
        @time complexity: O(n), where n is the number of nodes in the doubly linked list
        @space complexity: O(1), for the temporary pointer
    */
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    /*
        @description: insert a new node at the tail of the doubly linked list
        @param: head - pointer to the head of the doubly linked list
        @param: data - integer data for the new node
        @return: Node* - pointer to the head of the doubly linked list
        @time complexity: O(n), where n is the number of nodes in the doubly linked list
        @space complexity: O(1), for the new node
    */
    Node *insertNodeAtTail(Node *head, int data)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data, temp, nullptr);
        temp->next = newNode;

        return head;
    }

    /*
        @description: delete the last node of the doubly linked list
        @param: head - pointer to the head of the doubly linked list
        @return: Node* - pointer to the head of the doubly linked list
        @time complexity: O(n), where n is the number of nodes in the doubly linked list
        @space complexity: O(1), for the temporary pointer
    */
    Node *deleteLastNode(Node *head)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;

        return head;
    }

    /*
        @description: reverse the doubly linked list
        @param: head - pointer to the head of the doubly linked list
        @return: Node* - pointer to the new head of the doubly linked list
        @time complexity: O(n), where n is the number of nodes in the doubly linked list
        @space complexity: O(1), for the temporary pointers
    */
    Node *reverseLL(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *cur = head;
        while (cur)
        {
            Node *temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            head = cur;
            cur = temp;
        }

        return head;
    }
};

int main()
{
    Node *head = new Node(10);

    doublyLinkedLists sol;
    sol.insertNodeAtTail(head, 20);
    sol.insertNodeAtTail(head, 30);

    cout << "Doubly Linked List after inserting nodes at tail:" << endl;
    sol.printList(head);

    // head = sol.deleteLastNode(head);
    // cout << "Doubly Linked List after deleting last node:" << endl;
    // sol.printList(head);

    head = sol.reverseLL(head);
    cout << "Doubly Linked List after reversing:" << endl;
    sol.printList(head);

    return 0;
}