/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30219
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int &i : coins)
            for (int j = i; j < amount + 1; j++)
            {
                dp[j] = min(dp[j], dp[j - i] + 1);
            }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
