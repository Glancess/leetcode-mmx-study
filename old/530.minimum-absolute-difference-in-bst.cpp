/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30219
 *
 * [530] 二叉搜索树的最小绝对差
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
    int minn = 1e9;
    TreeNode *pre = nullptr;
    void getmin(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        getmin(root->left);
        if (pre)
        {
            minn = root->val - pre->val < minn ? root->val - pre->val : minn;
        }
        pre = root;
        getmin(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        getmin(root);
        return minn;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */
