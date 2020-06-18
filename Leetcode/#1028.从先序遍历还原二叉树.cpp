/*
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：



输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
 

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal
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
      string getNextNumInfo(int& nNum, int& nDeep, string S)
      {
          nNum = 0;
          nDeep = 0;

          while (S[nDeep] == '-')
          {
              nDeep++;
          }

          int i = nDeep;
          while (S[i] != '-')
          {
              nNum = nNum * 10 + S[i] - '0';
              i++;

              if (i == S.length())
              {
                  break;
              }
          }

          S = S.substr(i);

          return S;
      }
  public:
      TreeNode* recoverFromPreorder(string S) {
          string strBackup = S;
          TreeNode* retTree = NULL;
          stack<TreeNode*> stackTree;

          // 初始化根节点
          int nNum = 0, nDeep = 0;
          retTree = new TreeNode(0);
          strBackup = this->getNextNumInfo(nNum, nDeep, strBackup);
          retTree->val = nNum;
          stackTree.push(retTree);

          bool bLeft = true;
          while (strBackup.length() != NULL)
          {
              // 获取一个节点
              strBackup = this->getNextNumInfo(nNum, nDeep, strBackup);

              if (nDeep < stackTree.size())
              {// 如果该节点对应的深度小于stack当前的深度，就pop至深度然后存放
                  while (stackTree.size() != nDeep)
                  {
                      stackTree.pop();
                  }

                  bLeft = false;
              }
              
              // 如果该节点对应的深度等于stack当前的深度，就取出stack节点存放
              if (nDeep == stackTree.size())
              {
                  // 弹出节点
                  TreeNode* tempNode = stackTree.top();
                  stackTree.pop();

                  stackTree.push(tempNode);

                  if (!bLeft || tempNode->left != NULL)
                  {
                      if (tempNode->right == NULL)
                      {
                          tempNode->right = new TreeNode(nNum);
                          tempNode->right->val = nNum;
                          stackTree.push(tempNode->right);
                          bLeft = true;
                      }
                  }
                  else
                  {
                      if (tempNode->left == NULL)
                      {
                          tempNode->left = new TreeNode(nNum);
                          tempNode->left->val = nNum;
                          stackTree.push(tempNode->left);
                      }
                  }
              }
              else
              {// 程序出现问题，或者我没考虑到的情况
                  break;
              }

          }
          return retTree;
      }
  };