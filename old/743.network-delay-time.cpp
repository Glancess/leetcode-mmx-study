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
        // bell-man ford--upgrade

        // i need edges
        vector<vector<vector<int>>> edges(n + 1);
        for (auto &i : times)
        {
            edges[i[0]].push_back({i[1], i[2]});
        }
        vector<int> Mindis(n + 1, 1e9);
        Mindis[k] = 0;
        queue<int> qu;
        qu.push(k);
        vector<bool> inque(n + 1, false);
        inque[k] = true;
        while (!qu.empty())
        {
            int t = qu.front();
            inque[t] = false;
            qu.pop();
            for (auto &i : edges[t])
            {
                if (Mindis[i[0]] > Mindis[t] + i[1])
                {
                    Mindis[i[0]] = Mindis[t] + i[1];
                    if (!inque[i[0]])
                    {

                        qu.push(i[0]);
                        inque[i[0]] = true;
                    }
                }
            }
        }
        int resu = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (Mindis[i] == 1e9)
            {
                return -1;
            }
            resu = max(Mindis[i], resu);
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
