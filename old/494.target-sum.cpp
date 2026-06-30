/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30219
 *
 * [494] 目标和
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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int &i : nums)
        {
            sum += i;
        }
        if ((sum + target) % 2 != 0)
            return 0;
        if (abs(target) > sum)
        {
            return 0;
        }
        {
        }
        int total = (target + sum) / 2;
        vector<int> dp(total + 1, 0);
        dp[0] = 1;
        for (int num : nums)
        {
            if (num == 0)
            {
                // 所有方案翻倍
                for (int j = 0; j <= total; j++)
                    dp[j] *= 2;
            }
            else
            {
                // 0-1 背包
                for (int j = total; j >= num; j--)
                    dp[j] += dp[j - num];
            }
        }
        return dp[total];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
