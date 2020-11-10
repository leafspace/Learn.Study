/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 例： 4 5 2 6 3 1 找到峰值，交换峰值两端
        if (nums.size() < 2) return;
        int nTop = -1;

        // 找到峰值
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) { i--; }

        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        nTop = i;
        i = nums.size() - 1;
        while (i >= 0 && nums[i] <= nums[nTop]) { i--; }

        // 交换两数
        if (nTop != i) {
            int temp = nums[i];
            nums[i] = nums[nTop];
            nums[nTop] = temp;
        }

        reverse(nums.begin() + nTop + 1, nums.end());
    }
};