/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30219
 *
 * [474] 一和零
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
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &k : strs)
        {
            int ze = count(k.begin(), k.end(), '0');
            int on = k.size() - ze;

            for (int i = m; i >= ze; i--)
            {
                for (int j = n; j >= on; j--)
                {
                    dp[i][j] = max(dp[i - ze][j - on] + 1, dp[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["10", "0001", "111001", "1", "0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10", "0", "1"]\n1\n1\n
// @lcpr case=end

 */
