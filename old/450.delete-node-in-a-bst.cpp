/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30219
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return root;
        }
        if (root->val == key)
        {
            if (!root->left)
            {
                return root->right;
            }
            if (!root->right)
            {
                return root->left;
            }
            if (root->left && root->right)
            {
                TreeNode *t = root->right;
                while (t->left)
                {
                    t = t->left;
                }
                t->left = root->left;
                return root->right;
            }
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
