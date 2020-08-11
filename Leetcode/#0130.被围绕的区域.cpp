/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef struct Point
{
    int x;
    int y;

    Point(int nX, int nY) : x(nX), y(nY) {};
}Point;

class Solution {
    vector<vector<Point>> pointGroup;
public:
    int SearchGroupIndex(vector<vector<char>>& board, int nIndex, int pointX, int pointY)
    {
        for (int i = 0; i < pointGroup[nIndex].size(); ++i)
        {
            if (pointGroup[nIndex][i].x == pointX && pointGroup[nIndex][i].y == pointY)
            {
                return i;
            }
        }
        return -1;
    }

    int SearchGroupIndex(vector<vector<char>>& board, int nIndex, Point& point)
    {
        return SearchGroupIndex(board, nIndex, point.x, point.y);
    }

    void DeepLoop(vector<vector<char>>& board, int nIndex, Point& point)
    {
        Point pointUp(max(0, point.x - 1), point.y);
        Point pointDown(min((int)board.size() - 1, point.x + 1), point.y);
        Point pointLeft(point.x, max(0, point.y - 1));
        Point pointRight(point.x, min((int)board[point.x].size() - 1, point.y + 1));

        if (board[pointUp.x][pointUp.y] == 'O')
        {
            if (SearchGroupIndex(board, nIndex, pointUp) < 0)
            {
                pointGroup[nIndex].push_back(pointUp);
                DeepLoop(board, nIndex, pointUp);
            }
        }

        if (board[pointDown.x][pointDown.y] == 'O')
        {
            if (SearchGroupIndex(board, nIndex, pointDown) < 0)
            {
                pointGroup[nIndex].push_back(pointDown);
                DeepLoop(board, nIndex, pointDown);
            }
        }

        if (board[pointLeft.x][pointLeft.y] == 'O')
        {
            if (SearchGroupIndex(board, nIndex, pointLeft) < 0)
            {
                pointGroup[nIndex].push_back(pointLeft);
                DeepLoop(board, nIndex, pointLeft);
            }
        }

        if (board[pointRight.x][pointRight.y] == 'O')
        {
            if (SearchGroupIndex(board, nIndex, pointRight) < 0)
            {
                pointGroup[nIndex].push_back(pointRight);
                DeepLoop(board, nIndex, pointRight);
            }
        }
    }

    void DivideGroup(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'O')
                {
                    Point point(i, j);
                    int nIndex = SearchGroupIndex(board, point);

                    if (nIndex < 0)
                    {
                        vector<Point> tempList;
                        tempList.push_back(point);
                        pointGroup.push_back(tempList);

                        DeepLoop(board, pointGroup.size() - 1, point);
                    }

                }
            }
        }
    }

    int SearchGroupIndex(vector<vector<char>>& board, int pointX, int pointY)
    {
        for (int i = 0; i < pointGroup.size(); ++i)
        {
            for (int j = 0; j < pointGroup[i].size(); ++j)
            {
                if (pointGroup[i][j].x == pointX && pointGroup[i][j].y == pointY)
                {
                    return i;
                }
            }
        }

        return -1;
    }

    int SearchGroupIndex(vector<vector<char>>& board, Point& point)
    {
        return SearchGroupIndex(board, point.x, point.y);
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        DivideGroup(board);

        vector<bool> bGroupX(pointGroup.size(), true);
        for (int i = 0; i < board[0].size(); ++i)
        {
            if (board[0][i] == 'O')
            {
                int nIndex = SearchGroupIndex(board, 0, i);
                if (nIndex >= 0)
                    bGroupX[nIndex] = false;
            }

            if (board[board.size() - 1][i] == 'O')
            {
                int nIndex = SearchGroupIndex(board, board.size() - 1, i);
                if (nIndex >= 0)
                    bGroupX[nIndex] = false;
            }
        }

        for (int i = 1; i < board.size() - 1; ++i)
        {
            if (board[i][0] == 'O')
            {
                int nIndex = SearchGroupIndex(board, i, 0);
                if (nIndex >= 0)
                    bGroupX[nIndex] = false;
            }

            if (board[i][board[0].size() - 1] == 'O')
            {
                int nIndex = SearchGroupIndex(board, i, board[0].size() - 1);
                if (nIndex >= 0)
                    bGroupX[nIndex] = false;
            }
        }

        for (int i = 0; i < bGroupX.size(); ++i)
        {
            if (bGroupX[i])
            {
                for (int j = 0; j < pointGroup[i].size(); ++j)
                {
                    board[pointGroup[i][j].x][pointGroup[i][j].y] = 'X';
                }
            }
        }
    }
};
