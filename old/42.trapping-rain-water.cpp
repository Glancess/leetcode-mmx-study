/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30219
 *
 * [42] 接雨水
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
    int trap(vector<int> &height)
    {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[st.top()] < height[i])
            {
                int t = st.top();
                st.pop();
                if (st.empty())
                {
                    break;
                }
                int high = min(height[i], height[st.top()]) - height[t];
                int wide = i - st.top() - 1;
                ans += high * wide;
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
