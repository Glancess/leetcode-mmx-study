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
        // 定义 偶数持有，奇数不持有
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, 0));
        for (int i = 0; i < 2 * k; i++)
        {
            if (i % 2 == 0)
            {
                dp[0][i] = -prices[0];
            }
            else
            {
                dp[0][i] = 0;
            }
        }
        for (int j = 1; j < prices.size(); j++)
        {
            for (int i = 0; i < 2 * k; i++)
            {
                if (i == 0)
                {
                    dp[j][0] = max(-prices[j], dp[j - 1][0]);
                }
                else if (i % 2 == 0)
                {
                    dp[j][i] = max(dp[j - 1][i - 1] - prices[j], dp[j - 1][i]);
                }
                else if (i % 2 == 1)
                {
                    dp[j][i] = max(dp[j - 1][i - 1] + prices[j], dp[j - 1][i]);
                }
            }
        }
        int maxx = 0;
        for (int i = 0; i < 2 * k; i++)
        {
            maxx = max(maxx, dp.back()[i]);
        }
        return maxx;
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
