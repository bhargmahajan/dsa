#include <bits/stdc++.h>

using namespace std;

/**
    @description: class representing a node in a binary tree
*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/**
    @description: class to solve binary tree related problems
*/
class BinaryTree
{
public:
    /**
        @description: find the maximum number of children that can be content with the given cookies
        @param: g: vector of integers representing the greed factor of each child
        @param: s: vector of integers representing the size of each cookie
        @return: maximum number of content children
        @time complexity: O(n log n + m log m) where n is the size of g and m is the size of s
        @space complexity: O(1)
    */
    bool isEmpty(Node *root)
    {
        return root == NULL;
    }

    vector<int> preOrder(Node *root)
    {
        if (isEmpty(root))
            return {};

        vector<int> ans;
        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();
            ans.push_back(it->data);

            if (it->right)
                st.push(it->right);

            if (it->left)
                st.push(it->left);
        }
        return ans;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    BinaryTree tree;
    vector<int> pre = tree.preOrder(root);
    cout << "Preorder Traversal: ";
    for (int i : pre)
        cout << i << " ";
    cout << endl;

    return 0;
}