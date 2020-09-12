/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

 

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
 

提示：

节点值的范围在32位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<double> m_AverageList;
    vector<int> m_AverageCountList;

    void DeepLoop(TreeNode* root, int nLevel = 0) {
        if (root == NULL) return;

        if (m_AverageList.size() != m_AverageCountList.size()) return;
        if (m_AverageList.size() <= nLevel) {
            m_AverageList.push_back(0);
            m_AverageCountList.push_back(0);
        }

        m_AverageList[nLevel] += root->val;
        m_AverageCountList[nLevel]++;

        DeepLoop(root->left, nLevel + 1);
        DeepLoop(root->right, nLevel + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        m_AverageList.clear();
        m_AverageCountList.clear();

        DeepLoop(root);

        for (int i = 0; i < m_AverageList.size(); ++i) {
            m_AverageList[i] = m_AverageList[i] / (m_AverageCountList[i] * 1.0);
        }

        return m_AverageList;
    }
};