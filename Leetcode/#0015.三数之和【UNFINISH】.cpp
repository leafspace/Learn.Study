/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int FindNum(vector<int>& nums, int nNum, int aIndex, int bIndex)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == aIndex || i == bIndex)
            {
                continue;
            }

            if (nums[i] == nNum)
            {
                return i;
            }
        }
        return -1;
    }

    bool IsSameList(vector<int> numsA, vector<int> numsB)
    {
        if (numsA.size() != numsB.size())
        {
            return false;
        }

        for (int i = 0; i < numsA.size(); ++i)
        {
            if (numsA[i] != numsB[i])
            {
                return false;
            }
        }

        return true;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> retList;
        vector<vector<int>> retTempList;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int nLastNum = 0 - (nums[i] + nums[j]);
                int nLastNumIndex = FindNum(nums, nLastNum, i, j);
                if (nLastNumIndex >= 0)
                {
                    vector<int> tempList;
                    int a = nums[i] > nums[j] ? 
                    (nums[j] > nums[nLastNumIndex] ? nums[nLastNumIndex] : nums[j]) :
                    (nums[i] > nums[nLastNumIndex] ? nums[nLastNumIndex] : nums[i]);

                    int b = nums[i] > nums[j] ?
                        (nums[j] > nums[nLastNumIndex] ? nums[j] : nums[i] > nums[nLastNumIndex] ? nums[nLastNumIndex] : nums[i]) :
                        (nums[i] > nums[nLastNumIndex] ? nums[i] : nums[j] > nums[nLastNumIndex] ? nums[nLastNumIndex] : nums[j]);

                    int c = nums[i] < nums[j] ? 
                    (nums[j] < nums[nLastNumIndex] ? nums[nLastNumIndex] : nums[j]) :
                    (nums[i] < nums[nLastNumIndex] ? nums[nLastNumIndex] : nums[i]);

                    tempList.push_back(a);
                    tempList.push_back(b);
                    tempList.push_back(c);
                    retTempList.push_back(tempList);
                }
            }
        }

        for (int i = 0; i < retTempList.size(); ++i)
        {
            int j = 0;
            for (; j < retList.size(); ++j)
            {
                if (IsSameList(retTempList[i], retList[j]))
                {
                    break;
                }
            }
            if (j >= retList.size())
            {
                retList.push_back(retTempList[i]);
            }
        }
        return retList;
    }
};