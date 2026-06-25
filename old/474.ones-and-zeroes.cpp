/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30218
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
        vector<vector<vector<int>>> dp(
            strs.size(),
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, 0)));

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                int zero = count(strs[0].begin(), strs[0].end(), '0');
                int one = strs[0].size() - zero;
                if (zero <= i && one <= j)
                    dp[0][i][j] = 1;
            }
        }
        for (int k = 1; k < strs.size(); k++)
        {
            for (int i = 0; i < m + 1; i++)
            {
                for (int j = 0; j < n + 1; j++)
                {
                    int zero = count(strs[k].begin(), strs[k].end(), '0');
                    int one = strs[k].size() - zero;
                    if (zero <= i && one <= j)
                        dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - zero][j - one] + 1);
                    else
                        dp[k][i][j] = dp[k - 1][i][j];
                }
            }
        }
        return dp[strs.size() - 1][m][n];
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
