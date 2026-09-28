/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 * @lcpr version=30219
 *
 * [1091] 二进制矩阵中的最短路径
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
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        vector<vector<int>> dr = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        int n = grid.size();

        if (grid[0][0] == 1)
        {
            return -1;
        }

        queue<pair<int, int>> qu;
        qu.push({0, 0});

        // 标记访问
        grid[0][0] = 1;

        int step = 1;

        while (!qu.empty())
        {
            int size = qu.size();

            while (size--)
            {
                auto t = qu.front();
                qu.pop();

                if (t.first == n - 1 && t.second == n - 1)
                {
                    return step;
                }

                for (auto &i : dr)
                {
                    int dx = t.first + i[0];
                    int dy = t.second + i[1];

                    if (dx < 0 || dy < 0 || dx >= n || dy >= n)
                    {
                        continue;
                    }

                    if (grid[dx][dy] == 0)
                    {
                        grid[dx][dy] = 1;
                        qu.push({dx, dy});
                    }
                }
            }

            step++;
        }

        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[1,1,0],[1,1,0]]\n
// @lcpr case=end

 */
