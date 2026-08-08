/*
 * @lc app=leetcode.cn id=787 lang=cpp
 * @lcpr version=30219
 *
 * [787] K 站中转内最便宜的航班
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
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> graph(n + 1);
        while (m > 0)
        {
            m--;
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }
        queue<int> qu;
        vector<bool> inqu(n + 1, false);
        vector<int> Mindis(n + 1, 1e9);
        vector<int> cnt(n + 1, 0);
        Mindis[1] = 0;
        qu.push(1);
        cnt[1] = 1;
        inqu[1] = true;
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
                    if (!inqu[j.first])
                    {
                        qu.push(j.first);
                        cnt[j.first]++;
                        inqu[j.first] = true;
                        if (cnt[j.first] >= n)
                        {
                            cout << "circle";
                            return 0;
                        }
                    }
                }
            }
            if (Mindis[n] == 1e9)
                cout << "unconnected";
            else
                cout << Mindis[n];
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]\n0\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n0\n
// @lcpr case=end

 */
