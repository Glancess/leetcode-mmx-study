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
    int ant = 0;
    // 1 biaoshi fangshexiangtou,0meibeijiankong,2biaoshibeijiankong
    int get(TreeNode *root)
    {
        if (!root)
        {
            return 2;
        }
        int l = get(root->left);
        int r = get(root->right);
        if (l == 0 || r == 0)
        {
            ant++;
            return 1;
        }
        else if (l == 1 || r == 1)
        {

            return 2;
        }
        else if (l == 2 && r == 2)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
    int minCameraCover(TreeNode *root)
    {
        ant = 0;

        if (get(root) == 0)
        {
            ant++;
        }

        return ant;
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
