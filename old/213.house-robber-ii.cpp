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
    int robRange(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];

        vector<int> dp(right - left + 1);

        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);

        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 1],
                        dp[i - 2] + nums[left + i]);
        }

        return dp.back();
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            robRange(nums, 0, n - 2),
            robRange(nums, 1, n - 1));
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
