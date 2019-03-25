/*
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出: 
"apple"
示例 2:

输入:
s = "abpcplea", d = ["a","b","c"]

输出: 
"a"
说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。
*/

class Solution {
public:
    // 用于检测s去除一些字符是否能变成d
    bool isSonString(string s, string d) {
        int nSIndex = 0, nDIndex = 0;
		do
		{
			if (s[nSIndex++] == d[nDIndex]) {
				nDIndex++;
			}
		} while (nSIndex != s.length());

		if (nDIndex == d.length()) {
			return true;
		}
		else {
			return false;
		}
        
        /*
        错误写法
        int nSIndex = 0, nDIndex = 0;
        for (nDIndex = 0; nDIndex < d.length(); ++nDIndex) {
            for (; nSIndex < s.length(); ++nSIndex) {
                if (s[nSIndex] == d[nDIndex]) {
                    break;
                } else {
                    continue;
                }
            }
            
            if (nSIndex == s.length()) {
                return false;
            }
        }
        */
        
        return true;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        int nRetIndex = -1;
        if (s.size() == 0 || d.size() == 0) {
            return "";
        }
        for (int i = 0; i < d.size(); ++i) {
            if (isSonString(s, d[i])) {
                cout << d[i] << endl;
                if (nRetIndex == -1) {                                      // 如果这是第一个符合要求的子串
                    nRetIndex = i;
                } else if (d[i].length() > d[nRetIndex].length()) {         // 如果长度大于前一个符合要求的子串
                    nRetIndex = i;
                } else if (d[i].length() == d[nRetIndex].length()) {        // 长度相同则判断字典序
                    if (d[i] < d[nRetIndex]) {
                        nRetIndex = i;
                    }
                }
            }
        }
        
        if (nRetIndex == -1) {
            return "";
        } else {
            return d[nRetIndex];
        }
    }
};
