/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30218
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *so(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return new TreeNode(nums[left]);
        }
        if (left > right)
        {
            return nullptr;
        }
        int index = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[index]);
        root->left = so(nums, left, index - 1);
        root->right = so(nums, index + 1, right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return so(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */
