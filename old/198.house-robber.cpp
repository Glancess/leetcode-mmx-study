/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30219
 *
 * [198] 打家劫舍
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
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1)
        {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int j = 2; j < nums.size(); j++)
        {
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[j]);
        }
        return dp[nums.size() - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */
