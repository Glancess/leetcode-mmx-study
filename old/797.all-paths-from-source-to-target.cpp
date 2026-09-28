/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=30219
 *
 * [797] 所有可能的路径
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
    vector<vector<int>> resu;
    void DFS(vector<int> path, vector<vector<int>> &graph, int start)
    {
        if (start == graph.size() - 1)
        {
            path.push_back(start);
            resu.push_back(path);
            return;
        }

        for (auto &i : graph[start])
        {
            path.push_back(start);
            DFS(path, graph, i);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<int> path;
        DFS(path, graph, 0);
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */
