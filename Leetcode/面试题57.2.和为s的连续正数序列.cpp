/*

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
【春招】
*/

class Solution {
public:
    long long getSigma(int nBegin, int nEnd)
    {
        static bool bIsCaculate = false;
        static long long nSigma[100000];

        if (!bIsCaculate)
        {
            nSigma[0] = 1;
            for (int i = 1; i < 100000; ++i)
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

    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> retLst;
        for (int i = 1; i <= target / 2; ++i)
        {
            int nSigma = 0;
            int j = i + 1;
            do
            {
                nSigma = getSigma(i, j);
                if (nSigma == target)
                {
                    vector<int> tempLst;
                    for (int pCounter = i; pCounter <= j; ++pCounter)
                    {
                        tempLst.push_back(pCounter);
                    }
                    retLst.push_back(tempLst);
                    break;
                }
                j++;
            } while (nSigma < target);
        }

        return retLst;
    }
};