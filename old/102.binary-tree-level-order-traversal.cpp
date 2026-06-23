/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30212
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> resu;
        queue<TreeNode *> qu;
        if (!root)
        {
            return {};
        }
        qu.push(root);
        while (!qu.empty())
        {

            int size = qu.size();
            vector<int> path;
            while (size > 0)
            {

                TreeNode *cur = qu.front();
                path.push_back(cur->val);
                qu.pop();
                if (cur->left)
                {
                    qu.push(cur->left);
                }
                if (cur->right)
                {
                    qu.push(cur->right);
                }
                size--;
            }
            resu.push_back(path);
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
