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
    // MST
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
        }
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
            father[a] = b;
        }

        /* data */
    };

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<int> Mindis(points.size(), 1e9);
        vector<bool> Visited(points.size(), false);
        Mindis[0] = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int Minindex = -1;
            int Minn = 1e9;
            for (int j = 0; j < points.size(); j++)
            {
                if ()
            }
        }
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
