/*
 * @lc app=leetcode.cn id=738 lang=cpp
 * @lcpr version=30219
 *
 * [738] 单调递增的数字
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
    int monotoneIncreasingDigits(int n)
    {
        string t = to_string(n);
        for (int i = 0; i < t.size() - 1; i++)
        {
            if (t[i] > t[i + 1])
            {
                // 已经找到不符合的位置
                t[i] -= 1;
                while (i >= 1 && t[i] < t[i - 1])
                {
                    i--;
                    t[i] -= 1;
                }

                for (int j = i + 1; j < t.size(); j++)
                {
                    t[j] = '9';
                }
            }
        }
        return stoi(t);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1234\n
// @lcpr case=end

// @lcpr case=start
// 332\n
// @lcpr case=end

 */
