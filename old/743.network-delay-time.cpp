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
        vector<vector<pair<int, int>>> edge(n + 1);
        for (auto &i : times)
        {
            edge[i[0]].push_back({i[1], i[2]});
        }
        vector<int> Mindis(n + 1, 1e9);
        Mindis[k] = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            int Mindistance = 1e9;
            int Minindex = -1;
            for (int j = 1; j <= n; j++)
            {
                if (!visited[j] && Mindistance > Mindis[j])
                {
                    Mindistance = Mindis[j];
                    Minindex = j;
                }
            }
            if (Minindex == -1)
            {
                break;
            }
            // biao ji
            visited[Minindex] = true;
            // kai shi song chi

            for (auto &k : edge[Minindex])
            {
                if (!visited[k.first] && Mindis[k.first] > Mindis[Minindex] + k.second)
                {
                    Mindis[k.first] = Mindis[Minindex] + k.second;
                }
            }
        }
        int ans = *max_element(Mindis.begin() + 1, Mindis.end());

        if (ans == 1e9)
        {
            return -1;
        }

        return ans;
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
