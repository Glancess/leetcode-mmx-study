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
        vector<int> searccc(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            searccc[s[i] - 'a'] = i;
        }
        int far = 0;
        int j = 0;
        vector<int> resu;
        for (int i = 0; i < s.size(); i++)
        {
            far = max(searccc[s[i] - 'a'], far);
            if (i == far)
            {
                resu.push_back(i - j + 1);
                j = i + 1;
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
