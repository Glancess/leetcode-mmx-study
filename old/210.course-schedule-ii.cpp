/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30219
 *
 * [210] 课程表 II
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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &i : prerequisites)
        {
            int from = i[1];
            int to = i[0];
            graph[from].push_back(to);
            indegree[to]++;
        }
        queue<int> qu;
        vector<int> path;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
            }
        }
        while (!qu.empty())
        {
            int t = qu.front();
            qu.pop();
            path.push_back(t);
            for (int &j : graph[t])
            {
                indegree[j]--;
                if (indegree[j] == 0)
                {
                    qu.push(j);
                }
            }
        }
        if (path.size() == numCourses)
        {
            return path;
        }
        else
        {
            return {};
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */
