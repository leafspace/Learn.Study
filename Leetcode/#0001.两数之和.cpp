/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retValue;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                } else {
                    if ((nums[i] + nums[j]) == target) {
                        retValue.push_back(i);
                        retValue.push_back(j);
                        return retValue;
                    }
                }
            }
        } 
        
        /*for (int i = 0; i < nums.size(); ++i) {
            int numTarget = target - nums[i];
            if (numTarget < nums[i]) {
                continue;
            } else {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (nums[j] == numTarget) {
                        retValue.push_back(i);
                        retValue.push_back(j);
                        return retValue;
                    }
                }
            }
        }*/
    }
};