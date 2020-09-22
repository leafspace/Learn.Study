/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
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
    int m_nSum;
    void DeepLoop(TreeNode* root)
    {
        if (root == NULL) return ;
        DeepLoop(root->right);
        m_nSum += root->val;
        root->val = m_nSum;
        DeepLoop(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        m_nSum = 0;
        DeepLoop(root);
        return root;
    }
}; 