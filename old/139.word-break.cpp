/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30219
 *
 * [139] 单词拆分
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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 1; j < s.size() + 1; j++)
        {
            for (auto &i : wordDict)
            {
                if (j >= i.size() && dp[j - i.size()] && s.substr(j - i.size(), i.size()) == i)
                {
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */
