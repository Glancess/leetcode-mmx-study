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
    int getmax(int left, int right, vector<int> &nums)
    {
        int index = -1;
        int maxx = -1e9;
        for (int i = left; i <= right; i++)
        {
            if (maxx < nums[i])
            {
                maxx = nums[i];
                index = i;
            }
        }
        return index;
    }
    TreeNode *get(int left, int right, vector<int> &nums)
    {
        if (left == right)
        {
            return new TreeNode(nums[left]);
        }
        if (right < left)
        {
            return nullptr;
        }
        int ind = getmax(left, right, nums);
        TreeNode *root = new TreeNode(nums[ind]);
        root->left = get(left, ind - 1, nums);
        root->right = get(ind + 1, right, nums);
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return get(0, nums.size() - 1, nums);
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
