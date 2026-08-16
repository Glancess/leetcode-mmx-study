/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30219
 *
 * [279] 完全平方数
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
    int numSquares(int n)
    {
        vector<int> bag;
        for (int i = 1; i * i <= n; i++)
        {
            bag.push_back(i * i);
        }
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int &i : bag)
        {
            for (int j = i; j < n + 1; j++)
            {
                dp[j] = min(dp[j], dp[j - i] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
