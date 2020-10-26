/*
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

 

示例 1：

输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：

输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：

输入：nums = [7,7,7,7]
输出：[0,0,0,0]
 

提示：

2 <= nums.length <= 500
0 <= nums[i] <= 100
通过次数31,818提交次数38,693

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

typedef struct Point
{
    int nIndex;
    int nValue;

    Point() {
        nIndex = -1;
        nValue = -1;
    }

    Point(int nI, int nV) {
        nIndex = nI;
        nValue = nV;
    }
} Point;
class Solution {
private:
    vector<Point> m_lstPoint;

    void quickSort(int nBegin, int nEnd) {
        if (nEnd <= nBegin) return;

        int i = nBegin;
        int j = nEnd + 1;
        Point key = m_lstPoint[i];

        while (true)
        {
            while (m_lstPoint[++i].nValue < key.nValue) {
                if (i == nEnd) break;
            }

            while (m_lstPoint[--j].nValue > key.nValue) {
                if (j == nBegin) break;
            }

            if (i >= j) break;

            Point temp = m_lstPoint[i];
            m_lstPoint[i] = m_lstPoint[j];
            m_lstPoint[j] = temp;

        }

        Point temp = m_lstPoint[nBegin];
        m_lstPoint[nBegin] = m_lstPoint[j];
        m_lstPoint[j] = temp;

        quickSort(nBegin, j - 1);
        quickSort(j + 1, nEnd);
    }
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        m_lstPoint.clear();
        for (int i = 0; i < nums.size(); ++i) {
            Point point(i, nums[i]);
            m_lstPoint.push_back(point);
        }

        quickSort(0, m_lstPoint.size() - 1);

        //vector<int> nRetList(nums.size(), -1);
        nums[m_lstPoint[0].nIndex] = 0;
        for (int i = 1, nRank = 1; i < m_lstPoint.size(); ++i, nRank++) {
            if (m_lstPoint[i].nValue == m_lstPoint[i - 1].nValue) 
            {
                nums[m_lstPoint[i].nIndex] = nums[m_lstPoint[i - 1].nIndex];
            }
            else
            {
                nums[m_lstPoint[i].nIndex] = nRank;
            }
        }
        return nums;
    }
};
