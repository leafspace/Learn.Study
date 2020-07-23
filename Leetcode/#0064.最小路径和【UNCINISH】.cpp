/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
typedef struct Point
{
    int x;
    int y;

    Point(int nX, int nY) : x(nX), y(nY) {}
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
    int nMinSize;
    int nSumCount;
public:
    void goStep(Point& pointBegin, Point& pointEnd, vector<vector<int>>& obstacleGrid, vector<vector<int>> runState, int nRunSum = 0)
    {
        Point pointDown(pointBegin.x + 1, pointBegin.y);
        if (pointEnd == pointDown)
        {
            nRunSum = nRunSum + obstacleGrid[pointDown.x][pointDown.y];
            if (nRunSum < nMinSize)
            {
                nMinSize = nRunSum;
            }
            nSumCount++;
        }
        else if (pointDown.x < obstacleGrid.size() && runState[pointDown.x][pointDown.y] == 0)
        {
            runState[pointDown.x][pointDown.y] = 1;

            goStep(pointDown, pointEnd, obstacleGrid, runState, nRunSum + obstacleGrid[pointDown.x][pointDown.y]);

            runState[pointDown.x][pointDown.y] = 0;
        }

        Point pointRight(pointBegin.x, pointBegin.y + 1);
        if (pointEnd == pointRight)
        {
            nRunSum = nRunSum + obstacleGrid[pointRight.x][pointRight.y];
            if (nRunSum < nMinSize)
            {
                nMinSize = nRunSum;
            }
            nSumCount++;
        }
        else if (pointRight.y < obstacleGrid[0].size() && runState[pointRight.x][pointRight.y] == 0)
        {
            runState[pointRight.x][pointRight.y] = 1;

            goStep(pointRight, pointEnd, obstacleGrid, runState, nRunSum + obstacleGrid[pointRight.x][pointRight.y]);

            runState[pointRight.x][pointRight.y] = 0;
        }
    }

    int minPathSum(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> stepRunState(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        for (int i = 0; i < obstacleGrid.size(); ++i)
        {
            for (int j = 0; j < obstacleGrid[0].size(); ++j)
            {
                stepRunState[i][j] = 0;
            }
        }

        stepRunState[0][0] = 1;
        this->nSumCount = 0;
        this->nMinSize = INT_MAX;

        Point pointBegin(0, 0);
        Point pointEnd(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);

        if (pointBegin == pointEnd)
        {
            return obstacleGrid[pointBegin.x][pointBegin.y];
        }

        goStep(pointBegin, pointEnd, obstacleGrid, stepRunState, obstacleGrid[pointBegin.x][pointBegin.y]);

        return this->nMinSize;
    }
};