/*
 * @lc app=leetcode.cn id=827 lang=cpp
 * @lcpr version=30219
 *
 * [827] 最大人工岛
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
    int DFS(vector<vector<int>> &grid, int target, int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (x >= n || y >= m || x < 0 || y < 0 || grid[x][y] != 1)
        {
            return 0;
        }
        grid[x][y] = target;
        return 1 + DFS(grid, target, x + 1, y) + DFS(grid, target, x - 1, y) + DFS(grid, target, x, y + 1) + DFS(grid, target, x, y - 1);
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int target = 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    mp[target] = DFS(grid, target, i, j);
                    target++;
                }
            }
        }
        int resu = 0;
        vector<pair<int, int>> dr = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> st;
                    for (auto &k : dr)
                    {
                        int nx = i + k.first;
                        int ny = j + k.second;
                        if (nx >= n || ny >= m || nx < 0 || ny < 0 || grid[nx][ny] == 0)
                        {
                            continue;
                        }
                        st.insert(grid[nx][ny]);
                    }
                    int sum = 1;
                    for (auto &l : st)
                    {
                        sum += mp[l];
                    }
                    resu = max(resu, sum);
                }
            }
        }
        return resu == 0 ? n * m : resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1, 0], [0, 1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 1], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 1], [1, 1]]\n
// @lcpr case=end

 */
