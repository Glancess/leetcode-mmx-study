/*
 * @lc app=leetcode.cn id=714 lang=cpp
 * @lcpr version=30219
 *
 * [714] 买卖股票的最佳时机含手续费
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
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int j = 1; j < prices.size(); j++)
        {
            dp[j][0] = max(dp[j - 1][0], dp[j - 1][1] - prices[j]);
            dp[j][1] = max(dp[j - 1][1], dp[j - 1][0] + prices[j] - fee);
        }
        return dp.back().back();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 3, 2, 8, 4, 9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */
