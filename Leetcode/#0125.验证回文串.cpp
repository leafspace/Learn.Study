/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isDigital(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }

    bool isLowerCharater(char ch)
    {
        return (ch >= 'a' && ch <= 'z');
    }

    bool isUpperCharater(char ch)
    {
        return (ch >= 'A' && ch <= 'Z');
    }

    bool isDigitalOrCharater(char ch)
    {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    bool isPalindrome(string s) {
        int nBeginIndex = 0, nEndIndex = s.size() - 1;

        while ((nBeginIndex < nEndIndex) && (nBeginIndex < s.size()) && (nEndIndex >= 0))
        {
            if (!isDigitalOrCharater(s[nBeginIndex]))
            {
                while (nBeginIndex < s.size() && !isDigitalOrCharater(s[nBeginIndex])) { nBeginIndex++; }
                continue;
            }

            if (!isDigitalOrCharater(s[nEndIndex]))
            {
                while (nEndIndex >= 0 && !isDigitalOrCharater(s[nEndIndex])) { nEndIndex--; }
                continue;
            }

            {
                char chA = s[nBeginIndex];
                char chB = s[nEndIndex];
                if (!isDigital(chA)) 
                {
                    if (isUpperCharater(chA))
                    {
                        chA = chA + 32;
                    }

                    if (isUpperCharater(chB))
                    {
                        chB = chB + 32;
                    }
                }

                if (chA != chB)
                {
                    return false;
                }
            }

            nBeginIndex++;
            nEndIndex--;
        }

        return true;
    }
};