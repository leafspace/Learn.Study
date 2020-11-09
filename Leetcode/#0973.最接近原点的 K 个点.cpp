/*
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
 

提示：

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-closest-points-to-origin
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    void quicksort(vector<vector<int>>& points, int left, int right) {
        if (left >= right) return;

        int i = left;
        int j = right;
        vector<int> key = points[left];

        while (i < j)
        {
            while (i < j && (pow(key[0], 2) + pow(key[1], 2)) < (pow(points[j][0], 2) + pow(points[j][1], 2))) { j--; }

            points[i] = points[j];

            while (i < j && (pow(key[0], 2) + pow(key[1], 2)) >= (pow(points[i][0], 2) + pow(points[i][1], 2))) { i++; }

            points[j] = points[i];
        }

        points[i] = key;
        quicksort(points, left, i - 1);
        quicksort(points, i + 1, right);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quicksort(points, 0, points.size() - 1);

        vector<vector<int>> retLst;
        for (int i = 0; i < K; ++i) {
            retLst.push_back(points[i]);
        }

        return retLst;
    }
};