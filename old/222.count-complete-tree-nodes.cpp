/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30212
 *
 * [222] 完全二叉树的节点个数
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
    int getHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (left == right)
        {
            // 左子树必须满
            return (1 << left) + countNodes(root->right);
        }
        else
        {
            return (1 << right) + countNodes(root->left);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
