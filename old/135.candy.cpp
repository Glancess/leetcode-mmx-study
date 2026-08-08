/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30219
 *
 * [135] 分发糖果
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
    int candy(vector<int> &ratings)
    {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for (int j = ratings.size() - 2; j > -1; j--)
        {
            if (ratings[j] > ratings[j + 1])
            {
                candy[j] = max(candy[j], candy[j + 1] + 1);
            }
        }
        int sum = 0;
        for (int &i : candy)
        {
            sum += i;
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */
