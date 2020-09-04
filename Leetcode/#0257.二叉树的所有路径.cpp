/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
通过次数54,379提交次数83,371

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> retList;

        if (root == NULL) return retList;
        if (root->left == NULL && root->right == NULL)
        {
            retList.push_back(to_string(root->val));
            return retList;
        }

        if (root->left != NULL)
        {
            vector<string> tempList = binaryTreePaths(root->left);
            for (int i = 0; i < tempList.size(); ++i)
            {
                retList.push_back(to_string(root->val) + "->" + tempList[i]);
            }
        }

        if (root->right != NULL)
        {
            vector<string> tempList = binaryTreePaths(root->right);
            for (int i = 0; i < tempList.size(); ++i)
            {
                retList.push_back(to_string(root->val) + "->" + tempList[i]);
            }
        }
        return retList;
    }
};