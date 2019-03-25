/*
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
每个 LED 代表一个 0 或 1，最低位在右侧。
例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例:

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

注意事项:

输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。

readBinaryWatch1会占用很大的时间。

*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>

using namespace std;

class Solution {
public:
	void getHourAndMinite(int *hour, int *minite, vector<int> lst, vector<int> lightLst) {
		for (int i = 0; i < lst.size(); ++i) {
			if (lst[i] < 4) {
				*hour = *hour + lightLst[lst[i]];
			}
			else {
				*minite = *minite + lightLst[lst[i]];
			}
		}
	}

	bool checkLst(vector<int> lst, vector<int> lightLst) {
		// 检查时间是否正确
		int hour = 0;
		int minite = 0;

		int *nIndexFlag = new int[lightLst.size()]{ 0 };
		for (int i = 0; i < lst.size(); ++i) {
			nIndexFlag[lst[i]]++;
			if (nIndexFlag[lst[i]] > 1) {
				return false;
			}
		}

		int minIndex = 0;
		for (int i = 1; i < lst.size(); ++i) {
			if (lst[i] < lst[minIndex]) {
				return false;
			}
			else {
				minIndex = i;
			}
		}

		delete nIndexFlag;

		this->getHourAndMinite(&hour, &minite, lst, lightLst);
		if (hour >= 12 || minite > 59) {
			return false;
		}
		else {
			return true;
		}
	}

	string createString(vector<int> lst, vector<int> lightLst) {
		// 创建string
		int hour = 0;
		int minite = 0;
		this->getHourAndMinite(&hour, &minite, lst, lightLst);

		char cStr[10] = { 0 };
		sprintf_s(cStr, "%d:%02d", hour, minite);

		string retString(cStr);
		return retString;
	}

	void createLst(vector<string> &retLst, vector<int> lst, vector<int> lightLst, int num) {
		// 选择第n位上的数
		for (int i = 0; i < lightLst.size(); ++i) {
			lst.push_back(i);
			if (lst.size() == num) {
				if (this->checkLst(lst, lightLst)) {
					string pStr = this->createString(lst, lightLst);
					for (int j = 0; j < lst.size(); ++j) {
						cout << lst[j] << " ";
					}
					cout << "\t";
					cout << pStr.c_str() << endl;
					retLst.push_back(pStr);
				}
			}
			else {
				this->createLst(retLst, lst, lightLst, num);
			}
			lst.pop_back();
		}

	}

	vector<string> readBinaryWatch1(int num) {
		vector<int> lightLst = { 8, 4, 2, 1, 32, 16, 8, 4, 2, 1 };
		vector<int> lst;
		vector<string> retLst;
		if (num <= 8 && num >= 0) {
			if (num == 0) {
				retLst.push_back("0:00");
			}
			else {
				this->createLst(retLst, lst, lightLst, num);
			}
		}
		return retLst;
	}

	vector<string> readBinaryWatch2(int num) {
		vector<string> retString;
		for (int hour = 0; hour < 12; ++hour) {
			bitset<4> hourBit(hour);
			for (int minute = 0; minute < 60; ++minute) {
				bitset<6> minuteBit(minute);
				if ((hourBit.count() + minuteBit.count()) == num) {
					char pCStr[10] = { 0 };
					sprintf_s(pCStr, "%d:%02d", hour, minute);
					cout << pCStr << endl;
					retString.push_back(pCStr);
				}
			}
		}
		return retString;
	}
};

int main()
{
	Solution A;
	vector<string> strLst = A.readBinaryWatch2(8);
}

