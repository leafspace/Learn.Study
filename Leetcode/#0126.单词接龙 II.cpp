/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    enum WordType
    {
        WordType_UNFIND = 0,
        WordType_FIND = 1,
        WordType_Begin = 3,
        WordType_End = 4,
        WordType_Runed = 5,
    };

    typedef struct Point
    {
        int x;
        int y;
    } Point;

    Point m_beginWordPoint;
    Point m_endWordPoint;
    vector<vector<char>> m_listWordCharDir;
    vector<vector<string>> m_listWordMap;
    vector<vector<WordType>> m_listWordFlagMap;
    vector<vector<Point>> m_listWordPointWay;
public:
    int SearchWord(string strWord, const vector<string> wordList)
    {
        for (size_t i = 0; i < wordList.size(); ++i)
        {
            if (wordList[i] == strWord)
            {
                return i;
            }
        }

        return -1;
    }

    vector<vector<char>> CreateWordCharDir(string beginWord, string endWord, vector<string> wordList)
    {
        wordList.push_back(beginWord);
        wordList.push_back(endWord);

        vector<vector<char>> listWordCharDir(wordList[0].size());
        for (size_t i = 0; i < wordList[0].length(); ++i)
        {
            char tempBuffer[26] = { 0 };
            for (size_t j = 0; j < wordList.size(); ++j)
            {
                tempBuffer[wordList[j][i] - 'a']++;
            }

            for (size_t j = 0; j < 26; ++j)
            {
                if (tempBuffer[j] > 0)
                {
                    listWordCharDir[i].push_back(j + 'a');
                }
            }
        }

        return listWordCharDir;
    }

    void DeepLoopListWordCharDir(const vector<vector<char>> listWordCharDir, int nDeepIndex, string beforeStr, vector<string>& tempWordList)
    {
        if (nDeepIndex >= listWordCharDir.size())
        {
            return;
        }

        for (size_t i = 0; i < listWordCharDir[nDeepIndex].size(); ++i)
        {
            string newStr = beforeStr + listWordCharDir[nDeepIndex][i];
            if (nDeepIndex == (listWordCharDir.size() - 1))
            {
                tempWordList.push_back(newStr);
            }
            else
            {
                DeepLoopListWordCharDir(listWordCharDir, nDeepIndex + 1, newStr, tempWordList);
            }
        }
    }

    vector<vector<string>> CreateWordMap(const vector<vector<char>> listWordCharDir)
    {
        vector<vector<string>> listWordMap;
        vector<string> tempWordList;

        DeepLoopListWordCharDir(listWordCharDir, 1, "", tempWordList);

        for (size_t i = 0; i < tempWordList.size(); ++i)
        {
            vector<string> tempWordLine;
            for (size_t j = 0; j < listWordCharDir[0].size(); ++j)
            {
                tempWordLine.push_back(listWordCharDir[0][j] + tempWordList[i]);
            }
            listWordMap.push_back(tempWordLine);
        }

        return listWordMap;
    }

    vector<vector<WordType>> CreateWordFlagMap(const vector<vector<string>> listWordMap, const vector<string> wordList,
        string beginWord, string endWord)
    {
        vector<vector<WordType>> listWordFlagMap(listWordMap.size(), vector<WordType>(listWordMap[0].size()));
        for (size_t i = 0; i < listWordMap.size(); ++i)
        {
            for (size_t j = 0; j < listWordMap[i].size(); ++j)
            {
                listWordFlagMap[i][j] = SearchWord(listWordMap[i][j], wordList) == -1 ? WordType_UNFIND : WordType_FIND;

                if (listWordMap[i][j] == beginWord)
                {
                    listWordFlagMap[i][j] = WordType_Begin;
                    m_beginWordPoint.x = i;
                    m_beginWordPoint.y = j;
                }

                if (listWordMap[i][j] == endWord)
                {
                    listWordFlagMap[i][j] = WordType_End;
                    m_endWordPoint.x = i;
                    m_endWordPoint.y = j;
                }
            }
        }

        return listWordFlagMap;
    }

    void DeepLoopWay(const Point beginWordPoint, const Point endWordPoint, const vector<vector<WordType>> listWordFlagMap, vector<Point> tempWay)
    {
        vector<Point> tempWayPointList;
        for (size_t i = 0; i < listWordFlagMap.size(); ++i)
        {
            if (i == beginWordPoint.x) continue;
            if (listWordFlagMap[i][beginWordPoint.y] == WordType_FIND)
            {
                Point point;
                point.x = i;
                point.y = beginWordPoint.y;
                tempWayPointList.push_back(point);
            }
            else if (listWordFlagMap[i][beginWordPoint.y] == WordType_End)
            {
                if (i == endWordPoint.x && beginWordPoint.y == endWordPoint.y)
                {
                    tempWay.push_back(endWordPoint);
                    m_listWordPointWay.push_back(tempWay);

                    return;
                }
            }
        }

        for (size_t i = 0; i < listWordFlagMap[0].size(); ++i)
        {
            if (i == beginWordPoint.y) continue;
            if (listWordFlagMap[beginWordPoint.x][i] == WordType_FIND)
            {
                Point point;
                point.x = beginWordPoint.x;
                point.y = i;
                tempWayPointList.push_back(point);
            }
            else if (listWordFlagMap[beginWordPoint.x][i] == WordType_End)
            {
                if (beginWordPoint.x == endWordPoint.x && i == endWordPoint.y)
                {
                    tempWay.push_back(endWordPoint);
                    m_listWordPointWay.push_back(tempWay);

                    return;
                }
            }
        }

        for (size_t i = 0; i < tempWayPointList.size(); ++i)
        {
            tempWay.push_back(tempWayPointList[i]);
            
            vector<vector<WordType>> tempListWordFlagMap = listWordFlagMap;
            tempListWordFlagMap[tempWayPointList[i].x][tempWayPointList[i].y] = WordType_Runed;

            DeepLoopWay(tempWayPointList[i], endWordPoint, tempListWordFlagMap, tempWay);

            tempWay.pop_back();
        }
    }

    int FindMinLength(const vector<vector<Point>> listWordPointWay)
    {
        int nMinLength = 99999;
        for (size_t i = 0; i < listWordPointWay.size(); ++i)
        {
            if (listWordPointWay[i].size() < nMinLength)
            {
                nMinLength = listWordPointWay[i].size();
            }
        }
        return nMinLength;
    }

    vector<vector<string>> CreateStringList(string beginWord, vector<vector<string>> listWordMap, vector<vector<Point>> listWordPointWay)
    {
        vector<vector<string>> retListArray;
        int nMinLength = FindMinLength(listWordPointWay);

        for (size_t i = 0; i < listWordPointWay.size(); ++i)
        {
            if (listWordPointWay[i].size() == nMinLength)
            {
                vector<string> tempList;
                tempList.push_back(beginWord);

                for (size_t j = 0; j < listWordPointWay[i].size(); ++j)
                {
                    tempList.push_back(listWordMap[listWordPointWay[i][j].x][listWordPointWay[i][j].y]);
                }

                retListArray.push_back(tempList);
            }
        }

        return retListArray;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> retListArray;
        if (SearchWord(beginWord, wordList) == -1)
        {
            wordList.push_back(beginWord);
        }

        if (SearchWord(endWord, wordList) == -1)
        {
            return retListArray;
        }

        if (endWord.length() == 1)
        {
            vector<string> tempList;
            tempList.push_back(beginWord);
            tempList.push_back(endWord);
            retListArray.push_back(tempList);
            return retListArray;
        }

        m_listWordCharDir = CreateWordCharDir(beginWord, endWord, wordList);
        m_listWordMap = CreateWordMap(m_listWordCharDir);
        m_listWordFlagMap = CreateWordFlagMap(m_listWordMap, wordList, beginWord, endWord);

        vector<Point> tempWay;
        DeepLoopWay(m_beginWordPoint, m_endWordPoint, m_listWordFlagMap, tempWay);

        retListArray = CreateStringList(beginWord, m_listWordMap, m_listWordPointWay);

        return retListArray;
    }
};