/*
排排坐，分糖果。

我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。

返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

 

示例 1：

输入：candies = 7, num_people = 4
输出：[1,2,3,1]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
示例 2：

输入：candies = 10, num_people = 3
输出：[5,2,3]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0]。
第三次，ans[2] += 3，数组变为 [1,2,3]。
第四次，ans[0] += 4，最终数组变为 [5,2,3]。
 

提示：

1 <= candies <= 10^9
1 <= num_people <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies-to-people
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    // 计算Sigma
    unsigned int getSigma(int n)
    {
        static bool bIsCalculate = false;
        static unsigned int nSigma[1000] = { 0 };

        if (n > 1000)
        {
            return -1;
        }

        if (n == 0)
        {
            return 0;
        }

        if (bIsCalculate == false)
        {
            // 计算范围内所有的sigma
            nSigma[0] = 1;
            for (int i = 1; i < 1000; ++i)
            {
                nSigma[i] = nSigma[i - 1] + (i + 1);
            }
        }

        return nSigma[n - 1];
    }

    // 获取nKTimes次分配从共分配的糖果数量
    unsigned int getCumulativeSum(int nKTimes, int num_people)
    {
        if (nKTimes < 2)
        {
            return getSigma(num_people);
        }
        return getSigma(nKTimes - 1) * num_people * num_people + nKTimes * getSigma(num_people);
    }

    // 获取第nIndex个人nKTimes总共拿到的糖果数量
    unsigned int getOnePeopleGetNum(int nKTimes, int nIndex, int num_people)
    {
        if (nKTimes == 0)
        {
            return 0;
        }
        return getSigma(nKTimes - 1) * num_people + nKTimes * nIndex;
    }

    // 获取到达当前次当前人时总共分配的数量
    unsigned int getAllDistribute(int nKTimes, int nIndex, int num_people)
    {
        if (nKTimes < 3)
        {
            if (nKTimes == 1)
            {
                return getSigma(nIndex);
            }
            else if (nKTimes == 2)
            {
                return getSigma(num_people) + nIndex * num_people + getSigma(nIndex);
            }
        }
        return getSigma(nKTimes - 1 - 1) * num_people * num_people + (nKTimes - 1) * getSigma(num_people) + (nKTimes - 1) * num_people * nIndex + getSigma(nIndex);
    }

    vector<int> distributeCandies(int candies, int num_people) {
        // 计算分发了多少次K=？
        int nKTimes = 1;
        vector<int> retList;
        while (candies > getCumulativeSum(nKTimes, num_people))
        {
            nKTimes++;
        }

        bool bIsOver = false;
        for (int i = 0; i < num_people; ++i)
        {
            // 完全分完当前人的数量
            unsigned int unAllDistribution = getAllDistribute(nKTimes, i + 1, num_people);
            
            if (bIsOver == false)
            {
                if (candies >= unAllDistribution)
                {
                    // 完全够分
                    unsigned int unDistribution = getOnePeopleGetNum(nKTimes, i + 1, num_people);
                    retList.push_back(unDistribution);

                    if (candies == unAllDistribution)
                    {
                        bIsOver = true;
                    }
                }
                else
                {
                    // 前面的都不够分或者正好
                    bIsOver = true;
                    unsigned int unDistribution = getAllDistribute(nKTimes, i, num_people);
                    retList.push_back(candies - unDistribution + getOnePeopleGetNum(nKTimes - 1, i + 1, num_people));
                }
            }
            else
            {
                // 只能分到上一次的
                unsigned int unDistribution = getOnePeopleGetNum(nKTimes - 1, i + 1, num_people);
                retList.push_back(unDistribution);
            }
        }

        return retList;
    }
};