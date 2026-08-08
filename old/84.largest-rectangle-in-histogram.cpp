/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30219
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int> &heights)
    {
        int resu = 0;
        heights.push_back(0);
        stack<int> st; // 单调增
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int t = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                resu = max(resu, heights[t] * (i - left - 1));
            }
            st.push(i);
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
