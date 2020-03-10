/*
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
【春招】
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
    int nMaxDepth = 0;
    int findMaxDepth(TreeNode* leaf)
    {
        if (leaf == NULL)
        {
            return 0;
        }
        else
        {
            int nLeft = findMaxDepth(leaf->left);
            int nRight = findMaxDepth(leaf->right);
            if (leaf->left != NULL)
            {
                nLeft++;
            }

            if (leaf->right != NULL)
            {
                nRight++;
            }

            if ((nLeft + nRight) > nMaxDepth)
            {
                nMaxDepth = nLeft + nRight;
            }

            return max(nLeft, nRight);
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        findMaxDepth(root);
        return nMaxDepth;
    }
};