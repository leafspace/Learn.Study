/*
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        TreeNode* tempLeft = root->left;
        TreeNode* tempRight = root->right;

        if (tempRight != nullptr)
        {
            // 转化右子树
            flatten(tempRight);
        }

        // 找到最后一片叶子
        if (tempLeft != nullptr)
        {
            // 转化左边子树
            flatten(tempLeft);
            root->right = tempLeft;
            while (tempLeft->right != nullptr) { tempLeft = tempLeft->right; }
            tempLeft->right = tempRight;
            root->left = nullptr;
        }
    }
};