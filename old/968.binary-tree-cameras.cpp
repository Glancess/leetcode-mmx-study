/*
 * @lc app=leetcode.cn id=968 lang=cpp
 * @lcpr version=30219
 *
 * [968] 监控二叉树
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
    int sum = 0;
    int get(TreeNode *root)
    {
        if (!root)
        {
            return 2;
        }
        int left = get(root->left);
        int right = get(root->right);
        if (left == 2 && right == 2)
        {

            return 0;
        }
        else if (left == 0 || right == 0)
        {
            sum++;
            return 1;
        }
        return 2;
    }

    int minCameraCover(TreeNode *root)
    {
        if (get(root) == 0)
        {
            sum++;
            return sum;
        }
        else
        {
            return sum;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,0,null,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,null,0,null,0,null,null,0]\n
// @lcpr case=end

 */
