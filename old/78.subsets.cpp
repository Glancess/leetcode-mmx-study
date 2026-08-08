/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30219
 *
 * [78] 子集
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
    vector<vector<int>> resu;
    vector<int> temp;
    void bakctracking(vector<int> &nums, int start)
    {
        resu.push_back(temp);
        for (int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            bakctracking(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        bakctracking(nums, 0);
        return resu;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
