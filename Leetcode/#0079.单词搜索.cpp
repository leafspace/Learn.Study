/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef struct Point {
    int x;
    int y;

    Point(int nX, int nY) {
        x = nX;
        y = nY;
    }
} Point;

class Solution {
private:
    vector<vector<Point>> m_smallCharList;
    vector<vector<Point>> m_upperCharList;
    vector<int> m_smallCharCountList;
    vector<int> m_upperCharCountList;

    bool judgeNearChar(Point& A, Point& B) {
        if ((A.x - 1) == B.x && A.y == B.y) return true;
        if (A.x == B.x && (A.y - 1) == B.y) return true;
        if ((A.x + 1) == B.x && A.y == B.y) return true;
        if (A.x == B.x && (A.y + 1) == B.y) return true;

        return false;
    }

    bool checkIsUsed(stack<Point> alreadyStack, Point& point) {
        while (!alreadyStack.empty()) {
            if (alreadyStack.top().x == point.x && alreadyStack.top().y == point.y) {
                return true;
            }
            alreadyStack.pop();
        }

        return false;
    }

    bool deepExist(string word, stack<Point> alreadyStack, int nIndex = 0) {
        Point lastPoint(0, 0);
        if (!alreadyStack.empty()) {
            lastPoint = alreadyStack.top();
        }

        if (nIndex == word.size()) return true;

        int nListIndex = -1;
        vector<vector<Point>>* useList = nullptr;
        if (word[nIndex] >= 'a' && word[nIndex] <= 'z') {
            useList = &m_smallCharList;
            nListIndex = word[nIndex] - 'a';

            if (m_smallCharCountList[nListIndex] > m_smallCharList[nListIndex].size()) return false;
        }
        else {
            useList = &m_upperCharList;
            nListIndex = word[nIndex] - 'A';

            if (m_upperCharCountList[nListIndex] > m_upperCharList[nListIndex].size()) return false;
        }

        bool retFlag = false;
        for (int i = 0; i < (*useList)[nListIndex].size(); ++i) {
            if (checkIsUsed(alreadyStack, (*useList)[nListIndex][i])) continue;

            if (alreadyStack.empty()) {
                alreadyStack.push((*useList)[nListIndex][i]);
            }
            else {
                Point tempPoint = (*useList)[nListIndex][i];
                if (!judgeNearChar(lastPoint, tempPoint)) {
                    continue;
                }
                else {
                    alreadyStack.push((*useList)[nListIndex][i]);
                }
            }

            retFlag = retFlag || deepExist(word, alreadyStack, nIndex + 1);
            if (retFlag) return retFlag;

            alreadyStack.pop();
        }
        return retFlag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<Point>> tempPointList(26);
        m_smallCharList = tempPointList;
        m_upperCharList = tempPointList;

        vector<int> tempCountList(26, 0);
        m_smallCharCountList = tempCountList;
        m_upperCharCountList = tempCountList;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                Point point(i, j);
                if (board[i][j] >= 'a' && board[i][j] <= 'z')
                {
                    m_smallCharList[board[i][j] - 'a'].push_back(point);
                }
                else
                {
                    m_upperCharList[board[i][j] - 'A'].push_back(point);
                }
            }
        }

        for (int i = 0; i < word.size(); ++i) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                m_smallCharCountList[word[i] - 'a']++;
            }
            else {
                m_upperCharCountList[word[i] - 'A']++;
            }
        }

        stack<Point> alreadyStack;
        return deepExist(word, alreadyStack);
    }
};
