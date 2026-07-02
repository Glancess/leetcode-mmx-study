/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30219
 *
 * [121] 买卖股票的最佳时机
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
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int j = 1; j < prices.size(); j++)
        {
            dp[j][0] = max(dp[j - 1][0], dp[j - 1][1] + prices[j]);
            dp[j][1] = max(dp[j - 1][1], -prices[j]);
        }
        return dp.back()[0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
