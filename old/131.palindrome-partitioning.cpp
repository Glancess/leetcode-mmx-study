/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30212
 *
 * [131] 分割回文串
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
    vector<vector<string>> resu;
    vector<string> path;
    bool ishuiwen(string &s)
    {
        if (s.size() == 1)
        {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(string &s, int start)
    {
        if (start == s.size())
        {
            resu.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            string t = s.substr(start, i - start + 1);
            if (ishuiwen(t))
            {
                path.push_back(t);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */
