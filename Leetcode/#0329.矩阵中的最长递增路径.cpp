/*
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
*/

typedef struct Point
{
    int x;
    int y;
    Point(int nX, int nY)
    {
        x = nX;
        y = nY;
    }
}Point;

const bool operator== (const Point& pointA, const Point& pointB)
{
    if ((pointA.x == pointB.x) && (pointA.y == pointB.y))
    {
        return true;
    }

    return false;
}

const bool operator!= (const Point& pointA, const Point& pointB)
{
    return !(pointA == pointB);
}

class Solution {
private:
    int m_nMaxPath = 0;
    vector<vector<int>> m_lstMaxFlag;
public:
    int getIndexValue(const Point& pointBegin, const vector<vector<int>>& matrix)
    {
        return matrix[pointBegin.x][pointBegin.y];
    }

    int getMaxPath(Point pointBegin, vector<vector<int>>& matrix, int nRunedLen = 0)
    {
        bool bHasNextPoint = false;

        Point pointUp(max(pointBegin.x - 1, 0), pointBegin.y);
        Point pointDown(min(pointBegin.x + 1, (int)(matrix.size() - 1)), pointBegin.y);
        Point pointLeft(pointBegin.x, max(pointBegin.y - 1, 0));
        Point pointRight(pointBegin.x, min(pointBegin.y + 1, (int)(matrix[0].size() - 1)));

        int nMaxPointUp = 0;
        int nMaxPointDown = 0;
        int nMaxPointLeft = 0;
        int nMaxPointRight = 0;

        if (getIndexValue(pointUp, matrix) > getIndexValue(pointBegin, matrix))
        {
            if (m_lstMaxFlag[pointUp.x][pointUp.y] != -1)
            {
                nMaxPointUp = m_lstMaxFlag[pointUp.x][pointUp.y];
            }
            else
            {
                nMaxPointUp = getMaxPath(pointUp, matrix);
                m_lstMaxFlag[pointUp.x][pointUp.y] = nMaxPointUp;
            }
        }

        if (getIndexValue(pointDown, matrix) > getIndexValue(pointBegin, matrix))
        {
            if (m_lstMaxFlag[pointDown.x][pointDown.y] != -1)
            {
                nMaxPointDown = m_lstMaxFlag[pointDown.x][pointDown.y];
            }
            else
            {
                nMaxPointDown = getMaxPath(pointDown, matrix);
                m_lstMaxFlag[pointDown.x][pointDown.y] = nMaxPointDown;
            }
        }

        if (getIndexValue(pointLeft, matrix) > getIndexValue(pointBegin, matrix))
        {
            if (m_lstMaxFlag[pointLeft.x][pointLeft.y] != -1)
            {
                nMaxPointLeft = m_lstMaxFlag[pointLeft.x][pointLeft.y];
            }
            else
            {
                nMaxPointLeft = getMaxPath(pointLeft, matrix);
                m_lstMaxFlag[pointLeft.x][pointLeft.y] = nMaxPointLeft;
            }
        }

        if (getIndexValue(pointRight, matrix) > getIndexValue(pointBegin, matrix))
        {
            if (m_lstMaxFlag[pointRight.x][pointRight.y] != -1)
            {
                nMaxPointRight = m_lstMaxFlag[pointRight.x][pointRight.y];
            }
            else
            {
                nMaxPointRight = getMaxPath(pointRight, matrix);
                m_lstMaxFlag[pointRight.x][pointRight.y] = nMaxPointRight;
            }
        }

        int nRetMax = 0;
        if (nMaxPointUp > nRetMax) nRetMax = nMaxPointUp;
        if (nMaxPointDown > nRetMax) nRetMax = nMaxPointDown;
        if (nMaxPointLeft > nRetMax) nRetMax = nMaxPointLeft;
        if (nMaxPointRight > nRetMax) nRetMax = nMaxPointRight;

        nRetMax = nRetMax + 1;

        return nRetMax;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m_nMaxPath = 0;
        if (matrix.size() == 0)
        {
            return 0;
        }
        
        vector<vector<int>> tempList(matrix.size(), vector<int>(matrix[0].size(), -1));
        m_lstMaxFlag = tempList;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                Point point(i, j);

                if (m_lstMaxFlag[i][j] == -1)
                {
                    m_lstMaxFlag[i][j] = getMaxPath(point, matrix);
                }

                if (m_lstMaxFlag[i][j] > m_nMaxPath)
                {
                    m_nMaxPath = m_lstMaxFlag[i][j];
                }
            }
        }

        return m_nMaxPath;
    }
};