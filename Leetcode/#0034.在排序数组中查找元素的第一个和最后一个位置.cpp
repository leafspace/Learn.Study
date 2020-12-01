/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
通过次数154,341提交次数378,827

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
private:
    int search2Way(vector<int>& nums, int nBegin, int nEnd, int target)
    {
        if (nEnd < nBegin) return -1;
        int nCenter = (nBegin + nEnd) / 2;
        if (nums[nCenter] == target) return nCenter;
        else if (nums[nCenter] > target) return search2Way(nums, nBegin, nCenter - 1, target);
        else return search2Way(nums, nCenter + 1, nEnd, target);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> retLst = { - 1, -1 };
        if (nums.size() < 1) return retLst;

        int nSearchIndex = search2Way(nums, 0, nums.size() - 1, target);
        if (nSearchIndex == -1) return retLst;

        int nNext = nSearchIndex;
        while (nNext < nums.size() && nums[nNext] == nums[nSearchIndex]) { nNext++; }
        nNext--;

        int nLast = nSearchIndex;
        while (nLast >= 0 && nums[nLast] == nums[nSearchIndex]) { nLast--; }
        nLast++;

        retLst[0] = nLast;
        retLst[1] = nNext;

        return retLst;
    }
};