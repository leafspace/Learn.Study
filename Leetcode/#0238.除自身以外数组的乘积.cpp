/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

class Solution {
public:
    /*
    如数组N=[1,2,3,4]，我们一次遍历的时候，得到顺序的乘积为ins=[1,2,6,24]，逆序的乘积为ret=[24, 24, 12, 4]，那么最后对于数组N中的除当前元素之外其余各元素的乘积，我们就可以利用ins和ret这两个数组来计算得到，假设输出数组为output，对于output中的每一个元素，存在output [i] = ins [i-1] * ret [i+1]（注意边界条件），最后得到的结果为output = [24, 12, 8, 6]
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lstIns, lstRet(nums.size());
        vector<int> lstReturn;
        
        int temp = 1;
        for (int i = 0 ; i < nums.size(); ++i) {
            temp = temp * nums[i];
            lstIns.push_back(temp);
            cout << temp << "\t";
        }
        cout << endl;
        
        temp = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            temp = temp * nums[i];
            lstRet[i] = temp;
            cout << temp << "\t";
        }
        cout << endl;
        
        for (int i = 0; i < nums.size(); ++i) {
            int before = 1, after = 1;
            if ((i - 1) >= 0) {
                before = lstIns[i - 1];
            }
            
            if ((i + 1) < nums.size()) {
                after = lstRet[i + 1];
            }
            temp = before * after;
            lstReturn.push_back(temp);
        }
        
        return lstReturn;
    }
};