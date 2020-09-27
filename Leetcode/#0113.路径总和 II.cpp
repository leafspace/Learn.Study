/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
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
    vector<vector<int>> m_pathList;
    void DeepLoop(TreeNode* root, vector<int> list, int sum) {
        if (root == NULL) return;

        if (sum == root->val) {
            if (root->left == NULL && root->right == NULL) {
                list.push_back(root->val);
                m_pathList.push_back(list);
                return;
            }
        }

        list.push_back(root->val);

        DeepLoop(root->left, list, sum - root->val);
        DeepLoop(root->right, list, sum - root->val);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        m_pathList.clear();

        vector<int> pathList;
        DeepLoop(root, pathList, sum);

        return m_pathList;
    }
};