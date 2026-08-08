/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30219
 *
 * [200] 岛屿数量
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
    void DFS(vector<vector<char>> &grid, int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (x >= n || y >= m || x < 0 || y < 0 || grid[x][y] == '0')
        {
            return;
        }
        grid[x][y] = '0';
        DFS(grid, x + 1, y);
        DFS(grid, x - 1, y);
        DFS(grid, x, y + 1);
        DFS(grid, x, y - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    DFS(grid, i, j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]\n
// @lcpr case=end

// @lcpr case=start
// [['1','1','0','0','0'],['1','1','0','0','0'],['0','0','1','0','0'],['0','0','0','1','1']]\n
// @lcpr case=end

 */
