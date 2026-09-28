/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30219
 *
 * [496] 下一个更大元素 I
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_map<int, int> mp;
        stack<int> st;
        for (int &i : nums2)
        {
            while (!st.empty() && st.top() < i)
            {
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> resu;
        for (int &i : nums1)
        {
            if (mp.find(i) != mp.end())
            {
                resu.push_back(mp[i]);
            }
            else
            {
                resu.push_back(-1);
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */
