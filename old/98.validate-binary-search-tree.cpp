/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30219
 *
 * [98] 验证二叉搜索树
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
    TreeNode *pre = nullptr;
    bool tag = true;
    void is(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        is(root->left);
        if (pre && pre->val >= root->val)
        {
            tag = false;
            return;
        }
        pre = root;
        is(root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        is(root);
        return tag;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
