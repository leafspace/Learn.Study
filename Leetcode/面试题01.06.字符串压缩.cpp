/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compress-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
【春招】
*/

class Solution {
public:
    string compressString(string S) {
        char* pRetString = new char[S.size() + 10];
        memset(pRetString, 0, sizeof(char) * (S.size() + 10));

        int nRetStringIndex = 0;
        int nCount = 0, nNowChar = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            // 老的字符 i != 0
            if (S[i] == nNowChar)
            {
                nCount++;
            }
            else
            {
                // 新的一轮字符 i != 0
                if (nCount > 0)
                {
                    // 记录原先的数据
                    sprintf(pRetString, "%s%d", pRetString, nCount);
                    nRetStringIndex = strlen(pRetString);

                    if (nRetStringIndex >= S.size())
                    {
                        delete[] pRetString;
                        return S;
                    }
                }

                // 遇到了新的字符 i 可能为0

                if ((nRetStringIndex + 1) >= S.size())
                {
                    delete[] pRetString;
                    return S;
                }

                nNowChar = S[i];
                pRetString[nRetStringIndex++] = S[i];
                nCount = 1;
            }
        }

        if (nCount > 0)
        {
            // 记录原先的数据
            sprintf(pRetString, "%s%d", pRetString, nCount);
            nRetStringIndex = strlen(pRetString);

            if (nRetStringIndex >= S.size())
            {
                delete[] pRetString;
                return S;
            }
        }

        string strRet(pRetString);
        delete[] pRetString;

        return strRet;
    }
};