/*
 * @lc app=leetcode.cn id=417 lang=cpp
 * @lcpr version=30219
 *
 * [417] 太平洋大西洋水流问题
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
    void DFS(vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &visi)
    {
        int n = heights.size();
        int m = heights[0].size();

        for (auto &i : dr)
        {
            int nx = x + i.first;
            int ny = y + i.second;
            if (nx >= n || ny >= m || nx < 0 || ny < 0)
            {
                continue;
            }
            if (visi[nx][ny])
            {
                continue;
            }
            if (heights[nx][ny] >= heights[x][y])
            {
                visi[x][y] = true;
                DFS(heights, nx, ny, visi);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> v1(n, vector<bool>(m, false));
        vector<vector<bool>> v2(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            DFS(heights, i, 0, v1);
            DFS(heights, i, m - 1, v2);
        }
        for (int i = 0; i < m; i++)
        {
            DFS(heights, 0, i, v1);
            DFS(heights, n - 1, i, v2);
        }
        vector<vector<int>> resu;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v1[i][j] && v2[i][j])
                {
                    resu.push_back({i, j});
                }
            }
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1],[1,2]]\n
// @lcpr case=end

 */
