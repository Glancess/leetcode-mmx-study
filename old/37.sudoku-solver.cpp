/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30208
 *
 * [37] 解数独
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
    bool iscorrect(vector<vector<char>> &board, int i, int j, char val)
    {
        for (int k = 0; k < board.size(); k++)
        {
            if (board[k][j] == val || board[i][k] == val)
            {
                return false;
            }
        }
        int iidex = (i / 3) * 3;
        int jidex = (j / 3) * 3;
        for (int i1 = iidex; i1 < iidex + 3; i1++)
        {
            for (int j1 = jidex; j1 < jidex + 3; j1++)
            {
                if (board[i1][j1] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isfind(vector<vector<char>> &board, int j, int i)
    {
        if (j == board.size())
        {
            i++;
            j = 0;
        }
        if (i == board.size())
        {
            return true;
        }
        if (board[i][j] == '.')
        {

            for (int k = 1; k < 10; k++)
            {

                {
                    if (iscorrect(board, i, j, '0' + k))
                    {
                        board[i][j] = '0' + k;
                        if (isfind(board, j + 1, i))
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
            }
        }

        else
        {
            return isfind(board, j + 1, i);
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        isfind(board, 0, 0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
