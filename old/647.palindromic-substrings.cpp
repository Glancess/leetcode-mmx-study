/*
 * @lc app=leetcode.cn id=647 lang=cpp
 * @lcpr version=30219
 *
 * [647] 回文子串
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
    int countSubstrings(string s)
    {
        int resu = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i > -1; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j])
                {
                    resu++;
                }
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

 */
