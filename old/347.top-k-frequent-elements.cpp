/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30212
 *
 * [347] 前 K 个高频元素
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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int &i : nums)
        {
            mp[i]++;
        }
        auto cmp = [](pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);
        for (auto &i : mp)
        {
            if (pq.size() < k)
            {
                pq.push(i);
            }
            else
            {
                if (pq.top().second < i.second)
                {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        vector<int> resu;
        while (!pq.empty())
        {
            resu.push_back(pq.top().first);
            pq.pop();
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,3,1,3,2]\n2\n
// @lcpr case=end

 */
