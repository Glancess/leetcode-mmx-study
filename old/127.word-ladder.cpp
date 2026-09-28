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
        unordered_set<string> se(wordList.begin(), wordList.end());
        if (se.count(endWord) == 0)
        {
            return 0;
        }
        queue<string> qu;
        int step = 1;
        qu.push(beginWord);
        while (!qu.empty())
        {

            int size = qu.size();
            while (size > 0)
            {
                size--;
                string t = qu.front();
                qu.pop();
                if (t == endWord)
                {
                    return step;
                }

                for (int i = 0; i < t.size(); i++)
                {
                    string tt = t;
                    for (char k = 'a'; k <= 'z'; k++)
                    {
                        if (tt[i] == k)
                        {
                            continue;
                        }
                        else
                        {
                            tt[i] = k;
                            if (se.find(tt) != se.end())
                            {
                                qu.push(tt);
                                se.erase(tt);
                            }
                        }
                    }
                }
            }
            step++;
                }
        return 0;
    }
}

;
// @lc code=end

/*
// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]\n
// @lcpr case=end

 */
