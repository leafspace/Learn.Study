#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
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