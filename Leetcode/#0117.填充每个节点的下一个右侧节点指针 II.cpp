/*
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 

示例：



输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

树中的节点数小于 6000
-100 <= node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<vector<Node*>> m_levelTree;

    void DeepLoop(Node* root, int nLevel = 0)
    {
        if (root == NULL) return;
        if (nLevel >= m_levelTree.size()) {
            vector<Node*> tempList;
            m_levelTree.push_back(tempList);
        }

        m_levelTree[nLevel].push_back(root);

        DeepLoop(root->left, nLevel + 1);
        DeepLoop(root->right, nLevel + 1);
    }
public:
    Node* connect(Node* root) {
        m_levelTree.clear();

        DeepLoop(root);

        for (int i = 0; i < m_levelTree.size(); ++i) {
            for (int j = 0; j < m_levelTree[i].size(); ++j) {
                if ((j + 1) < m_levelTree[i].size()) {
                    m_levelTree[i][j]->next = m_levelTree[i][j + 1];
                }
                else {
                    m_levelTree[i][j]->next = NULL;
                }
            }
        }

        return root;
    }
};