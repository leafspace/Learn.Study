/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
*/

class Solution {
public:
    string frequencySort(string s) {
        int iTextFlag[128] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            iTextFlag[charToIndex(s[i])]++;
        }
        
        for (int i = 0; i < 128; ++i) {
            char cStr = 0;
            cStr = indexToChar(i);
            cout << iTextFlag[i] << "(" << cStr << ")\t";
        }
        cout << endl;
        return getNewString(iTextFlag, s.size());
    }
    
    string getNewString(int* iTextFlag, int strMaxLen) {
        char *cNewStr = new char[strMaxLen];
        int iMaxIndex = -1;
        int strIndex = 0;
        while ((iMaxIndex = findMaxIndex(iTextFlag)) != -1) {
            char cStr = 0;
            cStr = indexToChar(iMaxIndex);
            for (int i = 0; i < iTextFlag[iMaxIndex]; ++i) {
                cNewStr[strIndex++] = cStr;
            }
            iTextFlag[iMaxIndex] = 0;
        }
        
        string str = cNewStr;
        return str;
    }
    
    int findMaxIndex(int* iTextFlag) {
        int iRetIndex = -1;
        
        int i = 0;
        while(i < 128 && iTextFlag[i++] == 0);
        if (i == 128) {
            return -1;
        } else {
            iRetIndex = i--;
        }
        
        for (i = 0; i < 128; ++i) {
            if (i == iRetIndex) {
                continue;
            }
            if (iTextFlag[i] > iTextFlag[iRetIndex]) {
                iRetIndex = i;
            }
        }
        
        return iRetIndex;
    }
    
    int charToIndex(char cStr) {
        return (int)cStr;
    }
    
    char indexToChar(int index) {
        return (char)index;
    }
};