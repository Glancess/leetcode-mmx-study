/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30217
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> resu;
    TreeNode *pre = nullptr;
    int maxcount = 0;
    int count = 0;
    void getmany(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        getmany(root->left);
        if (pre && pre->val == root->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        pre = root;
        if (count > maxcount)
        {
            resu.clear();
            resu.push_back(root->val);
            maxcount = count;
        }
        else if (count == maxcount)
        {
            resu.push_back(root->val);
        }
        getmany(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        getmany(root);
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
