/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
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

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        string retStr = "";
        vector<string> middleStrList(num1.size(), "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

        for (int i = 0; i < num1.size(); ++i)
        {
            int nAddFlag = 0;
            int nAnum = num1[num1.size() - 1 - i] - '0';

            int j = 0;
            for (j = 0; j < num2.size(); ++j)
            {
                nAddFlag = nAnum * (num2[num2.size() - 1 - j] - '0') + nAddFlag;
                middleStrList[i][middleStrList[i].size() - 1 - j] = nAddFlag % 10 + '0';
                nAddFlag = nAddFlag / 10;
            }

            if (nAddFlag != 0) middleStrList[i][middleStrList[i].size() - 1 - j] = nAddFlag % 10 + '0';
            for (j = 0; j < i; ++j)
            {
                middleStrList[i] = middleStrList[i] + "0";
            }

            while (middleStrList[i].find("0") == 0) { middleStrList[i] = middleStrList[i].substr(1); };
        }

        for (int i = 0; i < num1.size(); ++i)
        {
            retStr = addStrings(retStr, middleStrList[i]);
        }

        
        return retStr;
    }
};