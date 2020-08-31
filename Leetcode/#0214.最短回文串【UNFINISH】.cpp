/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:

输入: "aacecaaa"
输出: "aaacecaaa"
示例 2:

输入: "abcd"
输出: "dcbabcd"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        if (isPalindrome(s)) return s;
        string reversStr = "";
        for (int i = s.size() - 1; i >= 0; --i)
        {
            reversStr += s[i];
        }

        for (int i = 1; i < reversStr.size(); ++i)
        {
            string tempstr = reversStr.substr(0, i) + s;
            if (isPalindrome(tempstr)) return tempstr;
        }

        return reversStr + s;
    }
};