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
        vector<int> resu;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

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
            resu.push_back(t);
            qu.pop();
            for (int &i : graph[t])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    qu.push(i);
                }
            }
            /* code */
        }
        if (resu.size() != numCourses)
            return {};

        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n[[1,0],[1,2],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */
