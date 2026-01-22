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

    /*
        @description: check if the singly linked list is a palindrome
        @param: head - pointer to the head of the singly linked list
        @return: bool - true if the singly linked list is a palindrome, false otherwise
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the pointers used in the algorithm
    */
    bool isPalindrome(Node *head)
    {
        if (!head || head->next == nullptr)
            return true;

        Node *mid = middleNode(head);
        Node *rev = reverseList(mid->next);
        Node *first = head;
        Node *second = rev;

        while (second)
        {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }

    /*
        @description: rearrange the singly linked list such that all odd indexed nodes are together followed by the even indexed nodes
        @param: head - pointer to the head of the singly linked list
        @return: ListNode* - pointer to the head of the rearranged singly linked list
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the pointers used in the algorithm
    */
    Node *oddEvenList(Node *head)
    {
        Node *oddHead = new Node(-1), *oddTail = oddHead;
        Node *evenHead = new Node(-1), *evenTail = evenHead;
        Node *curr = head, *temp;

        while (curr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            oddTail->next = temp;
            oddTail = temp;

            if (curr)
            {
                temp = curr;
                curr = curr->next;
                temp->next = nullptr;
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        oddTail->next = evenHead->next;

        return oddHead->next;
    }

    /*
        @description: remove the Nth node from the end of the singly linked list
        @param: head - pointer to the head of the singly linked list
        @param: n - integer representing the position from the end
        @return: Node* - pointer to the head of the modified singly linked list
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the pointers used in the algorithm
    */
    Node *removeNthFromEnd(Node *head, int n)
    {
        Node *dummy = new Node(0, head);
        Node *fast = dummy, *slow = dummy;
        for (int i = 0; i <= n; i++)
            fast = fast->next;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }

    /*
        @description: delete the middle node of the singly linked list
        @param: head - pointer to the head of the singly linked list
        @return: Node* - pointer to the head of the modified singly linked list
        @time complexity: O(n/2), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the pointers used in the algorithm
    */
    Node *deleteMiddle(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        Node *slow = head, *fast = head->next->next;

        while (fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;

        return head;
    }

    Node *middleNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *mid = slow->next;
        slow->next = nullptr;

        return mid;
    }

    Node *mergeTwoSortedLinkedLists(Node *list1, Node *list2)
    {
        Node *dummyNode = new Node(-1);
        Node *temp = dummyNode;

        while (list1 && list2)
        {
            if (list1->data <= list2->data)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }

        return dummyNode->next;
    }

    /*
        @description: sort the singly linked list using merge sort
        @param: head - pointer to the head of the singly linked list
        @return: Node* - pointer to the head of the sorted singly linked list
        @time complexity: O(n log n), where n is the number of nodes in the singly linked list
        @space complexity: O(log n), for the recursive stack space
    */
    Node *sortList(Node *head)
    {
        if (head == nullptr || !head->next)
            return head;

        Node *middle = middleNode(head);
        Node *left = sortList(head);
        Node *right = sortList(middle);

        return mergeTwoSortedLinkedLists(left, right);
    }

    /*
        @description: get the intersection node of two singly linked lists
        @param: headA - pointer to the head of the first singly linked list
        @param: headB - pointer to the head of the second singly linked list
        @return: Node* - pointer to the intersection node, nullptr if there is no intersection
        @time complexity: O(2 × max(length of list1, length of list2))
        @space complexity: O(1), for the two pointers
    */
    Node *getIntersectionNode(Node *headA, Node *headB)
    {
        Node *t1 = headA, *t2 = headB;

        while (t1 != t2)
        {
            t1 = t1 ? t1->next : headA;
            t2 = t2 ? t2->next : headB;
        }

        return t1;
    }

    /*
        @description: add two numbers represented by two singly linked lists
        @param: l1 - pointer to the head of the first singly linked list
        @param: l2 - pointer to the head of the second singly linked list
        @return: Node* - pointer to the head of the resultant singly linked list
        @time complexity: O(max(m, n)), where m and n are the lengths of the two singly linked lists
        @space complexity: O(max(m, n)), for the resultant singly linked list
    */
    Node *addTwoNumbers(Node *l1, Node *l2)
    {
        Node *res = new Node(0), *temp = res;
        int carry = 0;

        while ((l1 || l2) || carry)
        {
            int sum = 0;

            if (l1)
            {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->data;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            Node *n = new Node(sum % 10);
            temp->next = n;
            temp = temp->next;
        }
        return res->next;
    }

    Node *getKthNode(Node *curr, int k)
    {
        while (curr && k > 0)
        {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    /*
        @description: reverse nodes of a singly linked list k at a time
        @param: head - pointer to the head of the singly linked list
        @param: k - integer representing the group size
        @return: ListNode* - pointer to the head of the modified singly linked list
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the pointers used in the algorithm
    */
    Node *reverseKGroup(Node *head, int k)
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *groupPrev = dummy;

        while (true)
        {
            Node *kth = getKthNode(groupPrev, k);
            if (!kth)
                break;

            Node *groupNext = kth->next;
            Node *prev = groupNext;
            Node *curr = groupPrev->next;

            for (int i = 0; i < k; i++)
            {
                Node *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            Node *temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy->next;
    }

    /*
        @description: rotate the singly linked list to the right by k places
        @param: head - pointer to the head of the singly linked list
        @param: k - integer representing the number of places to rotate
        @return: ListNode* - pointer to the head of the rotated singly linked list
        @time complexity: O(n), where n is the number of nodes in the singly linked list
        @space complexity: O(1), for the pointers used in the algorithm
    */
    Node *rotateRight(Node *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        int l = 1;
        Node *last = head;

        while (last->next)
        {
            last = last->next;
            l++;
        }

        last->next = head;
        k = k % l;
        Node *temp = head;

        for (int i = 1; i < l - k; i++)
            temp = temp->next;

        head = temp->next;
        temp->next = nullptr;

        return head;
    }

    void insertCopy(Node *head)
    {
        Node *temp = head;

        while (temp)
        {
            Node *copy = new Node(temp->val);
            Node *next = temp->next;
            copy->next = next;
            temp->next = copy;
            temp = next;
        }
    }

    void connectRandom(Node *head)
    {
        Node *temp = head;

        while (temp)
        {
            Node *copyNode = temp->next;

            if (temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;

            temp = temp->next->next;
        }
    }

    Node *getDeepCopy(Node *head)
    {
        Node *temp = head;
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;

        while (temp)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }

    /*
        @description: create a deep copy of a singly linked list with random pointers
        @param: head - pointer to the head of the singly linked list
        @return: Node* - pointer to the head of the deep copied singly linked list
        @time complexity: O(3n), where n is the number of nodes in the singly linked list
        @space complexity: O(n), for the pointers used in the algorithm
    */
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        insertCopy(head);
        connectRandom(head);
        return getDeepCopy(head);
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