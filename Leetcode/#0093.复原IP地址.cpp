/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<string>> proList;

    void restoreIpAddresses(string s, vector<string> strList, int nIndex, int nBegin)
    {
        if (nBegin >= s.size()) return;
        if (nIndex == 4)
        {
            strList.push_back(s.substr(nBegin));
            if (strList[nIndex - 1].length() > 0 && strList[nIndex - 1].length() <= 3 && stoi(strList[nIndex - 1]) <= 255)
            {
                if (stoi(strList[nIndex - 1]) == 0 && strList[nIndex - 1].length() > 1 || strList[nIndex - 1][0] == '0' && strList[nIndex - 1].length() > 1)
                {
                }
                else
                {
                    proList.push_back(strList);
                }
            }
        }
        else
        {
            vector<string> list1 = strList;
            list1.push_back(s.substr(nBegin, 1));
            if (list1[nIndex - 1].length() > 0 && stoi(list1[nIndex - 1]) <= 255)
            {
                if (stoi(list1[nIndex - 1]) == 0 && list1[nIndex - 1].length() > 1 || list1[nIndex - 1][0] == '0' && list1[nIndex - 1].length() > 1)
                {
                }
                else
                {
                    restoreIpAddresses(s, list1, nIndex + 1, nBegin + 1);
                }
            }
            
            vector<string> list2 = strList;
            list2.push_back(s.substr(nBegin, 2));
            if (list2[nIndex - 1].length() > 0 && stoi(list2[nIndex - 1]) <= 255)
            {
                if (stoi(list2[nIndex - 1]) == 0 && list2[nIndex - 1].length() > 1 || list2[nIndex - 1][0] == '0' && list2[nIndex - 1].length() > 1)
                {
                }
                else
                {
                    restoreIpAddresses(s, list2, nIndex + 1, nBegin + 2);
                }
            }

            vector<string> list3 = strList;
            list3.push_back(s.substr(nBegin, 3));
            if (list3[nIndex - 1].length() > 0 && stoi(list3[nIndex - 1]) <= 255)
            {
                if (stoi(list3[nIndex - 1]) == 0 && list3[nIndex - 1].length() > 1 || list3[nIndex - 1][0] == '0' && list3[nIndex - 1].length() > 1)
                {
                }
                else
                {
                    restoreIpAddresses(s, list3, nIndex + 1, nBegin + 3);
                }
            }
            
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> retStrList;
        restoreIpAddresses(s, retStrList, 1, 0);

        for (int i = 0; i < proList.size(); ++i)
        {
            string tempStr;
            for (int j = 0; j < 4; ++j)
            {
                if (proList[i][j].length() > 3 || stoi(proList[i][j]) > 255)
                {
                    tempStr = "";
                    break;
                }
                if (j == 3)
                {
                    tempStr = tempStr + proList[i][j];
                }
                else
                {
                    tempStr = tempStr + proList[i][j];
                    tempStr = tempStr + '.';
                }
            }

            if (tempStr != "" && tempStr.length() == (s.length() + 3))
            {
                retStrList.push_back(tempStr);
            }
        }
        return retStrList;
    }
};