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
            // oushu chiyou ,jishu maichu
            if (i % 2)
            {
                dp[0][i] = 0;
            }
            else
            {
                dp[0][i] = -prices[0];
            }
            for (int i = 1; i < prices.size(); i++)
            {
                for (int j = 0; j < 2 * k; j++)
                {
                    if (j == 0)
                    {
                        dp[i][j] = max(dp[i - 1][j], -prices[i]);
                        continue;
                    }

                    if (j % 2)
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                    }
                }
            }
        }
        int maxx = 0;
        for (int i = 0; i < 2 * k; i++)
        {
            if (dp.back()[i] > maxx)
            {
                maxx = dp.back()[i];
            }
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
