/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 * @lcpr version=30219
 *
 * [1049] 最后一块石头的重量 II
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
    int lastStoneWeightII(vector<int> &stones)
    {
        // 本来 选两块石头，碰撞，然后a-b的绝对值。剩余的作为新石头，继续碰撞。
        //  a1-b1 a2-b2 a3-b3 继续 a1-b1-a2+b2-a3+b3，总有些石头前面是+，有些是-
        int sum = 0;
        for (int &i : stones)
        {
            sum += i;
        }
        int total = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(total + 1, 0));
        for (int i = 0; i < stones.size(); i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i < total + 1; i++)
        {
            if (i >= stones[0])
            {
                dp[0][i] = stones[0];
            }
        }
        for (int i = 1; i < stones.size(); i++)
        {
            for (int j = 1; j < total + 1; j++)
            {
                if (j >= stones[i])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return abs(2 * dp[stones.size() - 1][total] - sum);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,4,1,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [31,26,33,21,40]\n
// @lcpr case=end

 */
