/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30219
 *
 * [45] 跳跃游戏 II
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
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int far = 0;
        int cur = 0;
        int step = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 当前范围内不断寻找下一跳最远能到哪里
            far = max(far, nums[i] + i);

            // 当前这一步的范围已经考察完了
            if (i == cur)
            {
                step++;
                cur = far;

                if (cur >= nums.size() - 1)
                {
                    return step;
                }
            }
        }

        return step;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */
