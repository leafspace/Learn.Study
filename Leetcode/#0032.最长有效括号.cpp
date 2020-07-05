/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
通过次数79,615提交次数245,092

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int nRetLen = 0;
        stack<int> pairCounter;   // '(' 字符左括号的位置
        vector<int> unPairCounter; // 未能匹配的'('、')'的位置

        // 找到所有落单的字符
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                pairCounter.push(i);
            }
            else if (s[i] == ')')
            {
                if (pairCounter.empty())
                {
                    unPairCounter.push_back(i);
                }
                else
                {
                    pairCounter.pop();
                }
            }
        }

        // 未能弹出的也是落单的字符
        while (!pairCounter.empty())
        {
            unPairCounter.push_back(pairCounter.top());
            pairCounter.pop();
        }

        // 末尾的结束符号也是落单字符
        unPairCounter.push_back(s.size());

        // 简单的排序
        sort(unPairCounter.begin(), unPairCounter.end());

        // 计算落单字符间的最大间距
        int nTemIndex = -1;
        for (int i = 0; i < unPairCounter.size(); ++i)
        {
            int nTempLen = unPairCounter[i] - nTemIndex - 1;
            if (nTempLen > nRetLen)
            {
                nRetLen = nTempLen;
            }
            nTemIndex = unPairCounter[i];
        }

        return nRetLen;
    }
};