/*
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 
示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
示例 3：

输入：name = "leelee", typed = "lleeelee"
输出：true
示例 4：

输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。
 

提示：

name.length <= 1000
typed.length <= 1000
name 和 typed 的字符都是小写字母。
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (strcmp(name.c_str(), typed.c_str()) == 0) {
            return true;
        } else if (name.length() > typed.length()) {
            return false;
        }
        
        for (int i = 0, typedI = 0; i < name.length(); ++i) {
            int iNameTimes = 0, iTypedTimes = 0;
            char cPName = name[i];
            char cPTyped = typed[typedI];
            // 查找这一阶段所有的相同字符
            while (i < name.length() && name[i] == cPName) {
                i++;
                iNameTimes++;
            }
            --i;                                         // 回到最后一个相同的字符
            cout << i << "\t" << iNameTimes << endl;
            
            if (cPName != typed[typedI]) {
                return false;
            } else {
                while (typedI < typed.length() && typed[typedI] == cPTyped) {
                    typedI++;
                    iTypedTimes++;
                }
                if (iNameTimes > iTypedTimes) {
                    return false;
                }
            }
        }
        
        return true;
    }
};