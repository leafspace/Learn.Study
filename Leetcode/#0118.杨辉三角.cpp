/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) { vector<vector<int>> retLst; return retLst; }
        if (numRows == 1) { vector<vector<int>> retLst = { { 1 } }; return retLst; }
        if (numRows == 2) { vector<vector<int>> retLst = { { 1 }, { 1, 1 } }; return retLst; }

        vector<vector<int>> retLst = { { 1 }, { 1, 1 } }; 
        for (int i = 3; i <= numRows; ++i)
        {
            vector<int> tempLst;
            for (int j = 0; j < i; ++j)
            {
                if (j == 0 || j == (i - 1)) {
                    tempLst.push_back(1);
                }
                else
                {
                    tempLst.push_back(retLst[i - 2][j - 1] + retLst[i - 2][j]);
                }
            }
            retLst.push_back(tempLst);
        }
        
        
        return retLst;
    }
};