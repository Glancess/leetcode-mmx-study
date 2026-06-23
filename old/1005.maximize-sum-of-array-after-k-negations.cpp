/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 * @lcpr version=30218
 *
 * [1005] K 次取反后最大化的数组和
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
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](int &i, int &j)
             { return abs(i) > abs(j); });
        for (int &i : nums)
        {
            if (i < 0 && k > 0)
            {
                k--;
                i = -i;
            }
        }
        if (k % 2)
        {
            nums.back() = -nums.back();
        }
        int sum = 0;
        for (int &i : nums)
        {
            sum += i;
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,-1,0,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,-3,-1,5,-4]\n2\n
// @lcpr case=end

 */
