/*
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：



输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

首先检查特殊情况，不可能腐烂的橘子跟没有新鲜橘子的情况

当为1的格子上下左右都为空时返回-1，或者当中没有腐烂的橘子也返回-1，当新鲜橘子数量为0时返回0

注：
当有孤岛新鲜橘子的情况也能返回-1

每次遍历改变橘子的状态，遍历可以顺序便利，也可以按照扩张方向一眼看出当前橘子在第几波腐烂

循环当当前感染的数量为0时不会再蔓延，每次遍历的时候需要注意不能把当前次被感染的橘子算为感染源

                    ((i - 1) > 0 && grid[(i - 1)][j] == 0)
                    ((i + 1) < nHeight && grid[(i + 1)][j] == 0)
                    ((j - 1) > 0 && grid[i][(j - 1)] == 0)
                    ((j + 1) < nWidth && grid[i][(j + 1)] == 0)
【春招】
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nFreshNum = 0;
        int nRotNum = 0;

        int nHeight = grid.size();
        int nWidth = grid[0].size();

        for (int i = 0; i < nHeight; ++i)
        {
            for (int j = 0; j < nWidth; ++j)
            {
                if (grid[i][j] == 1)
                {
                    nFreshNum++;
                }
                else if (grid[i][j] == 2)
                {
                    grid[i][j] = -1;
                    nRotNum++;
                }
            }
        }

        std::cout << nFreshNum << " " << nRotNum << std::endl;

        if (nFreshNum == 0)
        {
            return 0;
        }

        if (nRotNum == 0)
        {
            return -1;
        }

        int nRetTimes = 0;
        int nInfectionNum = 0;
        do
        {
            nInfectionNum = 0;
            for (int i = 0; i < nHeight; ++i)
            {
                for (int j = 0; j < nWidth; ++j)
                {
                    // 检查当前轮的感染源
                    if (grid[i][j] == (-nRetTimes - 1))
                    {
                        if ((i - 1) >= 0 && grid[(i - 1)][j] == 1)       { nInfectionNum++; grid[(i - 1)][j] = (-nRetTimes - 2); }
                        if ((i + 1) < nHeight && grid[(i + 1)][j] == 1) { nInfectionNum++; grid[(i + 1)][j] = (-nRetTimes - 2); }
                        if ((j - 1) >= 0 && grid[i][(j - 1)] == 1)       { nInfectionNum++; grid[i][(j - 1)] = (-nRetTimes - 2); }
                        if ((j + 1) < nWidth && grid[i][(j + 1)] == 1)  { nInfectionNum++; grid[i][(j + 1)] = (-nRetTimes - 2); }
                    }
                }
            }

            // 当前一轮感染了橘子了
            if (nInfectionNum > 0)
            {
                nRetTimes++;
                nRotNum = nRotNum + nInfectionNum;
                nFreshNum = nFreshNum - nInfectionNum;

                if (nFreshNum == 0)
                {
                    break;
                }
            }
            std::cout << nFreshNum << " " << nRotNum << std::endl;
        } while(nInfectionNum != 0);

        if (nFreshNum > 0)
        {
            return -1;
        }

        return nRetTimes;
    }
};