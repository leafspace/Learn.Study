/*

给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释: 
长度最长的公共子数组是 [3, 2, 1]。
说明:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
通过次数14,765提交次数28,854
*/

class Solution {
public:
    int findMaxLength(vector<int>& A, vector<int>& B, int nBeginA, vector<int>& lstBDic)
    {
        int nMax = 0;
        for (int i = 0; i < lstBDic.size(); ++i)
        {
            int nAIndex = nBeginA;
            int nBIndex = lstBDic[i];

            while (nAIndex < A.size() && nBIndex < B.size() && A[nAIndex] == B[nBIndex])
            {
                nAIndex++;
                nBIndex++;
            }

            int nLen = nAIndex - nBeginA;
            nMax = nMax > nLen ? nMax : nLen;
        }

        return nMax;
    }

    int findLength(vector<int>& A, vector<int>& B) {
        int nRetMaxLen = 0;
        vector<vector<int>> nNumDiction(100);

        for (int i = 0; i < B.size(); ++i)
        {
            nNumDiction[B[i]].push_back(i);
        }

        for (int i = 0; i < A.size(); ++i)
        {
            int nLen = findMaxLength(A, B, i, nNumDiction[A[i]]);
            nRetMaxLen = nRetMaxLen > nLen ? nRetMaxLen : nLen;

            if (nRetMaxLen == A.size() || nRetMaxLen == B.size())
            {
                break;
            }
        }

        return nRetMaxLen;
    }
};