/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
 

提示：

在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    void swapString(string &s, int nBeginIndex, int nEndIndex)
    {
        while (nBeginIndex < nEndIndex)
        {
            char tempC = s[nBeginIndex];
            s[nBeginIndex] = s[nEndIndex];
            s[nEndIndex] = tempC;

            nBeginIndex++;
            nEndIndex--;
        }
    }
public:
    string reverseWords(string s) {
        if (s == "") return s;
        int nBeginIndex = 0, nEndIndex = -1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i - 1] == ' ')
            {
                if (s[i] == ' ')
                {
                    nBeginIndex = i + 1;
                    nEndIndex = -1;
                }
                else
                {
                    nBeginIndex = i;
                    nEndIndex = -1;
                }
            }
            else
            {
                if (s[i] == ' ')
                {
                    nEndIndex = i - 1;
                    swapString(s, nBeginIndex, nEndIndex);

                    nBeginIndex = i + 1;
                    nEndIndex = i + 1;
                }
                else
                {
                    
                }
            }
        }

        if (s[s.size() - 1] != ' ') { nEndIndex = s.size() - 1; swapString(s, nBeginIndex, nEndIndex); }

        return s;
    }
};