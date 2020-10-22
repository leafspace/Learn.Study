/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。
通过次数23,640提交次数32,305

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef struct CharInterval
{
    char ch;
    int uBegin;
    int uEnd;

    CharInterval(void)
    {
        ch = 0;
        uBegin = -1;
        uEnd = -1;
    }
} CharInterval;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<CharInterval> m_lstCharInterval(26);

        for (int i = 0; i < 26; ++i) {
            m_lstCharInterval[i].ch = 'a' + i;
        }

        for (int i = 0; i < S.length(); ++i) {
            if (m_lstCharInterval[S[i] - 'a'].uBegin == -1)
            {
                m_lstCharInterval[S[i] - 'a'].uBegin = i;
            }
            else
            {
                m_lstCharInterval[S[i] - 'a'].uEnd = i;
            }
        }

        for (int i = 0; i < 26; ++i) {
            int nMinIndex = i;
            for (int j = i + 1; j < 26; ++j) {
                if (m_lstCharInterval[j].uBegin < m_lstCharInterval[nMinIndex].uBegin) nMinIndex = j;
            }

            if (i != nMinIndex) {
                CharInterval temp = m_lstCharInterval[nMinIndex];
                for (int j = nMinIndex; j > i; --j) {
                    m_lstCharInterval[j] = m_lstCharInterval[j - 1];
                }

                m_lstCharInterval[i] = temp;
            }
        }

        vector<int> retList;
        vector<CharInterval> retInterval;

        for (int i = 0; i < 26; ++i) {
            if (m_lstCharInterval[i].uBegin == -1 &&
                m_lstCharInterval[i].uEnd == -1) {
                continue;
            }
            else if (m_lstCharInterval[i].uBegin != -1 &&
                m_lstCharInterval[i].uEnd == -1) {
                m_lstCharInterval[i].uEnd = m_lstCharInterval[i].uBegin;
            }

            int j = 0;
            for (; j < retInterval.size(); ++j) {
                if (m_lstCharInterval[i].uBegin >= retInterval[j].uBegin &&
                    m_lstCharInterval[i].uBegin <= retInterval[j].uEnd ||
                    m_lstCharInterval[i].uEnd >= retInterval[j].uBegin &&
                    m_lstCharInterval[i].uEnd <= retInterval[j].uEnd ||


                    retInterval[j].uBegin >= m_lstCharInterval[i].uBegin &&
                    retInterval[j].uBegin <= m_lstCharInterval[i].uEnd ||
                    retInterval[j].uEnd >= m_lstCharInterval[i].uBegin &&
                    retInterval[j].uEnd <= m_lstCharInterval[i].uEnd) {

                    retInterval[j].uBegin = min(retInterval[j].uBegin, m_lstCharInterval[i].uBegin);
                    retInterval[j].uEnd = max(retInterval[j].uEnd, m_lstCharInterval[i].uEnd);
                    break;
                }
            }

            if (j == retInterval.size()) {
                retInterval.push_back(m_lstCharInterval[i]);
            }
        }

        int nNextBegin = 0;
        vector<CharInterval> lstSortRetInterval;
        while (nNextBegin < S.size()) {
            for (int i = 0; i < retInterval.size(); ++i) {
                if (retInterval[i].uBegin == nNextBegin) {
                    nNextBegin = retInterval[i].uEnd + 1;
                    lstSortRetInterval.push_back(retInterval[i]);
                }
            }
        }

        retInterval = lstSortRetInterval;
        for (int i = 0; i < retInterval.size(); ++i) {
            retList.push_back(retInterval[i].uEnd - retInterval[i].uBegin + 1);
        }
        return retList;
    }
};