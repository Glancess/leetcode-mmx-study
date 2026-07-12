/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30219
 *
 * [45] 跳跃游戏 II
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
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int far = 0;
        int cur = 0;
        if (nums.size() == 1)
        {
            return 0;
        }
        for (int i = 0; i <= far; i++)
        {
            far = max(far, nums[i] + i);
            if (i == cur)
            {
                step++;
                cur = far;
            }
            if (cur >= nums.size() - 1)
            {
                return step;
            }
        }
        return 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */
