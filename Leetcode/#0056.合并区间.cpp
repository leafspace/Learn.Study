/*
给出一个区间的集合，请合并所有重叠的区间。

 

示例 1:

输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。

 

提示：

intervals[i][0] <= intervals[i][1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
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
};