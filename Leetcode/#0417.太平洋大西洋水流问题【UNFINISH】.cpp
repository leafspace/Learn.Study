/*
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        short **sPacificFlag;
        short **sAtlanticFlag;

        auto auWidth = matrix[0].size();
        auto auHeight = matrix.size();

        sPacificFlag = new short*[auWidth];
        sAtlanticFlag = new short*[auWidth];

        for (int i = 0; i < auHeight; ++i)
        {
            sPacificFlag[i] = new short[auWidth];
            sAtlanticFlag[i] = new short[auWidth];

            memset(sPacificFlag[i], 0, sizeof(short) * auWidth);
            memset(sAtlanticFlag, 0, sizeof(short) * auWidth);
        }

        // 检测可流入太平洋的位置
        int x = 0, y = 0;
        bool xFlag = false, yFlag = true;

        do
        {


            if (x == 0 || y == 0)
            {
                sPacificFlag[x][y] = 1;

                if (xFlag) { x++; }
                if (yFlag) { y++; }

                xFlag = !xFlag;
                yFlag = !yFlag;
            }
            else
            {
                x = x + xFlag ? 1 : -1;
                y = y + yFlag ? 1 : -1;
            }

            if (x == (auHeight - 1) && y == (auWidth - 1))
            {
                break;
            }
        } while(true);


        for (int i = 0; i < auHeight; ++i)
        {
            delete[] sPacificFlag[i];
            delete[] sAtlanticFlag[i];
        }

        delete[] sPacificFlag;
        delete[] sAtlanticFlag;
    }
};