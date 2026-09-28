/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 * @lcpr version=30219
 *
 * [1334] 阈值距离内邻居最少的城市
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
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // floydsuanfa
        vector<vector<int>> edge(n, vector<int>(n, 1e9));
        for (auto &i : edges)
        {
            edge[i[0]][i[1]] = i[2];
            edge[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i < n; i++)
        {
            edge[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
                }
            }
        }
        int mincount = 1e9;
        int minindex = -1;
        for (int i = 0; i < n; i++)
        {

            int ans = 0;
            for (int &j : edge[i])
            {
                if (j <= distanceThreshold)
                {
                    ans++;
                }
            }
            if (mincount >= ans)
            {
                mincount = ans;
                minindex = i;
            }
        }
        return minindex;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]\n2\n
// @lcpr case=end

 */
