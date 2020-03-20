/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
通过次数10,681提交次数18,404
【春招】
*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int nNowMaxIndex = -1;
        int nNowMax = -1;
        vector<int> retList;

        if (k == 0)
        {
            return retList;
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            if (k > 0)
            {
                if (arr[i] > nNowMax)
                {
                    nNowMax = arr[i];
                    nNowMaxIndex = retList.size();
                }

                // 还没满 直接压入
                retList.push_back(arr[i]);
                k--;
            }
            else
            {
                if (arr[i] < nNowMax)
                {
                    retList[nNowMaxIndex] = arr[i];

                    nNowMaxIndex = 0;
                    nNowMax = retList[0];
                    for (int j = 1; j < retList.size(); ++j)
                    {
                        if (retList[j] > nNowMax)
                        {
                            nNowMax = retList[j];
                            nNowMaxIndex = j;
                        }
                    }
                }
            }
        }
        
        return retList;
    }
};