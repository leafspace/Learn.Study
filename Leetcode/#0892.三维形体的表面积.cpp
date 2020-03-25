/*
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。

 

示例 1：

输入：[[2]]
输出：10
示例 2：

输入：[[1,2],[3,4]]
输出：34
示例 3：

输入：[[1,0],[0,2]]
输出：16
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surface-area-of-3d-shapes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
【春招】
*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int nRetResult = 0;
        int nXWidth = grid.size();
        int nYHeight = grid[0].size();

        int nTempFace = 0;
        for (int i = 0; i < nXWidth; ++i)
        {
            for (int j = 0; j < nYHeight; ++j)
            {
                if (grid[i][j] <= 0)
                {
                    continue;
                }

                nTempFace = 6 * grid[i][j] - 2 * (grid[i][j] - 1);

                if (i > 0)
                {
                    if (grid[i - 1][j] > 0)
                    {
                        if (grid[i - 1][j] > grid[i][j])
                        {
                            nTempFace = nTempFace - grid[i][j];
                        }
                        else
                        {
                            nTempFace = nTempFace - grid[i - 1][j];
                        }
                    }
                }

                if (i < nXWidth - 1)
                {
                    if (grid[i + 1][j] > 0)
                    {
                        if (grid[i + 1][j] > grid[i][j])
                        {
                            nTempFace = nTempFace - grid[i][j];
                        }
                        else
                        {
                            nTempFace = nTempFace - grid[i + 1][j];
                        }
                    }
                }

                if (j > 0)
                {
                    if (grid[i][j - 1] > 0)
                    {
                        if (grid[i][j - 1] > grid[i][j])
                        {
                            nTempFace = nTempFace - grid[i][j];
                        }
                        else
                        {
                            nTempFace = nTempFace - grid[i][j - 1];
                        }
                    }
                }

                if (j < nYHeight - 1)
                {
                    if (grid[i][j + 1] > 0)
                    {
                        if (grid[i][j + 1] > grid[i][j])
                        {
                            nTempFace = nTempFace - grid[i][j];
                        }
                        else
                        {
                            nTempFace = nTempFace - grid[i][j + 1];
                        }
                    }
                }

                nRetResult = nRetResult + nTempFace;
            }
        }
        return nRetResult;
    }
};