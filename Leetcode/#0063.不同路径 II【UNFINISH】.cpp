/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
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
    int nSumCount;
public:
    void goStep(Point& pointBegin, Point& pointEnd, vector<vector<int>>& obstacleGrid, vector<vector<int>> runState)
    {
        Point pointUp(pointBegin.x - 1, pointBegin.y);
        if (pointEnd == pointUp && obstacleGrid[pointUp.x][pointUp.y] == 0)
        {
            nSumCount++;
        }
        else if (pointUp.x >= 0 && runState[pointUp.x][pointUp.y] == 0 && obstacleGrid[pointUp.x][pointUp.y] == 0)
        {
            runState[pointUp.x][pointUp.y] = 1;

            goStep(pointUp, pointEnd, obstacleGrid, runState);

            runState[pointUp.x][pointUp.y] = 0;
        }

        Point pointDown(pointBegin.x + 1, pointBegin.y);
        if (pointEnd == pointDown && obstacleGrid[pointDown.x][pointDown.y] == 0)
        {
            nSumCount++;
        }
        else if (pointDown.x < obstacleGrid.size() && runState[pointDown.x][pointDown.y] == 0 && obstacleGrid[pointDown.x][pointDown.y] == 0)
        {
            runState[pointDown.x][pointDown.y] = 1;

            goStep(pointDown, pointEnd, obstacleGrid, runState);

            runState[pointDown.x][pointDown.y] = 0;
        }

        Point pointLeft(pointBegin.x, pointBegin.y - 1);
        if (pointEnd == pointLeft && obstacleGrid[pointLeft.x][pointLeft.y] == 0)
        {
            nSumCount++;
        }
        else if (pointLeft.y >= 0 && runState[pointLeft.x][pointLeft.y] == 0 && obstacleGrid[pointLeft.x][pointLeft.y] == 0)
        {
            runState[pointLeft.x][pointLeft.y] = 1;

            goStep(pointLeft, pointEnd, obstacleGrid, runState);

            runState[pointLeft.x][pointLeft.y] = 0;
        }

        Point pointRight(pointBegin.x, pointBegin.y + 1);
        if (pointEnd == pointRight && obstacleGrid[pointRight.x][pointRight.y] == 0)
        {
            nSumCount++;
        }
        else if (pointRight.y < obstacleGrid[0].size() && runState[pointRight.x][pointRight.y] == 0 && obstacleGrid[pointRight.x][pointRight.y] == 0)
        {
            runState[pointRight.x][pointRight.y] = 1;

            goStep(pointRight, pointEnd, obstacleGrid, runState);

            runState[pointRight.x][pointRight.y] = 0;
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
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

        Point pointBegin(0, 0);
        Point pointEnd(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);

        if (pointBegin == pointEnd && obstacleGrid[pointBegin.x][pointBegin.y] == 0)
        {
            return 1;
        }

        if (obstacleGrid[pointBegin.x][pointBegin.y] == 1 || obstacleGrid[pointEnd.x][pointEnd.y] == 1)
        {
            return 0;
        }

        goStep(pointBegin, pointEnd, obstacleGrid, stepRunState);

        return this->nSumCount;
    }
};