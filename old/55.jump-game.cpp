/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30219
 *
 * [55] 跳跃游戏
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
    int main(void)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph;
        while (m > 0)
        {
            m--;
            int a, b, c;
            cin >> a >> b >> c;
            graph.push_back({a, b, c});
        }
        int src, dst, k;
        cin >> src >> dst >> k;

        vector<int> Mindis(n + 1, 1e9);
        Mindis[src] = 0;
        for (int i = 0; i <= k; i++)
        {
            auto t = Mindis;
            for (auto &j : graph)
            {
                if (t[j[0]] != 1e9)
                {
                    Mindis[j[1]] = min(Mindis[j[1]], t[j[0]] + j[2]);
                }
            }
        }
        if (Mindis[dst] == 1e9)
        {
            cout << "unreachable";
        }
        else
        {
            cout << Mindis[dst];
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */
