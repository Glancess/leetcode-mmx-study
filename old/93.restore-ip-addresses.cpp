/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30212
 *
 * [93] 复原 IP 地址
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
    vector<string> resu;
    bool isIp(string &s)
    {
        if (s.size() > 1)
        {
            return s[0] != '0' && stoi(s) <= 255 && stoi(s) >= 10;
        }
        return true;
    }
    vector<string> path;
    void backtracking(string &s, int nums, int start)
    {
        if (nums == 4 && start == s.size())
        {
            string t = path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3];
            resu.push_back(t);
            return;
        }
        if (nums > 4)
        {
            return;
        }
        for (int i = 1; i < 4; i++)
        {
            if (start + i > s.size())
            {
                break;
            }
            string t = s.substr(start, i);

            if (isIp(t))
            {
                path.push_back(t);
                backtracking(s, nums + 1, start + i);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0, 0);
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */
