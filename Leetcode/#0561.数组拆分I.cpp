/*
给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入: [1,4,3,2]

输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
提示:

n 是正整数,范围在 [1, 10000].
数组中的元素范围在 [-10000, 10000].
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        /*
            From blog : https://blog.csdn.net/spring_3_shine/article/details/80002528
            固定长度2*n的数组，一定会找出n个数组成答案，我们要使这n个数尽可能大，所以要尽可能抛弃掉小的数。所以每次取最小的两个数，就可以抛弃较小的数，得到答案。
        */
        int retValue = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            retValue += nums[i];
        }
        
        return retValue;
    }
};