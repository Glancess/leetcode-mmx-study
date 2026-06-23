/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30218
 *
 * [55] 跳跃游戏
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
    bool canJump(vector<int> &nums)
    {
        int far = 0;
        for (int i = 0; i <= far; i++)
        {
            far = max(far, nums[i] + i);
            if (far >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */
