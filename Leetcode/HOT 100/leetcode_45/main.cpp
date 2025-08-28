#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minJump(vector<int>& nums, vector<int>& minStepList, int nIndex)
	{
        //cout << nIndex << endl;
		if (nIndex >= nums.size() - 1)
		{
			return 0;
		}
        if (nums[nIndex] == 0)
        {
            return nums.size(); // 无法前进，返回一个大值
        }
        if (minStepList[nIndex] != -1)
        {
            return minStepList[nIndex];
        }

        int nMinStep = nums.size();
		int nMaxIndex = min((int)nums.size() - 1, nIndex + nums[nIndex]);
        for (int i = nIndex + 1; i <= nMaxIndex; i++)
        {
            int step = 1 + minJump(nums, minStepList, i);
            nMinStep = min(nMinStep, step);
        }

        minStepList[nIndex] = nMinStep;
		return nMinStep;
	}

	int jump(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return 0;
        }
        
        std::vector<int> minStepList(nums.size(), -1);
		return minJump(nums, minStepList, 0);
	}
};

int main()
{
    Solution solution;
    vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    cout << "Nums : " << nums.size() << endl;
    int result = solution.jump(nums);
    cout << "Minimum jumps: " << result << endl;
    return 0;
}