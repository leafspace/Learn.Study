/*
如果正整数可以被 A 或 B 整除，那么它是神奇的。

返回第 N 个神奇数字。由于答案可能非常大，返回它模 10^9 + 7 的结果。

 

示例 1：

输入：N = 1, A = 2, B = 3
输出：2
示例 2：

输入：N = 4, A = 2, B = 3
输出：6
示例 3：

输入：N = 5, A = 2, B = 4
输出：10
示例 4：

输入：N = 3, A = 6, B = 4
输出：8
 

提示：

1 <= N <= 10^9
2 <= A <= 40000
2 <= B <= 40000

*/

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int iLastIndex = 0;
        int iAIndex = 0;
        int iBIndex = 0;
        int iABIndex = 0;
        int iDivisor = this->findDivisor(A, B);
        while (N) {
            switch(this->findMinNum(iAIndex, iBIndex, iABIndex, A, B))
            {
                case 1 : iAIndex++; iLastIndex = iAIndex * A; break;
                case 2 : iBIndex++; iLastIndex = iBIndex * B; break;
                case 3 : iABIndex++; iLastIndex = iABIndex * A * B / iDivisor; break;
                case 4 : iAIndex++; iBIndex++; iABIndex++; iLastIndex = iAIndex * A; break;
                case 5 : iAIndex++; iABIndex++; iLastIndex = iAIndex * A; break;
                case 6 : iBIndex++; iABIndex++; iLastIndex = iBIndex * B;break;
                case 7 : iAIndex++; iBIndex++; iLastIndex = iAIndex * A;break;
                default : break;
            }
            N--;
        }
        
        
        double dModle = pow(10, 9) + 7;
        return (int)(iLastIndex % (int) dModle);
    }
    
    int findMinNum(int iAIndex, int iBIndex, int iABIndex, int A, int B) {
        static int iDivisor = this->findDivisor(A, B);
        int iValueA = (iAIndex + 1) * A;
        int iValueB = (iBIndex + 1) * B;
        int iValueAB = (iABIndex + 1) * A * B / iDivisor;
        int iRetIndex = 0;
        
        if (iValueA < iValueB && iValueA < iValueAB) {
            iRetIndex = 1;
        } else if(iValueB < iValueA && iValueB < iValueAB) {
            iRetIndex = 2;
        } else if(iValueAB < iValueA && iValueAB < iValueB) {
            iRetIndex = 3;
        } else if(iValueA == iValueAB && iValueB == iValueAB) {
            iRetIndex = 4;
        } else if(iValueA == iValueAB) {
            iRetIndex = 5;
        } else if (iValueB == iValueAB) {
            iRetIndex = 6;
        } else if (iValueA == iValueB) {
            iRetIndex = 7;
        }
        
        return iRetIndex;
    }
    
    int findDivisor(int A, int B) {
        int temp;
        while(B != 0) { 
            temp = A % B;
            A = B;
            B = temp;
        }
        return A;
    }
    
    int nthMagicalNumberSimple(int N, int A, int B) {
        int iTimeIndex = 0;
        while (N) {
            iTimeIndex++;
            if (iTimeIndex % A == 0 || iTimeIndex % B == 0) {
                N--;
            }
        }
        
        double dModle = pow(10, 9) + 7;
        return (int)(iTimeIndex % (int) dModle);
    }
};