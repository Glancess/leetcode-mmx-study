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
        vector<vector<int>> dr = {{1, 0},
                                  {-1, 0},
                                  {0, 1},
                                  {0, -1},
                                  {1, 1},
                                  {1, -1},
                                  {-1, 1},
                                  {-1, -1}};
        if (grid[0][0] == 1)
        {
            return -1;
        }
        queue<pair<int, int>> qu;
        qu.push({0, 0});
        grid[0][0] = 1;
        int result = 1;
        while (!qu.empty())
        {
            int size = qu.size();

            while (size > 0)
            {
                size--;
                auto [x, y] = qu.front();
                qu.pop();
                if (x == grid.size() - 1 && y == grid.size() - 1)
                {
                    return result;
                }
                for (auto i : dr)
                {
                    int nx = x + i[0];
                    int ny = y + i[1];

                    if (nx >= grid.size() || ny >= grid.size() || nx < 0 || ny < 0 || grid[nx][ny])
                    {
                        continue;
                    }

                    grid[nx][ny] = 1;
                    qu.push({nx, ny});
                }
                /* code */
            }
            result++;
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
