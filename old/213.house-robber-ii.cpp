/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30219
 *
 * [213] 打家劫舍 II
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
    int robb(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nums[0];
        }

        if (left == right)
        {
            return nums[left];
        }
        vector<int> dp(right - left + 1, 0);
        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[left + i], dp[i - 1]);
        }
        return dp.back();
    }

    int rob(vector<int> &nums)
    {

        return max(robb(nums, 0, nums.size() - 2), robb(nums, 1, nums.size() - 1));
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
