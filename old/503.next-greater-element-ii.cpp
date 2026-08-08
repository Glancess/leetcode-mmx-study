/*
 * @lc app=leetcode.cn id=503 lang=cpp
 * @lcpr version=30219
 *
 * [503] 下一个更大元素 II
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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> resu(nums.size(), -1);
        stack<int> st;
        int n = nums.size();
        for (int i = 0; i < 2 * n; i++)
        {
            int index = i % n;
            while (!st.empty() && nums[st.top()] < nums[index])
            {
                resu[st.top()] = nums[index];
                st.pop();
            }
            if (i < n)
            {
                st.push(i);
            }
        }
        return resu;
        }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,3]\n
// @lcpr case=end

 */
