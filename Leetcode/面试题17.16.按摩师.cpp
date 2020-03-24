/*
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

 

示例 1：

输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：

输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
示例 3：

输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。


|      | 2    | 1    | 4    | 5    | 9    | 1    | 1    | 3    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 选   | 2    | 1    | 6    | 7    | 9    | 8    | 10   | 12   |
| 不选 | 0    | 2    | 2    | 6    | 7    | 9    | 9    | 10   |


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-masseuse-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

【春招】
*/

class Solution {
public:
    int massage(vector<int>& nums) {
        int nRetMax = 0;
        int *nChoose = new int[nums.size()];
        int *nNoChoose = new int[nums.size()];

        if (nums.size() == 0)
        {
            return 0;
        }
        
        nChoose[0] = nums[0];
        nNoChoose[0] = 0;

        for (int i = 1; i < nums.size(); ++i)
        {
            nChoose[i] = nNoChoose[i - 1] + nums[i];
            nNoChoose[i] = max(nChoose[i - 1], nNoChoose[i - 1]);    
        }

        nRetMax = max(nChoose[nums.size() - 1], nNoChoose[nums.size() - 1]);

        delete[] nChoose;
        delete[] nNoChoose;

        return nRetMax;
    }
};