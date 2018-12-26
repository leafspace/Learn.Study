/*
给定一个整数，将其转化为7进制，并以字符串形式输出。

示例 1:

输入: 100
输出: "202"
示例 2:

输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。
*/

class Solution {
public:
    stack<char> num2Stack(int num) {
        stack<char> retStack;
        
        // 整数为0的情况
        if (num == 0) {
            retStack.push('0');
        }
        
        while(num) {
            retStack.push(num % 7 + '0');
            num = num /7;
        }
        
        return retStack;
    }
    
    string stack2String(bool bIsPositive, stack<char> numStack) {
        int nIndex = 0;
        int charSize = bIsPositive ? numStack.size() : numStack.size() + 1;
        char *charaterStr = new char[charSize];
        
        if (bIsPositive == false) {
            charaterStr[nIndex++] = '-';
        }
        
        while(!numStack.empty()) {
            charaterStr[nIndex++] = numStack.top();
            numStack.pop();
        }
        charaterStr[nIndex++] = 0;
        
        string retStr(charaterStr);
        
        delete charaterStr;
        
        return retStr;
    }
    
    string convertToBase7(int num) {
        bool bIsPositive = true;
        if (num < 0) {
            bIsPositive = false;
            num = num * -1;
        }
        
        return this->stack2String(bIsPositive, this->num2Stack(num));
    }
};