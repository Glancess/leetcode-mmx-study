/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30218
 *
 * [435] 无重叠区间
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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int sum = 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             {
            if(a[0]!=b[0]){
                return a[0]<b[0];
            }else{
                return a[1]<b[1];
            } });
        auto same = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < same[1])
            {
                sum++;
                same = same[1] < intervals[i][1] ? same : intervals[i];
            }
            else
            {
                same = intervals[i];
            }
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [1,2], [1,2] ]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [2,3] ]\n
// @lcpr case=end

 */
