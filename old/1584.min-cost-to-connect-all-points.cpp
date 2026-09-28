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
    struct Unionfind
    {
        vector<int> father;
        Unionfind(int n)
        {
            father.resize(n + 1);
            for (int i = 0; i < n + 1; i++)
            {
                father[i] = i;
            }
        }
        int find(int a)
        {
            if (father[a] == a)
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
            if (a != b)
                father[a] = b;
        }
        /* data */
    };

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        // 最小生成树
        int n = points.size();
        vector<int> Mindis(n, 1e9);
        Mindis[0] = 0;
        int waste = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            int Minindex = -1;
            int Mind = 1e9;
            for (int i = 0; i < Mindis.size(); i++)
            {
                if (!visited[i] && Mind > Mindis[i])
                {
                    Minindex = i;
                    Mind = Mindis[i];
                }
            }
            visited[Minindex] = true;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j])
                {
                    int dis =
                        abs(points[Minindex][0] - points[j][0]) +
                        abs(points[Minindex][1] - points[j][1]);

                    Mindis[j] = min(Mindis[j], dis);
                }
            }
        }
        for (int &i : Mindis)
        {
            waste += i;
        }
        return waste;
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
