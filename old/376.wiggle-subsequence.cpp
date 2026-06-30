/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=30219
 *
 * [376] 摆动序列
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
    int wiggleMaxLength(vector<int> &nums)
    {
        int count = 1;
        int pre = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int diff = nums[i + 1] - nums[i];
            if (diff < 0 && pre >= 0)
            {
                count++;
                pre = diff;
            }
            if (diff > 0 && pre <= 0)
            {
                count++;
                pre = diff;
            }
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,4,9,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,17,5,10,13,15,10,5,16,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end

 */
