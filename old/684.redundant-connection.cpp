/*
 * @lc app=leetcode.cn id=684 lang=cpp
 * @lcpr version=30219
 *
 * [684] 冗余连接
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
            {
                father[a] = b;
            }
        }
        /* data */
    } Unionfind;

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        Unionfind uni(edges.size());
        vector<int> resu;
        for (auto &i : edges)
        {
            if (uni.issame(i[0], i[1]))
            {
                resu = i;
            }
            else
            {
                uni.join(i[0], i[1]);
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2], [1,3], [2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
// @lcpr case=end

 */
