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
        int sum = 0;
        for (int &i : stones)
        {
            sum += i;
        }
        // 2堆，A ，一堆B。A+B=sum ，求A-B的最小值。A=sum-B；B=sum/2；
        int total = sum / 2;
        vector<int> dp(total + 1, 0);
        dp[0] = 0;
        for (int &i : stones)
        {
            for (int j = total; j >= i; j--)
            {
                dp[j] = max(dp[j - i] + i, dp[j]);
            }
        }
        return abs(2 * dp.back() - sum);
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
