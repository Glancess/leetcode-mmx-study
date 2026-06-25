/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30219
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string s)
    {
        vector<int> index(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i] - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        vector<int> resu;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, index[s[i] - 'a']);
            if (i == right)
            {
                resu.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */
