/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30219
 *
 * [188] 买卖股票的最佳时机 IV
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
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, 0));
        for (int i = 0; i < 2 * k; i++)
        {
            if (i % 2)
            {
                dp[0][i] = 0;
            }
            else
            {
                dp[0][i] = -prices[0];
            }
        }
        for (int j = 1; j < prices.size(); j++)
        {
            for (int i = 0; i < 2 * k; i++)
            {
                if (i == 0)

                {

                    dp[j][0] = max(dp[j - 1][0], -prices[j]);
                }
                else if (i % 2)
                {
                    dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - 1] + prices[j]);
                }
                else
                {
                    dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - 1] - prices[j]);
                }
            }
        }
        return dp.back()[2 * k - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */
