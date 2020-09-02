/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

 

通过次数19,229提交次数91,688

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isNumber(string s) {
        string sB = "";
        for (int i = 0, nI = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                sB += s[i];
            }
        }

        s = sB;

        if (s.size() == 0) return false;

        bool bPointNum = false, bENum = false;
        int nNowNumBeginIndex = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            {
                if (i == 0) nNowNumBeginIndex = 0;
                if (s[max(i - 1, 0)] == 'e' || s[max(i - 1, 0)] == 'E')
                {
                    nNowNumBeginIndex = max(i - 1, 0);
                }
            }
            break;
            case '+': case '-':
            {
                if (bENum && s[i] == '+') return false;
                if (nNowNumBeginIndex == -1) nNowNumBeginIndex = i;
                else return false;
            }
            break;
            case 'e': case 'E':
            {
                if (nNowNumBeginIndex == -1 || bENum) return false;
                if (s[max(i - 1, 0)] == '.')
                {
                    return false;
                }

                nNowNumBeginIndex = -1;
                bENum = true;
                bPointNum = false;
            }
            break;
            case '.':
            {
                if (nNowNumBeginIndex == -1) return false;
                if (bPointNum) return false;
                else bPointNum = true;
            }
            break;
            default:
            {
                return false;
            }
            }
        }

        if (bENum && nNowNumBeginIndex == -1)
        {
            return false;
        }

        return true;
    }
};