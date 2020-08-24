/*
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long nNumNumber = (long long)(n - m) + 1;
        int nIndex = 0;
        int nRetNum = 0;

        while (n)
        {
            int nJudgementNum = pow(2, nIndex) + 1;
            int nIndexNum = 1;
            if (nNumNumber > nJudgementNum) nIndexNum = 0;
            else if (n % 2 == 0 || m % 2 == 0) nIndexNum = 0;

            nRetNum = nRetNum + nIndexNum * pow(2, nIndex);

            nIndex++;
            m = m / 2;
            n = n / 2;
        }

        return nRetNum;
    }
};