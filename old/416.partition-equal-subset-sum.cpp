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
        vector<vector<bool>> dp(nums.size(), vector<bool>(total + 1, false));

        if (nums[0] <= total)
        {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j < total + 1; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                else
                {
                    dp[i][j] = dp[i - 1][j];
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
