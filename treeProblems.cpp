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

    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
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

    /**
        @description: function to check if two binary trees are the same
        @param: p: pointer to the root of the first binary tree
        @param: q: pointer to the root of the second binary tree
        @return: boolean value indicating whether the trees are the same or not
        @time complexity: O(n+m), where m and n are the number of nodes in the two trees
        @space complexity: O(1)
    */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        return (p->data == q->data) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    /**
        @description: function to perform zigzag level order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector of vectors containing the zigzag level order traversal
        @time complexity: O(n)
        @space complexity: O(n)
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        bool flag = true;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                q.pop();

                int index = flag ? i : size - 1 - i;
                temp[index] = n->data;

                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }

            flag = !flag;
            res.push_back(temp);
        }

        return res;
    }

    /**
        @description: function to perform vertical order traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector of vectors containing the vertical order traversal
        @time complexity: O(N * log²N * log²N * log²N)), where n is the number of nodes in the tree
        @space complexity: O(n)
    */
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            TreeNode *temp = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(temp->data);

            if (temp->left)
                q.push({temp->left, {x - 1, y + 1}});
            if (temp->right)
                q.push({temp->right, {x + 1, y + 1}});
        }

        vector<vector<int>> res;
        for (auto p : mp)
        {
            vector<int> v;
            for (auto t : p.second)
            {
                v.insert(v.end(), t.second.begin(), t.second.end());
            }
            res.push_back(v);
        }

        return res;
    }

    /**
        @description: function to perform top view traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the top view traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n)
    */
    vector<int> topView(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        map<int, int> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *n = it.first;
            int line = it.second;

            if (mp.find(line) == mp.end())
                mp[line] = n->data;

            if (n->left != NULL)
                q.push({n->left, line - 1});

            if (n->right != NULL)
                q.push({n->right, line + 1});
        }

        for (auto it : mp)
            res.push_back(it.second);

        return res;
    }

    /**
        @description: function to perform bottom view traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the bottom view traversal of the tree
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n)
    */
    vector<int> bottomView(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        map<int, int> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *n = it.first;
            int line = it.second;

            mp[line] = n->data;

            if (n->left != NULL)
                q.push({n->left, line - 1});

            if (n->right != NULL)
                q.push({n->right, line + 1});
        }

        for (auto it : mp)
            res.push_back(it.second);

        return res;
    }

    void right(TreeNode *root, int level, vector<int> &res)
    {
        if (!root)
            return;

        if (res.size() == level)
            res.push_back(root->data);

        right(root->right, level + 1, res);
        right(root->left, level + 1, res);
    }

    /**
        @description: function to perform right side view traversal of the binary tree
        @param: root: pointer to the root of the binary tree
        @return: vector containing the right side view traversal of the tree
        @time complexity: O(n)
        @space complexity: O(h), where h is the height of the tree
    */
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        right(root, 0, res);

        return res;
    }

    bool mirror(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
            return left == right;

        return (left->data == right->data) && mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    /**
        @description: function to check if the binary tree is symmetric
        @param: root: pointer to the root of the binary tree
        @return: boolean value indicating whether the tree is symmetric or not
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(1), where h is the height of the tree
    */
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return mirror(root->left, root->right);
    }

    bool getPath(TreeNode *root, vector<int> &arr, int x)
    {
        if (!root)
            return false;

        arr.push_back(root->data);
        if (root->data == x)
            return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back();
        return false;
    }

    /**
        @description: function to find the path from the root to a given node in the binary tree
        @param: A: pointer to the root of the binary tree
        @param: B: integer value representing the target node
        @return: vector containing the path from the root to the target node
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n), where n is the number of nodes in the tree
    */
    vector<int> solve(TreeNode *A, int B)
    {
        vector<int> res;
        if (A == NULL)
            return res;

        getPath(A, res, B);

        return res;
    }

    /**
        @description: function to find the lowest common ancestor of two nodes in the binary tree
        @param: root: pointer to the root of the binary tree
        @param: p: pointer to the first node
        @param: q: pointer to the second node
        @return: pointer to the lowest common ancestor of the two nodes
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(h), where h is the height of the tree
    */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);

        if (l == NULL)
            return r;
        else if (r == NULL)
            return l;
        else
            return root;
    }

    /**
        @description: function to change the binary tree to satisfy the children sum property
        @param: root: pointer to the root of the binary tree
        @return: void
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(h), where h is the height of the tree
    */
    void changeTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        int child = 0;
        if (root->left)
            child += root->left->data;
        if (root->right)
            child += root->right->data;

        if (child >= root->data)
            root->data = child;
        else
        {
            if (root->left)
                root->left->data = root->data;
            else if (root->right)
                root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if (root->left)
            tot += root->left->data;
        if (root->right)
            tot += root->right->data;

        if (root->left || root->right)
            root->data = tot;
    }

    void mapParentNodes(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();

            if (n->left)
            {
                parentMap[n->left] = n;
                q.push(n->left);
            }

            if (n->right)
            {
                parentMap[n->right] = n;
                q.push(n->right);
            }
        }
    }

    vector<int> bfsFromTarget(TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parentMap, int k)
    {
        queue<TreeNode *> q;
        unordered_set<TreeNode *> visited;
        int currLevel = 0;

        q.push(target);
        visited.insert(target);

        while (!q.empty())
        {
            int s = q.size();

            if (currLevel++ == k)
                break;

            for (int i = 0; i < s; i++)
            {
                TreeNode *n = q.front();
                q.pop();

                if (n->left && visited.find(n->left) == visited.end())
                {
                    visited.insert(n->left);
                    q.push(n->left);
                }

                if (n->right && visited.find(n->right) == visited.end())
                {
                    visited.insert(n->right);
                    q.push(n->right);
                }

                if (parentMap.count(n) &&
                    visited.find(parentMap[n]) == visited.end())
                {
                    visited.insert(parentMap[n]);
                    q.push(parentMap[n]);
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front()->data);
            q.pop();
        }

        return res;
    }

    /**
        @description: function to find the distance between two nodes in the binary tree
        @param: root: pointer to the root of the binary tree
        @param: target: pointer to the target node
        @param: k: integer value representing the distance between the two nodes
        @return: vector containing the distance between the two nodes
        @time complexity: O(n), where n is the number of nodes in the tree
        @space complexity: O(n)
    */
   vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (!root)
            return {};

        unordered_map<TreeNode *, TreeNode *> parentMap;
        mapParentNodes(root, parentMap);

        return bfsFromTarget(target, parentMap, k);
    }

    int findHeightLeft(TreeNode *node)
    {
        int h = 0;
        while (node)
        {
            h++;
            node = node->left;
        }

        return h;
    }

    int findHeightRight(TreeNode *node)
    {
        int h = 0;
        while (node)
        {
            h++;
            node = node->right;
        }

        return h;
    }

    /**
        @description: function to count the number of nodes in a complete binary tree
        @param: root: pointer to the root of the binary tree
        @return: integer representing the number of nodes in the tree
        @time complexity: O(log(n) * log(n)), where n is the number of nodes in the tree
        @space complexity: O(1)
    */
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = findHeightLeft(root), rh = findHeightRight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(35);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(2);

    TreeProblems t;
    t.changeTree(root);

    cout << "Binary Tree after Children Sum Property: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}