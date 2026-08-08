/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30219
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int count = 1;
        sort(points.begin(), points.end(), [](auto &i, auto &j)
             {
                if(i[0]!=j[0]){
                    
                    return i[0]<j[0];
                }else{
                    return i[1]<j[1];
                } });
        vector<int> same = points[0];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= same[1])
            {
                same[0] = points[i][0];
                same[1] = same[1] < points[i][1] ? same[1] : points[i][1];
            }
            else
            {
                same = points[i];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */
