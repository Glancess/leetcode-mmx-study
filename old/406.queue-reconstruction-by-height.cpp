/*
 * @lc app=leetcode.cn id=406 lang=cpp
 * @lcpr version=30219
 *
 * [406] 根据身高重建队列
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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](auto &i, auto &j)
             {
            if(i[0]!=j[0]){
                return i[0]>j[0];
            }else{

                return i[1]<j[1];

            } });
        vector<vector<int>> resu;
        for (auto &i : people)
        {

            resu.insert(resu.begin() + i[1], i);
        }
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]\n
// @lcpr case=end

 */
