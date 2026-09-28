/*
 * @lc app=leetcode.cn id=685 lang=cpp
 * @lcpr version=30219
 *
 * [685] 冗余连接 II
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
        bool issame(int a, int b)
        {
            return find(a) == find(b);
        }
        int find(int a)
        {
            if (father[a] == a)
            {
                return a;
            }
            return father[a] = find(father[a]);
        }
        void join(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                father[a] = b;
            }
        }
        /* data */
    };

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        vector<int> indegree(edges.size() + 1, 0);
        // cha ru du wei 2 de
        for (auto &i : edges)
        {
            indegree[i[1]]++;
        }
        vector<int> edge1, edge2;
        for (auto &i : edges)
        {
            if (indegree[i[1]] == 2)
            {
                if (!edge1.empty())
                {
                    edge2 = i;
                }
                else
                {
                    edge1 = i;
                }
            }
        }
        vector<int> resu;
        if (edge2.empty())
        {
            Unionfind uni2(edges.size());
            for (auto &i : edges)
            {
                if (uni2.issame(i[0], i[1]))
                {
                    resu = i;
                }
                else
                {
                    uni2.join(i[0], i[1]);
                }
            }
        }
        else
        {

            resu = edge2;
            Unionfind uni1(edges.size());
            for (auto &i : edges)
            {
                if (i == edge2)
                {
                    continue;
                }
                if (uni1.issame(i[0], i[1]))
                {
                    resu = edge1;
                }
                else
                {
                    uni1.join(i[0], i[1]);
                }
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,1],[1,5]]\n
// @lcpr case=end

 */
