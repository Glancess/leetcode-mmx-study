/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30219
 *
 * [377] 组合总和 Ⅳ
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
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j < target + 1; j++)
        {
            for (int &i : nums)
            {
                if (j >= i)
                {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */
