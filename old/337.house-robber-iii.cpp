/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30219
 *
 * [337] 打家劫舍 III
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
    vector<int> robb(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }
        auto l = robb(root->left);
        auto r = robb(root->right);
        return {root->val + l[1] + r[1], max(l[1], l[0]) + max(r[1], r[0])};
    }

    int rob(TreeNode *root)
    {
        auto resu = robb(root);
        return max(resu[0], resu[1]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
