/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30219
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
        sort(intervals.begin(), intervals.end(), [](auto &i, auto &j)
             {
            if(i[0]!=j[0]){
                
                return i[0]<j[0];
            }else{

                return i[1]<j[1];
            } });
        int count = 0;
        vector<int> same = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < same[1])
            {
                count++;
                same = intervals[i][1] < same[1] ? intervals[i] : same;
            }
            else
            {
                same = intervals[i];
            }
        }
        return count;
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
