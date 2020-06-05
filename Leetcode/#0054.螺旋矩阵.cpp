/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    enum MoveDire
    {
        Move_Right = 0,
        Move_Bottom = 1,
        Move_Left = 2,
        Move_Top = 3,

        Move_Size,
    };
private:
    int nWidth;
    int nHeight;
public:
    void MoveNext(int& i, int& j, MoveDire& nowMoveDire, int& nRoundTimes, vector<vector<int>>& matrix)
    {
        switch (nowMoveDire)
        {
        case Move_Right:
        {
            if ((j + 1 + nRoundTimes) >= nWidth)
            {
                nowMoveDire = Move_Bottom;
                MoveNext(i, j, nowMoveDire, nRoundTimes, matrix);
            }
            else
            {
                j++;
            }
        }
        break;
        case Move_Bottom:
        {
            if ((i + 1 + nRoundTimes) >= nHeight)
            {
                nowMoveDire = Move_Left;
                MoveNext(i, j, nowMoveDire, nRoundTimes, matrix);
            }
            else
            {
                i++;
            }
        }
        break;
        case Move_Left:
        {
            if ((j - 1 - nRoundTimes) < 0)
            {
                nowMoveDire = Move_Top;
                MoveNext(i, j, nowMoveDire, nRoundTimes, matrix);
                nRoundTimes++;
            }
            else
            {
                j--;
            }
        }
        break;
        case Move_Top:
        {
            if ((i - 1 - nRoundTimes) < 0)
            {
                nowMoveDire = Move_Right;
                MoveNext(i, j, nowMoveDire, nRoundTimes, matrix);
            }
            else
            {
                i--;
            }
        }
        break;

        default:
            return;
        };
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> retList;
        int nRoundTimes = 0;
        nHeight = matrix.size();
        nWidth = nHeight == 0 ? 0 : matrix[0].size();

        int i = 0, j = 0;
        MoveDire nowMoveDire = Move_Right;

        while (retList.size() < (nHeight * nWidth))
        {
            retList.push_back(matrix[i][j]);
            cout << matrix[i][j] << " ";
            if (retList.size() == (nHeight * nWidth))
            {
                break;
            }
            MoveNext(i, j, nowMoveDire, nRoundTimes, matrix);
        }

        return retList;
    }
};