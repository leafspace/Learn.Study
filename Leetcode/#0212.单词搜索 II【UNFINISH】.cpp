/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
*/

typedef struct Point
{
    int x;
    int y;
    
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
}Point;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> retStrings;
        
        // 建立索引列表
        vector<Point> *pIndexs = new vector<Point>[26];
        this->createIndexs(board, pIndexs);
        
        // 按照单词循环找字母
        for (int i = 0; i < words.size(); ++i) {
            if (this->checkWord(words[i])) {
                retStrings.push_back(words[i]);
            }
        }
        
        return retStrings;
    }
    
    void createIndexs(vector<vector<char>>& board, vector<Point>* pIndexs) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                Point pPoint(i, j);
                pIndexs[board[i][j] - 'a'].push_back(pPoint);
            }
        }
    }
    
    bool checkWord(vector<Point>* pIndexs, string word) {
     }
};