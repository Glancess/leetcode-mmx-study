/*
 * @lc app=leetcode.cn id=127 lang=cpp
 * @lcpr version=30219
 *
 * [127] 单词接龙
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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.count(endWord) == 0)
        {
            return 0;
        }
        queue<string> qu;
        qu.push(beginWord);
        int step = 1;
        while (!qu.empty())
        {
            int size = qu.size();
            step++;
            while (size > 0)
            {
                size--;
                string t = qu.front();
                qu.pop();

                for (int i = 0; i < t.size(); i++)
                {
                    for (char k = 'a'; k <= 'z'; k++)
                    {

                        string tt = t;
                        if (k == tt[i])
                        {
                            continue;
                        }
                        tt[i] = k;
                        if (tt == endWord)
                        {
                            return step;
                        }
                        if (st.count(tt) != 0)
                        {
                            st.erase(tt);
                            qu.push(tt);
                                                }
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]\n
// @lcpr case=end

 */
