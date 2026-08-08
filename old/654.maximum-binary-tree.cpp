/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30219
 *
 * [654] 最大二叉树
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
    int findindex(vector<int> &nums, int l, int r)
    {
        int maxx = -1;
        int maxxindex = -1;
        for (int i = l; i <= r; i++)
        {
            if (maxx < nums[i])
            {
                maxx = nums[i];
                maxxindex = i;
            }
        }
        return maxxindex;
    }

    TreeNode *build(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int index = findindex(nums, l, r);
        TreeNode *root = new TreeNode(nums[index]);
        root->left = build(nums, l, index - 1);
        root->right = build(nums, index + 1, r);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */
