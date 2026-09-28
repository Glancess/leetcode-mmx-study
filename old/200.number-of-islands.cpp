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
    vector<vector<int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void DFS(vector<vector<char>> &grid, int x, int y)
    {
        if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0 || grid[x][y] == '0')
        {
            return;
        }
        grid[x][y] = '0';
        DFS(grid, x, y - 1);
        DFS(grid, x, y + 1);
        DFS(grid, x - 1, y);
        DFS(grid, x + 1, y);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
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
