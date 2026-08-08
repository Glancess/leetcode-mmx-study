/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30219
 *
 * [207] 课程表
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &i : prerequisites)
        {
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> qu;
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
            for (int &i : graph[t])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    qu.push(i);
                }
            }
        }
        return indegree == vector<int>(numCourses, 0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */
