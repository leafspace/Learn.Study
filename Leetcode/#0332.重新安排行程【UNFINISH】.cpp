/*
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
示例 1:

输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
示例 2:

输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
	bool findPath(vector<string>& list, string begin, string end)
	{
		for (int i = 0; i < list.size() - 1; ++i)
		{
			if (list[i] == begin && list[i + 1] == end)
				return true;
		}

		return false;
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		map<string, vector<string>> indexMap;

		for (int i = 0; i < tickets.size(); ++i)
		{
			if (indexMap.find(tickets[i][0]) == indexMap.end())
			{
				vector<string> pointIndexList;
				pointIndexList.push_back(tickets[i][1]);

				indexMap[tickets[i][0]] = pointIndexList;
			}
			else
			{
				indexMap[tickets[i][0]].push_back(tickets[i][1]);
			}
		}

		for (auto iter = indexMap.begin(); iter != indexMap.end(); ++iter)
		{
			sort(iter->second.begin(), iter->second.end());
		}

		vector<string> retList;
		retList.push_back("JFK");

		while (indexMap.find(retList[retList.size() - 1]) != indexMap.end() && indexMap[retList[retList.size() - 1]].size() != 0)
		{
			bool bFlag = true;
			for (int i = 0; i < indexMap[retList[retList.size() - 1]].size(); ++i)
			{
				if (!findPath(retList, retList[retList.size() - 1], indexMap[retList[retList.size() - 1]][i]))
				{
					retList.push_back(indexMap[retList[retList.size() - 1]][i]);
					bFlag = false;
					break;
				}
			}

			if (bFlag) break;
		}

		return retList;
	}
};