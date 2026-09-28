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
    vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int res = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int t = 4;
                    for (auto &k : dr)
                    {
                        int nx = i + k.first;
                        int ny = j + k.second;
                        if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())
                        {
                            continue;
                        }
                        if (grid[nx][ny])
                        {
                            t--;
                        }
                    }
                    res += t;
                }
            }
        }
        return res;
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
