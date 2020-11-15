/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    int getModeCount(int n) {
        int nRetCount = 0;
        while (n) {
            if (n % 2 == 1) nRetCount++;
            n = n / 2;
        }
        return nRetCount;
    }

    string getModeString(string num, int n) {
        string strRet = "";
        int i = 0;
        while (n) {
            if (n % 2 == 1) {
                strRet = num[num.size() - 1 - i] + strRet;
            }

            n = n / 2;
            i++;
        }

        /*i = 0;
        while (i < strRet.size() && strRet[i] == '0') { i++; }

        if (i < strRet.size()) {
            strRet = strRet.substr(i, strRet.size());
        }*/

        int nNum = stoi(strRet);
        strRet = to_string(nNum);

        return strRet;
    }
    
    int compareString(string str1, string str2) {
        if (stoi(str1) > stoi(str2)) return 1;
        else if (stoi(str1) < stoi(str2)) return -1;
        
        return 0;
    }
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        int nNumModeCount = num.size() - k;
        string strRet = "";
        for (int i = 0; i < pow(2, num.size()); ++i) {
            if (nNumModeCount == getModeCount(i)) {
                string strMode = getModeString(num, i);
                if (strRet == "") strRet = strMode;
                else if (compareString(strMode, strRet) < 0) {
                    strRet = strMode;
                }
            }
        }

        return strRet;
    }
};