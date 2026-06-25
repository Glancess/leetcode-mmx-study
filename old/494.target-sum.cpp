/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30219
 *
 * [494] 目标和
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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // A-B=tar A+B=sum 2A=tar+sum;A=tar+sum  /2;
        int sum = 0;
        for (int &i : nums)
        {
            sum += i;
        }
        if ((sum + target) % 2)
        {
            return 0;
        }
        int total = (sum + target) / 2;
        if (total < 0)
        {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(total + 1, 0));
        if (nums[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;

            if (nums[0] <= total)
            {
                dp[0][nums[0]] = 1;
            }
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < total + 1; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size() - 1][total];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
