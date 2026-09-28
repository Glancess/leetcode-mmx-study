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
            int a = t[i] - '0';
            int b = t[i + 1] - '0';
            if (a > b)
            {
                t[i]--;
                while (i > 0)
                {
                    if (t[i] - '0' < t[i - 1] - '0')
                    {
                        i--;
                        t[i]--;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int k = i + 1; k < t.size(); k++)
                {
                    t[k] = '9';
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
