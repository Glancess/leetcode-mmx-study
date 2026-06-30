/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30219
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int &i : nums)
        {
            sum += i;
        }
        if (sum % 2)
        {
            return false;
        }
        int total = sum / 2;
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        for (int &i : nums)
        {
            for (int j = total; j > 0; j--)
            {
                if (j >= i)
                    dp[j] = dp[j] || dp[j - i];
            }
        }
        return dp[total];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
