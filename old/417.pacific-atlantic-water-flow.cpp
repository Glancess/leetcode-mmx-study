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
    vector<vector<int>> dr = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void DFS(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y)
    {
        visited[x][y] = true;
        for (auto &i : dr)
        {
            int nx = i[0] + x;
            int ny = i[1] + y;
            if (nx >= heights.size() || ny >= heights[0].size() || nx < 0 || ny < 0 || visited[nx][ny])
            {
                continue;
            }
            if (heights[nx][ny] < heights[x][y])
            {
                continue;
            }

            DFS(heights, visited, nx, ny);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visited1(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> visited2(heights.size(), vector<bool>(heights[0].size(), false));
        for (int i = 0; i < m; i++)
        {
            DFS(heights, visited1, 0, i);
            DFS(heights, visited2, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            DFS(heights, visited1, i, 0);
            DFS(heights, visited2, i, m - 1);
        }
        vector<vector<int>> resu;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited1[i][j] && visited2[i][j])
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
