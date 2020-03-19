/*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
【春招】
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int i = 0;
        int retLength = 0;
        bool bIsSingle = false;
        int nCount[58] = { 0 };

        for (i = 0; i < s.size(); ++i)
        {
            nCount[s[i] - 'A']++;
        }

        for (i = 0; i < 58; ++i)
        {
            if (nCount[i] > 0)
            {
                retLength += (nCount[i] - 1);

                if (nCount[i] % 2 == 0)
                {
                    retLength++;
                }
                else if (!bIsSingle)
                {
                    bIsSingle = true;
                }
            }
        }

        if (bIsSingle)
        {
            retLength++;
        }

        return retLength;
    }
};