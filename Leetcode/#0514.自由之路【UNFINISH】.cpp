/*
视频游戏“辐射4”中，任务“通向自由”要求玩家到达名为“Freedom Trail Ring”的金属表盘，并使用表盘拼写特定关键词才能开门。

给定一个字符串 ring，表示刻在外环上的编码；给定另一个字符串 key，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。

最初，ring 的第一个字符与12:00方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。

旋转 ring 拼出 key 字符 key[i] 的阶段中：

您可以将 ring 顺时针或逆时针旋转一个位置，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。
示例：

 


 
输入: ring = "godding", key = "gd"
输出: 4
解释:
 对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。 
 对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
 当然, 我们还需要1步进行拼写。
 因此最终的输出是 4。
提示：

ring 和 key 的字符串长度取值范围均为 1 至 100；
两个字符串中都只有小写字符，并且均可能存在重复字符；
字符串 key 一定可以由字符串 ring 旋转拼出。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/freedom-trail
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    vector<vector<int>> m_nRingRunnerLst;
    void getRingAllRunner(string &ring) {
        for (int i = 0; i < ring.size(); ++i) {
            for (int j = 0; j < ring.size(); ++j) {
                // ring[i]到ring[j]最少需要多少步
                if (i == j) continue;
                m_nRingRunnerLst[i][j] = min((int)(abs(j - i)), (int)(ring.size() - 1 - abs(j - i)));
            }
        }
    }
    int findMinRunner(char chA, char chB, string &ring)
    {
        int nRetMin = 0xFFFFFF;
        for (int i = 0; i < ring.size(); ++i)
        {
            for (int j = 0; j < ring.size(); ++j) 
            {
                if (ring[i] == chA && ring[j] == chB && m_nRingRunnerLst[i][j] < nRetMin) {
                    nRetMin = m_nRingRunnerLst[i][j];
                }
            }
        }

        return nRetMin;
    }
public:
    int findRotateSteps(string ring, string key) {
        m_nRingRunnerLst.clear();
        vector<vector<int>> tempLst(100, vector<int>(100, 0));
        m_nRingRunnerLst = tempLst;

        getRingAllRunner(ring);

        int nRetTimes = key.size();
        char cLastChar = ring[0];
        for (int i = 0; i < key.size(); ++i) {
            nRetTimes = nRetTimes + findMinRunner(cLastChar, key[i], ring);
            cLastChar = key[i];
        }
        return nRetTimes;
    }
};