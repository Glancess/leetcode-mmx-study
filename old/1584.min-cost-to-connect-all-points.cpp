/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 * @lcpr version=30219
 *
 * [1584] 连接所有点的最小费用
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
    typedef struct edge
    {
        /* data */
        int from;
        int to;
        int distance;
    };
    typedef struct Unionfind
    {
        vector<int> father;

        Unionfind(int n)
        {
            father.resize(n + 1);
            for (int i = 0; i < n + 1; i++)
            {
                father[i] = i;
            }
        } /* data */
        int find(int a)
        {
            if (a == father[a])
            {
                return a;
            }
            return father[a] = find(father[a]);
        }
        bool issame(int a, int b)
        {
            return find(a) == find(b);
        }
        void join(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a == b)
            {
                return;
            }
            else
            {
                father[a] = b;
            }
        }
    };

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int res = 0;

        vector<bool> visited(n, false);

        vector<int> minDist(n, INT_MAX);

        minDist[0] = 0;

        for (int i = 0; i < n; i++)
        {
            int cur = -1;
            int minVal = INT_MAX;

            // 找距离树最近的点
            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && minDist[j] < minVal)
                {
                    minVal = minDist[j];
                    cur = j;
                }
            }
            // 加入树
            visited[cur] = true;
            res += minVal;

            for (int j = 0; j < n; j++)
            {
                if (!visited[j])
                {
                    int dis = abs(points[j][0] - points[cur][0]) + abs(points[j][1] - points[cur][1]);
                    minDist[j] = min(minDist[j], dis);
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0],[2,2],[3,10],[5,2],[7,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,12],[-2,5],[-4,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[1,0],[-1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[-1000000,-1000000],[1000000,1000000]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0]]\n
// @lcpr case=end

 */
