/*

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int nRetMax = 0;
        map<int, int> mapDictionary;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            map<int, int>::iterator mapDictionardIndex = mapDictionary.find(i);
            if (mapDictionardIndex != mapDictionary.end())
            {
                mapDictionary[nums[i]] = mapDictionary[nums[i]] + 1;
            }
            else
            {
                mapDictionary.insert(std::pair<int, int>(nums[i], 1));
            }
        }

        for (auto iter : mapDictionary)
        {
            if ((&iter)->second > nRetMax)
            {
                nRetMax = (&iter)->second;
            }
        }

        return nRetMax;
    }
};