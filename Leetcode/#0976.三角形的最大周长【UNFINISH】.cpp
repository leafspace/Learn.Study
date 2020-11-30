/*
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。

 

示例 1：

输入：[2,1,2]
输出：5
示例 2：

输入：[1,2,1]
输出：0
示例 3：

输入：[3,2,3,4]
输出：10
示例 4：

输入：[3,6,2,3]
输出：8
 

提示：

3 <= A.length <= 10000
1 <= A[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-perimeter-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    bool getIsPerimeter(int a, int b, int c)
    {
        if (((a + b) > c) && ((b + c) > a) && ((a + c) > b) &&
            (abs(a - b) < c) && (abs(b - c) < a) && (abs(a - c) < b))
        {
            return true;
        }
        return false;
    }
    vector<short> getDigitByte1(int n)
    {
        int i = 0;
        vector<short> retLst;
        while (n)
        {
            if (n % 2 == 1) retLst.push_back(i);

            i++;
            n = n / 2;
        }
        return retLst;
    }
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) return 0;

        sort(A.begin(), A.end());

        int nRetMax = 0;
        for (int i = 7; i < pow(2, A.size()); ++i)
        {
            vector<short> tempList = getDigitByte1(i);
            if (tempList.size() != 3 || !getIsPerimeter(A[A.size() - 1 - tempList[0]], A[A.size() - 1 - tempList[1]], A[A.size() - 1 - tempList[2]])) continue;

            int nTempPrem = A[A.size() - 1 - tempList[0]] + A[A.size() - 1 - tempList[1]] + A[A.size() - 1 - tempList[2]];
            if (nTempPrem > nRetMax) {
                nRetMax = nTempPrem;
                break;
            }
        }

        return nRetMax;
    }
};