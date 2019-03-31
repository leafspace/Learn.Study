/*
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意:

数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。

*/

/*
class Solution {
public:
    int CaculateBitNum(int nValue) {
        int retValue = 0;
        while(nValue) {
            if (nValue % 2 == 1) {
                retValue++;
            }
            nValue /= 2;
        }
        return retValue;
    }
    
    int HammingDistance(int nValueA, int nValueB) {
        int nXOR = nValueA ^ nValueB;              // 算出异或值
        // 计算异或值中为1的数量
        return this->CaculateBitNum(nXOR);
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int retValue = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                retValue += this->HammingDistance(nums[i], nums[j]);
            }
        }
        return retValue;
    }
};

这一题目如果借用汉明距离–位运算 分别求两位数字之间的汉明距离，最后再求和，那么肯定会超时。换一种思路：对每一个数的相同位置的上的二进制位进行判断，统计是1的个数cnt，那么为0的个数就是nums.size()-cnt，那么该二进制位就会形成cnt*（nums.size()-cnt）的汉明距离。
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt, ans = 0;
        for(int i = 0; i < 32; i++){
            cnt = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j]&1){
                    cnt++;
                }
                nums[j] >>= 1;
            }
            ans += cnt*(nums.size() - cnt);
        }
        return ans;
    }
};