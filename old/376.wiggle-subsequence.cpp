/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=30218
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
        if (nums.size() < 2)
            return nums.size();

        int res = 1;
        int prevDiff = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];

            if ((diff > 0 && prevDiff <= 0) ||
                (diff < 0 && prevDiff >= 0))
            {
                res++;
                prevDiff = diff;
            }
        }

        return res;
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
