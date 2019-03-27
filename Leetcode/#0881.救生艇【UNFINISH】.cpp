/*
第 i 个人的体重为 people[i]，每艘船可以承载的最大重量为 limit。

每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

 

示例 1：

输入：people = [1,2], limit = 3
输出：1
解释：1 艘船载 (1, 2)
示例 2：

输入：people = [3,2,2,1], limit = 3
输出：3
解释：3 艘船分别载 (1, 2), (2) 和 (3)
示例 3：

输入：people = [3,5,3,4], limit = 5
输出：4
解释：4 艘船分别载 (3), (3), (4), (5)
提示：

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int iRetTimes = 0;
        int iLeftPeople = people.size();
        bool *bUseFlags = new bool[people.size()];
        for (int i = 0; i < people.size(); ++i) {
            bUseFlags[i] = true;
        }
        
        
        while(iLeftPeople) {
            // TODO 找到当前数组里满足 0 < x < limit 的最大x组合
            int iMaxIndex = this->findMaxIndex(people, bUseFlags);
            int iMinIndex = this->findMinIndex(people, bUseFlags, iMaxIndex);
            
            if (iMaxIndex == -1) {
                if (iMinIndex == -1) {
                    // 不会出现这种情况
                }
                bUseFlags[iMinIndex] = false;
                iLeftPeople--;
            } else if(iMinIndex == -1) {
                bUseFlags[iMaxIndex] = false;
                iLeftPeople--;
            } else if(iMaxIndex == iMinIndex) {
                bUseFlags[iMinIndex] = false;
                iLeftPeople--;
            } else {
                if ((people[iMaxIndex] + people[iMinIndex]) <= limit) {
                    bUseFlags[iMaxIndex] = false;
                    bUseFlags[iMinIndex] = false;
                    iLeftPeople-=2;
                } else {
                    bUseFlags[iMaxIndex] = false;
                    iLeftPeople--;
                }
            }
            iRetTimes++;
        }
        
        return iRetTimes;
    }
    
    bool checkSumLimit(vector<int> people, int limit) {
        int sum = 0;
        for (int i = 0; i < people.size(); ++i) {
            sum += people[i];
        }
        return sum < limit;
    }
    
    int findMaxIndex(vector<int> &people, bool *bUseFlags, int iMinIndex = -1) {
        int iRetIndex = 0;
        while ((iRetIndex < people.size() && !bUseFlags[iRetIndex]) || iRetIndex == iMinIndex) {
            iRetIndex++;
        };
        
        if (iRetIndex == people.size()) {
            return -1;
        }
        
        for (int i = 0; i < people.size(); ++i) {
            if (!bUseFlags[i] || i == iRetIndex) {
                continue;
            }
            
            if (people[i] > people[iRetIndex]) {
                iRetIndex = i;
            }
        }
        return iRetIndex;
    }
    
    int findMinIndex(vector<int> &people, bool *bUseFlags, int iMaxIndex = -1) {
        int iRetIndex = 0;
        while ((iRetIndex < people.size() && !bUseFlags[iRetIndex]) || iRetIndex == iMaxIndex) {
            iRetIndex++;
        };
        
        for (int i = 0; i < people.size(); ++i) {
            if (!bUseFlags[i] || i == iRetIndex) {
                continue;
            }
            
            if (people[i] < people[iRetIndex]) {
                iRetIndex = i;
            }
        }
        return iRetIndex;
    }
    
};