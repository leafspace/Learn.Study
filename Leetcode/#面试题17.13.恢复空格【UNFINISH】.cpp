/*
哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。

注意：本题相对原题稍作改动，只需返回未识别的字符数

 

示例：

输入：
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
输出： 7
解释： 断句后为"jess looked just like tim her brother"，共7个未识别字符。
提示：

0 <= len(sentence) <= 1000
dictionary中总字符数不超过 150000。
你可以认为dictionary和sentence中只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/re-space-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool pairString(string sentence, int nSentenceBegin, bool* bFlagSentence, string paistring)
    {
        int j = 0;

        while ((nSentenceBegin + j) < sentence.size() && j < paistring.size() && bFlagSentence[nSentenceBegin + j] == false &&
            sentence[nSentenceBegin + j] == paistring[j]) {
            j++;
        }

        if (j >= paistring.size()) return true;

        return false;
    }

    int respace(vector<string>& dictionary, string sentence) {
        int nRetLen = 0;
        sort(dictionary.begin(), dictionary.end());

        vector<int> dictionaryIndex(26, -1);
        if (dictionary.size() != 0) dictionaryIndex[dictionary[0][0] - 'a'] = 0;
        for (int i = 1; i < dictionary.size(); ++i)
        {
            if (dictionary[i][0] != dictionary[i - 1][0])
            {
                dictionaryIndex[dictionary[i][0] - 'a'] = i;
            }
        }

        bool* bFlagSentence = new bool[sentence.size()];

        for (int i = 0; i < sentence.size(); ++i)
        {
            bFlagSentence[i] = false;
        }


        for (int i = 0; i < sentence.size(); ++i)
        {
            if (bFlagSentence[i] || dictionaryIndex[sentence[i] - 'a'] == -1)
            {
                continue;
            }

            int nDictionBegin = dictionaryIndex[sentence[i] - 'a'];
            int nDictionEnd = 0;

            int j = 1;
            while ((sentence[i] - 'a' + j) < 26 && dictionaryIndex[sentence[i] - 'a' + j] == -1) { j++; }
            nDictionEnd = (sentence[i] - 'a' + j) >= 26 ? dictionary.size() - 1 : dictionaryIndex[sentence[i] - 'a' + j] - 1;

            for (int j = nDictionEnd; j >= nDictionBegin; --j)
            {
                if (pairString(sentence, i, bFlagSentence, dictionary[j]))
                {
                    memset(&bFlagSentence[i], true, sizeof(bool) * dictionary[j].size());
                    i = i + dictionary[j].size() - 1;
                    break;
                }
            }
        }

        for (int i = 0; i < sentence.size(); ++i)
        {
            if (bFlagSentence[i] == false) nRetLen++;
        }

        delete[] bFlagSentence;
        return nRetLen;

    }
};