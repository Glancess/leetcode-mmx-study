/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30219
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit(vector<int> &prices)
    {
        // 0表示持有，1表示当天卖，2表示自由，3表示冷冻
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][2] - prices[i], dp[i - 1][3] - prices[i]});
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);
            dp[i][3] = dp[i - 1][1];
        }
        return max({dp.back()[1], dp.back()[2], dp.back()[3]});
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
