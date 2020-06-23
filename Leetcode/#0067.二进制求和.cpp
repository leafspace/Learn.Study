/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string addBinary(string a, string b) {
        bool bCarry = false;
        string retStr = "";

        int nLen = 0;
        while ((int)(a.size() - nLen) > 0 || (int)(b.size() - nLen) > 0)
        {
            char chA = '0', chB = '0';
            if ((int)(a.size() - nLen) > 0)
            {
                chA = a[a.size() - 1 - nLen];
            }

            if ((int)(b.size() - nLen) > 0)
            {
                chB = b[b.size() - 1 - nLen];
            }

            int nCount = 0;
            if (chA == '1') nCount++;
            if (chB == '1') nCount++;
            if (bCarry) nCount++;

            char chIndex = '0';
            switch (nCount)
            {
            case 0:
            {
                chIndex = '0';
                bCarry = false;
            }
            break;
            case 1:
            {
                chIndex = '1';
                bCarry = false;
            }
            break;
            case 2:
            {
                chIndex = '0';
                bCarry = true;
            }
            break;
            case 3:
            {
                chIndex = '1';
                bCarry = true;
            }
            break;
            }

            retStr = chIndex + retStr;
            nLen++;
        }

        if (bCarry) retStr = '1' + retStr;
        return retStr;
    }
};
