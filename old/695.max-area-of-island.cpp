/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30219
 *
 * [695] 岛屿的最大面积
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
    int DFS(vector<vector<int>> &grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (x >= m || y >= n || x < 0 || y < 0 || grid[x][y] == 0)
        {
            return 0;
        }
        grid[x][y] = 0;
        return 1 + DFS(grid, x + 1, y) + DFS(grid, x, y - 1) + DFS(grid, x - 1, y) + DFS(grid, x, y + 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxarea = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    maxarea = max(maxarea, DFS(grid, i, j));
                }
            }
        }
        return maxarea;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */
