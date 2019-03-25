/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        
        int iMaxIndex = 0, iMaxSize = 1;
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j <= s.size() - i; ++j) {
                if (this->isPalindrome(s.substr(j, i))) {
                    if (i > iMaxSize) {
                        iMaxIndex = j;
                        iMaxSize = i;
                        break;
                    }
                }
            }
        }
        return s.substr(iMaxIndex, iMaxSize);
    }
    
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};