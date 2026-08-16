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
        vector<int> Mindis(n, 1e9);
        Mindis[src] = 0;
        for (int i = 0; i <= k; i++)
        {
            vector<int> t = Mindis;

            for (auto &k : flights)
            {
                if (t[k[0]] != 1e9)
                {
                    Mindis[k[1]] = min(Mindis[k[1]], t[k[0]] + k[2]);
                }
            }
        }
        return Mindis[dst] == 1e9 ? -1 : Mindis[dst];
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
