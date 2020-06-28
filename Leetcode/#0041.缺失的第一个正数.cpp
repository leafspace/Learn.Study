/*
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

 

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
 

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums.size() == 0) return 1;

        int nIndex = 0;
        while (nIndex < nums.size() && nums[nIndex] <= 0) nIndex++;

        if ((nIndex == nums.size()) || (nIndex < nums.size() && nums[nIndex] > 1)) return 1;

        for (nIndex++; nIndex < nums.size(); ++nIndex)
        {
            if (nums[nIndex] > (nums[nIndex - 1] + 1))
            {
                return (nums[nIndex - 1] + 1);
            }
        }

        return (nums[nIndex - 1] + 1);
    }
};