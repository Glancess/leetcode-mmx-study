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
        bool issame(int a, int b)
        {
            return find(a) == find(b);
        }
        /* data */
    };

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        vector<int> indegree(edges.size() + 1, 0);
        for (auto &i : edges)
        {
            int u = i[0];
            int v = i[1];
            indegree[v]++;
        }
        vector<int> edge1;
        vector<int> edge2;
        for (auto &i : edges)
        {
            if (indegree[i[1]] == 2)
            {
                if (edge1.empty())
                {
                    edge1 = i;
                }
                else
                {
                    edge2 = i;
                }
            }
        } // 得到两条入度边，edge2较次
        vector<int> resu = edge2;
        if (!edge1.empty())
        {
            Unionfind un(edges.size());
            for (auto &i : edges)
            {
                if (i == edge2)
                {
                    continue;
                }
                if (un.issame(i[0], i[1]))
                {
                    resu = edge1;
                }
                else
                {
                    un.join(i[0], i[1]);
                }
            }
            return resu;
        }
        else
        {
            Unionfind un(edges.size());
            for (auto &i : edges)
            {
                if (un.issame(i[0], i[1]))
                {
                    resu = i;
                }
                else
                {
                    un.join(i[0], i[1]);
                }
            }
            return resu;
        }
        return {};
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
