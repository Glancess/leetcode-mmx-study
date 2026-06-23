/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30218
 *
 * [63] 不同路径 II
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 0; i < obstacleGrid[0].size(); i++)
        {
            if (obstacleGrid[0][i] == 1)
            {
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 1; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */
