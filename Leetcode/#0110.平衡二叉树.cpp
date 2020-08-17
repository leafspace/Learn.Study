/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。+
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
public:
    bool bIsBalanced = true;
    int getDeep(TreeNode* root) {
        if (root == NULL) return 0;
        else 
        {
            int nDeepLeft = getDeep(root->left);
            int nDeepRight = getDeep(root->right);

            if (abs(nDeepLeft - nDeepRight) > 1) bIsBalanced = false;
            return max(nDeepLeft, nDeepRight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (abs(getDeep(root->left) - getDeep(root->right)) > 1)
        {
            return false;
        }

        return bIsBalanced;
    }
};