/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：

1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。
*/

class Solution {
public:
    bool compareStack(stack<char> S, stack<char> T) {
        while(!S.empty() && !T.empty()) {
            if (S.top() != T.top()) {
                cout << "Stack is diffrent ! (" << S.top() << "," << T.top()  << ")" << endl;
                return false;
            }
            S.pop();
            T.pop();
        }
        
        if (!S.empty() || !T.empty()) {
            cout << "Have stack not empty !" << endl;
            return false;
        } else {
            return true;
        }
    }
    
    stack<char> string2Stack(string pStr) {
        stack<char> pStack;
        for (int i = 0; i < pStr.length(); ++i) {
            if (pStr[i] == '#') {
                if (!pStack.empty()) {
                    pStack.pop();
                }
                continue;
            }
            pStack.push(pStr[i]);
        }
        return pStack;
    }
    
    bool backspaceCompare(string S, string T) {
        return this->compareStack(this->string2Stack(S), this->string2Stack(T));
    }
};

// 202010  

class Solution {
    void InitStack(stack<char> &st, string str)
    {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else
            {
                st.push(str[i]);
            }
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        stack<char> sStack;
        stack<char> tStack;

        InitStack(sStack, S);
        InitStack(tStack, T);

        while (!sStack.empty() && !tStack.empty())
        {
            if (sStack.top() != tStack.top()) {
                return false;
            }

            sStack.pop();
            tStack.pop();
        }

        if (!sStack.empty() || !tStack.empty()) {
            return false;
        }

        return true;

    }
};