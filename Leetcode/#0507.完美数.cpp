/*
对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。

给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False

 

示例：

输入: 28
输出: True
解释: 28 = 1 + 2 + 4 + 7 + 14
 

注意:

输入的数字 n 不会超过 100,000,000. (1e8)
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int iSumNum = 0;
        if (num == 1) {
            return false;
        }
        
        vector<int> lstFactor = this->getAllFactor(num);
        for (int i = 0; i < lstFactor.size(); ++i) {
            iSumNum += lstFactor[i];
            cout << lstFactor[i] << endl;
        }
        
        if (iSumNum == num) {
            return true;
        } else {
            return false;
        }
    }
    
    vector<int> getAllFactor(int num) {
        vector<int> retList;
        int iNewLimit = num / 2;
        retList.push_back(1);
        for (int i = 2; i < iNewLimit; ++i) {
            if (num % i == 0) {
                retList.push_back(i);
                retList.push_back(num / i);
                iNewLimit = num / i;
            }
        }
        return retList;
    }
};