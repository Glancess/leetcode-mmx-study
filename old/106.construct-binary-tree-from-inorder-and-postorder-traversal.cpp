/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30219
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    int findIndex(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr)
    {
        for (int i = il; i <= ir; i++)
        {
            if (inorder[i] == postorder[pr])
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *gett(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr)
    {
        if (il > ir)
        {
            return nullptr;
        }
        int index = findIndex(inorder, il, ir, postorder, pl, pr);
        TreeNode *root = new TreeNode(inorder[index]);
        int size = index - il;
        root->left = gett(inorder, il, index - 1, postorder, pl, pl + size - 1);
        root->right = gett(inorder, index + 1, ir, postorder, pl + size, pr - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return gett(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
