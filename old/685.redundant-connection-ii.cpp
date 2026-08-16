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
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> graph(n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 0;
        }
        while (m > 0)
        {
            m--;
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            dp[a][b] = c;
            dp[b][a] = c;
        }
        for (int k = 1; k < n + 1; k++)
        {
            // k作为中转节点
            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < n + 1; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int x;
        cin >> x;
        while (x > 0)
        {
            x--;
            int a, b;
            cin >> a >> b;
            if (dp[a][b] == 1e9)
            {
                cout << -1 << "\n";
            }
            else
                cout << dp[a][b] << "\n";
        }
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
