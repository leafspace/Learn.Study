/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int iRetStrIndex = 0;
        char cRetStr[256] = { 0 };
        double cRetNum = numerator * 1.0 / denominator;
        
        // 整数部分
        if (cRetNum >= 0) {
            int tempNum = (int) cRetNum;
            vector<int> tempList;
            do {
                tempList.push_back(tempNum % 10);
                tempNum = tempNum / 10;
            } while(tempNum);
            
            for (int i = tempList.size() - 1; i >= 0; --i) {
                cRetStr[iRetStrIndex++] = tempList[i] + '0';
            }
        }
        
        // 如果商是整数
        cRetNum = cRetNum - (int)cRetNum;
        if (cRetNum == 0) {
            cRetStr[iRetStrIndex] = 0;
            return cRetStr;
        }
        
        // 小数部分
        cRetStr[iRetStrIndex++] = '.';
        int iTiemNum = -1;
        do {
            cRetNum = cRetNum * 10;
            if (iTiemNum == (int)cRetNum) {
                char cLastChar = cRetStr[iRetStrIndex - 1];
                cRetStr[iRetStrIndex - 1] = '(';
                cRetStr[iRetStrIndex] = cLastChar;
                cRetStr[iRetStrIndex + 1] = ')';
                iRetStrIndex += 2;
                break;
            } else {
                iTiemNum = (int)cRetNum;
            }
            cRetStr[iRetStrIndex++] = iTiemNum + '0';
            cRetNum = cRetNum - iTiemNum;
        } while(cRetNum);
        
        
        cRetStr[iRetStrIndex] = 0;
        return cRetStr;
    }
};