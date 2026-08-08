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
        for (int i = 0; i < nums2.size(); i++)
        {
            while (!st.empty() && st.top() < nums2[i])
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> resu(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {

            if (mp.count(nums1[i]))
            {
                resu[i] = mp[nums1[i]];
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
