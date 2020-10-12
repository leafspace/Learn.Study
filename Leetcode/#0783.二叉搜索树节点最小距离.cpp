/*
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 

注意：

二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。
本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
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
/*class Solution {
private:
    vector<bool> m_bFlagList;
    void DeepLoop(TreeNode* root) {
        if (root == NULL) return;

        m_bFlagList[root->val] = true;

        DeepLoop(root->left);
        DeepLoop(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        m_bFlagList.clear();
        vector<bool> tempList(101, false);
        m_bFlagList = tempList;

        DeepLoop(root);

        int i = 0;
        int nTempMinDiff = 0;
        int nMinDifference = m_bFlagList.size();
        while (!m_bFlagList[i] && ++i < m_bFlagList.size()) {}
        for (i++; i < m_bFlagList.size(); ++i) 
        {
            nTempMinDiff++;
            if (m_bFlagList[i]) {
                if (nTempMinDiff < nMinDifference) nMinDifference = nTempMinDiff;
                if (nMinDifference == 1) return 1;
                nTempMinDiff = 0;
            }
        }

        return nMinDifference;
    }
};*/

class Solution {
private:
    vector<int> m_NodeList;
    void DeepLoop(TreeNode* root) {
        if (root == NULL) return;

        m_NodeList.push_back(root->val);

        DeepLoop(root->left);
        DeepLoop(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        m_NodeList.clear();

        DeepLoop(root);

        sort(m_NodeList.begin(), m_NodeList.end());

        int nMinDifference = 0xFFFFFF;
        for (int i = 1; i < m_NodeList.size(); ++i) {
            int nTempDiff = abs(m_NodeList[i] - m_NodeList[i - 1]);
            if (nTempDiff < nMinDifference) nMinDifference = nTempDiff;

            if (nMinDifference == 1) return 1; 
        }

        return nMinDifference;
    }
};