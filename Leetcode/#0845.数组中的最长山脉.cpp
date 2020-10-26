/*
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：

B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）

给出一个整数数组 A，返回最长 “山脉” 的长度。

如果不含有 “山脉” 则返回 0。

 

示例 1：

输入：[2,1,4,7,3,2,5]
输出：5
解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
示例 2：

输入：[2,2,2]
输出：0
解释：不含 “山脉”。
 

提示：

0 <= A.length <= 10000
0 <= A[i] <= 10000
通过次数11,829提交次数30,421

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-mountain-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int nRetMaxLen = 0;
        int nUpLen = -1;
        int nDownLen = -1;

        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1]) {
                if (nUpLen > 0 && nDownLen < 0) {
                    nUpLen++;
                    nDownLen = -1;
                }
                else if (nUpLen < 0 && nDownLen < 0) {
                    nUpLen = 2;
                    nDownLen = -1;
                }
                else if (nUpLen > 0 && nDownLen > 0) {
                    if ((nUpLen + nDownLen) > nRetMaxLen) nRetMaxLen = (nUpLen + nDownLen);
                    nUpLen = 2;
                    nDownLen = -1;
                }
                else if (nUpLen < 0 && nDownLen > 0) {
                    nUpLen = 2;
                    nDownLen = -1;
                }
            }
            else if (A[i] < A[i - 1]) {
                if (nUpLen > 0 && nDownLen < 0) {
                    nDownLen = 1;
                }
                else if (nUpLen < 0 && nDownLen < 0) {
                    nUpLen = -1;
                    nDownLen = -1;
                }
                else if (nUpLen > 0 && nDownLen > 0) {
                    nDownLen++;
                }
                else if (nUpLen < 0 && nDownLen > 0) {
                    nDownLen++;
                }
            }
            else {
                if (nUpLen > 0 && nDownLen > 0 && (nUpLen + nDownLen) > nRetMaxLen) {
                    nRetMaxLen = nUpLen + nDownLen;
                }
                nUpLen = -1;
                nDownLen = -1;
            }
        }

        if ((nUpLen + nDownLen) > nRetMaxLen && nDownLen > 0) nRetMaxLen = (nUpLen + nDownLen);
        
        if (nRetMaxLen < 3) return 0;
        return nRetMaxLen;
    }
};