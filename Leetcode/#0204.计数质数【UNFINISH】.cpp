/*

统计所有小于非负整数 n 的质数的数量。

 

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
 

提示：

0 <= n <= 5 * 106
*/

class Solution {
private:
    bool isPrimes(int n)
    {
        for (int i = 0; i < primesLst.size(); ++i)
        {
            if (n % primesLst[i] == 0) return false;
        }
        return true;
    }

    vector<int> primesLst;
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        else if (n < 4) return 1;
        else if (n < 6) return 2;
        else if (n < 8) return 3;

        primesLst.clear();
        int nRetCount = 4;
        primesLst.push_back(5);
        primesLst.push_back(7);
        for (int i = 8; i < n; ++i)
        {
            if (i % 2 == 0 || i % 3 == 0) continue;
            if (isPrimes(i)) {
                nRetCount++;
                primesLst.push_back(i);
            }
        }
        return nRetCount;
    }
};