/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30218
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int sum = 0;
        sort(g.begin(), g.end(), [](int &a, int &b)
             { return a < b; });
        sort(s.begin(), s.end(), [](int &a, int &b)
             { return a < b; });
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                sum++;
                j++;
                i++;
            }
            else
            {
                j++;
            }
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */
