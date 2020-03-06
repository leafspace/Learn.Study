/*
给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?

示例 1:

输入: 5
输出: 2
解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
示例 2:

输入: 9
输出: 3
解释: 9 = 9 = 4 + 5 = 2 + 3 + 4
示例 3:

输入: 15
输出: 4
解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
说明: 1 <= N <= 10 ^ 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/consecutive-numbers-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int nMax = 0;
    long long getSigma(int nBegin, int nEnd)
    {
        static bool bIsCaculate = false;
        static long long* nSigma = new long long[(int)(nMax / 2)];

        if (nEnd >= nMax / 2)
        {
            return -1;
        }
        if (!bIsCaculate)
        {
            nSigma[0] = 1;
            for (int i = 1; i < (int)(nMax / 2); ++i)
            {
                nSigma[i] = nSigma[i - 1] + (i + 1);
            }
            bIsCaculate = true;
        }

        if (nBegin == 1)
        {
            return nSigma[nEnd - 1];
        }
        else if (nBegin > 1)
        {
            return nSigma[nEnd - 1] - nSigma[nBegin - 1] + nBegin;
        }

        return -1;
    }

    int consecutiveNumbersSum(int N) {
        nMax = N;
        int retCount = 0;
        for (int i = 1; i <= N / 2; ++i)
        {
            int nSigma = 0;
            int j = i + 1;
            do
            {
                nSigma = getSigma(i, j);
                if (nSigma == N)
                {
                    retCount++;
                    break;
                }
                j++;
            } while (nSigma < N);
        }
        return retCount + 1;
    }
};