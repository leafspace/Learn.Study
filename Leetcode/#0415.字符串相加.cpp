/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int nCarry = 0;
        string retStr = "";

        int nLen = 0;
        while ((int)(num1.size() - nLen) > 0 || (int)(num2.size() - nLen) > 0)
        {
            char chA = '0', chB = '0';
            if ((int)(num1.size() - nLen) > 0)
            {
                chA = num1[num1.size() - 1 - nLen];
            }

            if ((int)(num2.size() - nLen) > 0)
            {
                chB = num2[num2.size() - 1 - nLen];
            }

            int nTempSum = chA - '0' + chB - '0';
            nTempSum += nCarry;

            retStr = (char)(nTempSum % 10 + '0') + retStr;
            nCarry = nTempSum / 10;

            nLen++;
        }

        if (nCarry > 0) retStr = (char)(nCarry + '0') + retStr;

        return retStr;
    }
};