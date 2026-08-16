/*
 * @lc app=leetcode.cn id=718 lang=cpp
 * @lcpr version=30219
 *
 * [718] 最长重复子数组
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
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {

        int ans = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i < nums1.size() + 1; i++)
        {
            for (int j = 1; j < nums2.size() + 1; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,2,1]\n[3,2,1,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n[0,0,0,0,0]\n
// @lcpr case=end

 */
