/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
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
    vector<int> inorderList;
    void DeepLoop(TreeNode* root) {
        if (root == NULL) return;
        DeepLoop(root->left);
        inorderList.push_back(root->val);
        DeepLoop(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderList.clear();

        DeepLoop(root);

        return inorderList;
    }
};