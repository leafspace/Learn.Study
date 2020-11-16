/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
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

    void quicksort2(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) return;

        int i = left;
        int j = right;
        vector<int> key = intervals[left];

        while (i < j)
        {
            while (i < j && key[1] >= intervals[j][1]) { j--; }

            intervals[i] = intervals[j];

            while (i < j && key[1] < intervals[i][1]) { i++; }

            intervals[j] = intervals[i];
        }

        intervals[i] = key;
        quicksort2(intervals, left, i - 1);
        quicksort2(intervals, i + 1, right);
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        quicksort(people, 0, people.size() - 1);

        int i = 1, nBegin = 0;
        for (; i < people.size(); ++i) {
            if (people[i][0] == people[nBegin][0]) { continue; }
            else if ((i - nBegin) > 1) {
                quicksort2(people, nBegin, i - 1);
            }
            nBegin = i;
        }
        if ((i - nBegin) > 1) {
            quicksort2(people, nBegin, i - 1);
        }

        for (int i = people.size() - 1; i >= 0; --i) {
            if (people[i][1] == 0) continue;

            if ((i + people[i][1]) >= people.size()) break;

            vector<int> moveLst = people[i];
            for (int j = 0; j < moveLst[1]; ++j) {
                people[i + j] = people[i + j + 1];
                people[i + j + 1] = moveLst;
            }
        }
        return people;
    }
};