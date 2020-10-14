/*
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    vector<vector<int>> m_charCountLst;
public:
    vector<string> commonChars(vector<string>& A) {
        m_charCountLst.clear();
        vector<vector<int>> tempList(A.size(), vector<int>(26, 0));
        m_charCountLst = tempList;

        vector<string> retList;

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                m_charCountLst[i][A[i][j] - 'a']++;
            }
        }

        for (int j = 0; j < 26; ++j) {
            int nMinCount = 0xFFFF;
            for (int i = 0; i < m_charCountLst.size(); ++i) {
                if (m_charCountLst[i][j] < nMinCount) {
                    nMinCount = m_charCountLst[i][j];
                }
            }

            if (nMinCount != 0) {
                char chars = (char)('a' + j);
                string tempStr = " ";
                tempStr[0] = chars;
                for (int i = 0; i < nMinCount; ++i) {
                    retList.push_back(tempStr);
                }
            }
        }

        return retList;
    }
};