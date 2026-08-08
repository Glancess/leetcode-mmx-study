/*
 * @lc app=leetcode.cn id=743 lang=cpp
 * @lcpr version=30219
 *
 * [743] 网络延迟时间
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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> Mindis(n + 1, 1e9);
        Mindis[k] = 0;
        queue<int> qu;
        vector<bool> inqu(n + 1, false);
        for (auto &i : times)
        {
            graph[i[0]].push_back({i[1], i[2]});
        }
        qu.push(k);
        inqu[k] = true;
        while (!qu.empty())
        {
            int t = qu.front();
            qu.pop();
            inqu[t] = false;
            for (auto &j : graph[t])
            {
                if (Mindis[j.first] > Mindis[t] + j.second)
                {
                    Mindis[j.first] = Mindis[t] + j.second;
                    qu.push(j.first);
                    inqu[j.first];
                }
            }
        }
        int resu = 0;
        for (int i = 1; i < Mindis.size(); i++)
        {
            if (Mindis[i] == 1e9)
            {
                return -1;
            }
            else
            {
                resu = max(resu, Mindis[i]);
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */
