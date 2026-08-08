/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30219
 *
 * [257] 二叉树的所有路径
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
    vector<string> resu;
    void backtracking(TreeNode *root, string s)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            s += to_string(root->val);
            resu.push_back(s);
            return;
        }
        backtracking(root->left, s + to_string(root->val) + "->");
        backtracking(root->right, s + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        backtracking(root, "");
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
