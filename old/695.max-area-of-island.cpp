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
        int n = grid.size();
        int m = grid[0].size();
        if (x >= n || y >= m || x < 0 || y < 0 || grid[x][y] == 0)
        {
            return 0;
        }
        grid[x][y] = 0;
        return 1 + DFS(grid, x + 1, y) + DFS(grid, x - 1, y) + DFS(grid, x, y + 1) + DFS(grid, x, y - 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int resu = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    int area = DFS(grid, i, j);
                    resu = max(resu, area);
                }
            }
        }
        return resu;
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
