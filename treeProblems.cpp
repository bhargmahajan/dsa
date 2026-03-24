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

    /**
        @description: function to calculate the maximum depth of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: integer representing the maximum depth of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n) in the worst case (when the tree is skewed)
    */
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l, r);
    }

    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = dfsHeight(root->left);
        if (l == -1)
            return -1;

        int r = dfsHeight(root->right);
        if (r == -1)
            return -1;

        if (abs(l - r) > 1)
            return -1;

        return 1 + max(l, r);
    }

    /**
        @description: function to check if the binary tree is balanced
        @param: root: pointer to the root of the binary tree
        @return: boolean value indicating whether the tree is balanced or not
        @time complexity: O(n)
        @space complexity: O(1)
    */
    bool isBalanced(TreeNode *root) { return dfsHeight(root) != -1; }

    int calculateHeight(TreeNode *node, int &d)
    {
        if (!node)
            return 0;

        int l = calculateHeight(node->left, d);
        int r = calculateHeight(node->right, d);
        d = max(d, l + r);

        return max(l, r) + 1;
    }

    /**
        @description: function to calculate the diameter of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: integer representing the diameter of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(1) in the worst case (when the tree is skewed)
    */
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        calculateHeight(root, d);
        return d;
    }

    int dfs(TreeNode *node, int &maxSum)
    {
        if (!node)
            return 0;

        int l = max(0, dfs(node->left, maxSum));
        int r = max(0, dfs(node->right, maxSum));
        maxSum = max(maxSum, l + r + node->data);

        return max(l, r) + node->data;
    }

    /**
        @description: function to calculate the maximum path sum in the binary tree
        @param: root: pointer to the root of the binary tree
        @return: integer representing the maximum path sum
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(h) in the worst case (when the tree is skewed)
    */
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;

        dfs(root, maxSum);

        return maxSum;
    }
};