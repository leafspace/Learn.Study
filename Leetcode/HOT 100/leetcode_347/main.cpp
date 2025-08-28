#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numsMap;
        for (int val : nums) {
            if (numsMap.find(val) != numsMap.end()) {
                numsMap[val] += 1;
            } else {
                numsMap[val] = 1;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> minHeap(cmp);
        for (auto item : numsMap) {
            if (minHeap.size() < k) {
                minHeap.push(pair<int, int>(item.first, item.second));
            } else {
                if (minHeap.top().second < item.second) {
                    minHeap.pop();
                    minHeap.push(pair<int, int>(item.first, item.second));
                }
            }
            cout << minHeap.top().first << endl;
        }

        vector<int> refList;
        while (!minHeap.empty())
        {
            refList.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return refList;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4,1,-1,2,-1,2,3};
    int k = 2;
    vector<int> result = solution.topKFrequent(nums, k);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}