/*
 * @lc app=leetcode.cn id=463 lang=cpp
 * @lcpr version=30219
 *
 * [463] 岛屿的周长
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
    int islandPerimeter(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    int zhouzhang = 4;
                    for (auto &k : dr)
                    {
                        int nx = i + k.first;
                        int ny = j + k.second;
                        if (nx >= n || ny >= m || nx < 0 || ny < 0)
                        {
                            continue;
                        }
                        if (grid[nx][ny])
                        {
                            zhouzhang--;
                        }
                    }
                    result += zhouzhang;
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0]]\n
// @lcpr case=end

 */
