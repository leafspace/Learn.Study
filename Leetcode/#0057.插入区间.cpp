/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
	void quicksort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) return;

        int i = left;
        int j = right;
        vector<int> key = intervals[left];

        while (i < j)
        {
            while (i < j && key[0] < intervals[j][0]) { j--; }

            intervals[i] = intervals[j];

            while (i < j && key[0] >= intervals[i][0]) { i++; }

            intervals[j] = intervals[i];
        }

        intervals[i] = key;
        quicksort(intervals, left, i - 1);
        quicksort(intervals, i + 1, right);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        quicksort(intervals, 0, intervals.size() - 1);

        vector<vector<int>> retList;
        for (int i = 0; i < intervals.size(); ++i) {
            int j = 0;
            for (; j < retList.size(); ++j) {
                if (intervals[i][0] >= retList[j][0] &&
                    intervals[i][0] <= retList[j][1] ||
                    intervals[i][1] >= retList[j][0] &&
                    intervals[i][1] <= retList[j][1] ||


                    retList[j][0] >= intervals[i][0] &&
                    retList[j][0] <= intervals[i][1] ||
                    retList[j][1] >= intervals[i][0] &&
                    retList[j][1] <= intervals[i][1]) {

                    retList[j][0] = min(retList[j][0], intervals[i][0]);
                    retList[j][1] = max(retList[j][1], intervals[i][1]);
                    break;
                }
            }

            if (j == retList.size()) retList.push_back(intervals[i]);
        }

        return retList;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int nNewIntervalBeginIndexGroup = -1;
        int nNewIntervalEndIndexGroup = -1;

        vector<vector<int>> retLst;
        retLst = intervals;
        retLst.push_back(newInterval);

        retLst = merge(retLst);

        return retLst;
    }
};