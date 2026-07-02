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
        vector<int> le = robb(root->left);
        vector<int> ri = robb(root->right);
        return {
            le[1] + ri[1] + root->val, max(le[0], le[1]) + max(ri[0], ri[1])};
    }

    int rob(TreeNode *root)
    {
        return max(robb(root)[0], robb(root)[1]);
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
