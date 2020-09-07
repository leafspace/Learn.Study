/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
private:
    vector<vector<int>> m_OrderList;
public:
    void deepLoop(TreeNode* root, int nLevel = 0) {
        vector<int> tempList;
        if (m_OrderList.size() > nLevel)
        {
            tempList = m_OrderList[nLevel];
        }

        tempList.push_back(root->val);
        if (m_OrderList.size() > nLevel)
        {
            m_OrderList[nLevel] = tempList;
        }
        else
        {
            m_OrderList.push_back(tempList);
        }

        if (root->left != NULL) deepLoop(root->left, nLevel + 1);
        if (root->right != NULL) deepLoop(root->right, nLevel + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> retList;
        if (root == NULL) return retList;

        m_OrderList.clear();
        deepLoop(root);

        for (int i = m_OrderList.size() - 1; i >= 0; --i)
        {
            retList.push_back(m_OrderList[i]);
        }

        return retList;
    }
};