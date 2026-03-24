#include <bits/stdc++.h>

using namespace std;

/**
    @description: class representing a node in a binary tree
*/
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right) {
        data = val;
        left = left;
        right = right;
    }
};

/**
    @description: class to solve binary tree related problems
*/

class TreeProblems
{
public:
    vector<int> preorder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return res;

        res.push_back(root->data);
        preorder(root->left, res);
        preorder(root->right, res);

        return res;
    }

    /**
        @description: function to perform pre-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the pre-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    vector<int> inorder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return res;

        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);

        return res;
    }

    /**
        @description: function to perform in-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the in-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> postorder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return res;

        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->data);

        return res;
    }

    /**
        @description: function to perform post-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the post-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    /**
        @description: function to perform level-order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the level-order traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is a complete binary tree)
    */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                q.pop();
                level.push_back(n->data);

                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
            }

            res.push_back(level);
        }

        return res;
    }
};