/*

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
通过次数256,381提交次数395,074
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }

        int nRetNum = 0;
        // 找到所有的波峰波谷  且一定是波谷买入，波锋卖出
        int nState = 0; // 0为无状态 1为升高状态 -1为降低状态
        vector<int> pricesFlagLst;
        pricesFlagLst.push_back(prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                if (nState == -1) {
                    pricesFlagLst.push_back(prices[i - 1]);
                }

                nState = 1;
            }
            else if (prices[i] < prices[i - 1]) {
                if (nState == 1) {
                    pricesFlagLst.push_back(prices[i - 1]);
                }

                nState = -1;
            }
        }
        pricesFlagLst.push_back(prices[prices.size() - 1]);

        int i = 1;
        while (i < pricesFlagLst.size() && pricesFlagLst[i] <= pricesFlagLst[i - 1]) i++;
        for (; i < pricesFlagLst.size(); i += 2) {
            if (pricesFlagLst[i] > pricesFlagLst[i - 1]) {
                nRetNum = nRetNum + (pricesFlagLst[i] - pricesFlagLst[i - 1]);
            }
        }

        return nRetNum;
    }
};