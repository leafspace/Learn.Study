/*
在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。

现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。

投影就像影子，将三维形体映射到一个二维平面上。

在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。

返回所有三个投影的总面积。

 

示例 1：

输入：[[2]]
输出：5
示例 2：

输入：[[1,2],[3,4]]
输出：17
解释：
这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。

示例 3：

输入：[[1,0],[0,2]]
输出：8
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：14
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：21

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/projection-area-of-3d-shapes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int nRetResult = 0;
        int nXWidth = grid.size();
        int nYHeight = grid[0].size();

        int nZMax = 0;
        int *pXMaxList = new int[nXWidth];
        int *pYMaxList = new int[nYHeight];

        memset(pXMaxList, 0, sizeof(int) * nXWidth);
        memset(pYMaxList, 0, sizeof(int) * nYHeight);

        for (int i = 0; i < nXWidth; ++i)
        {
            for (int j = 0; j < nYHeight; ++j)
            {
                if (grid[i][j] > 0)
                {
                    nZMax++;

                    if (grid[i][j] > pYMaxList[j])
                    {
                        pYMaxList[j] = grid[i][j];
                    }

                    if (grid[i][j] > pXMaxList[i])
                    {
                        pXMaxList[i] = grid[i][j];
                    }
                }
            }
        }

        nRetResult += nZMax;
        for (int i = 0; i < nXWidth; ++i)
        {
            nRetResult += pXMaxList[i];
        }

        for (int i = 0; i < nYHeight; ++i)
        {
            nRetResult += pYMaxList[i];
        }


        delete[] pXMaxList;
        delete[] pYMaxList;

        return nRetResult;
    }
};