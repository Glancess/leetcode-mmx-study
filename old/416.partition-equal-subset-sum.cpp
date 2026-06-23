/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30218
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
        if (sum % 2 != 0)
        {
            return false;
        }
        int total = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(total + 1, false));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = true;
        }
        for (int i = 0; i < total + 1; i++)
        {
            if (i == nums[0])
            {
                dp[0][i] = true;
            }
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= total; j++)
            {
                if (nums[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][total];
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
