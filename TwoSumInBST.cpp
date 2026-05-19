#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool reverse;

public:
    BSTIterator(TreeNode *root, bool isReverse) : reverse(isReverse)
    {
        pushAll(root);
    }

    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    int next()
    {
        TreeNode *tmpNode = st.top();
        st.pop();

        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);

        return tmpNode->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        BSTIterator r(root, true);
        BSTIterator l(root, false);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;

    Solution sol;
    bool result = sol.findTarget(root, k);

    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}