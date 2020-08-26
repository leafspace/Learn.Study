/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    vector<string> retList;
    vector<string> numberFlag = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
public:
    void deepLoop(string digits, int nIndex, string already)
    {
        for (int i = 0; i < numberFlag[digits[nIndex] - '0'].size(); ++i)
        {
            string tempStr = already + numberFlag[digits[nIndex] - '0'][i];
            if (nIndex == digits.size() - 1)
            {
                retList.push_back(tempStr);
            }
            else
            {
                deepLoop(digits, nIndex + 1, tempStr);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        retList.clear();
        if (digits.size() == 0) return retList;

        deepLoop(digits, 0, "");

        return retList;
    }
};