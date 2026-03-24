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
        @description: function to check if the binary tree is empty
        @param: root: pointer to the root of the binary tree
        @return: true if the tree is empty, false otherwise
        @time complexity: O(1)
        @space complexity: O(1)
    */
    bool isEmpty(Node *root)
    {
        return root == NULL;
    }

    /**
        @description: function to perform pre-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the pre-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
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

    /**
        @description: function to perform in-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the in-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
    vector<int> inOrder(Node *root)
    {
        if (isEmpty(root))
            return {};

        vector<int> ans;
        stack<Node *> st;
        Node *curr = root;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }

        return ans;
    }

    /**
        @description: function to perform post-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the post-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
    vector<int> postOrder(Node *root) {
        if (isEmpty(root))
            return {};

        vector<int> ans;
        stack<Node *> st1, st2;
        st1.push(root);

        while (!st1.empty()){
            Node *curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left)
                st1.push(curr->left);
            if (curr->right)
                st1.push(curr->right);
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
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
    vector<int> in = tree.postOrder(root);
    cout << "Postorder Traversal: ";
    for (int i : in)
        cout << i << " ";
    cout << endl;

    return 0;
}