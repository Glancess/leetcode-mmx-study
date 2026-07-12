/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30219
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> resu;
        sort(intervals.begin(), intervals.end(), [](auto &i, auto &j)
             {
            if(i[0]!=j[0]){
                
                return i[0]<j[0];
            }else{

                return i[1]<j[1];
            } });
        auto same = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= same[1])
            {
                same[1] = same[1] > intervals[i][1] ? same[1] : intervals[i][1];
            }
            else
            {
                resu.push_back(same);
                same = intervals[i];
            }
        }
        resu.push_back(same);
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,7],[1,4]]\n
// @lcpr case=end

 */
