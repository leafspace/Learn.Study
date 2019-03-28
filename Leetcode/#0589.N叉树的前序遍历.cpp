/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

 



 

返回其前序遍历: [1,3,5,6,2,4]。

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> retLst;
        if (root != NULL) {
            retLst.push_back(root->val);
            for (int i = 0; i < root->children.size(); ++i) {
                vector<int> pList = this->preorder(root->children[i]);
                for (int j = 0; j < pList.size(); ++j) {
                    retLst.push_back(pList[j]);
                }
            }
        }
        return retLst;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack <Node*> tStack;
        vector<int> retLst;
        
        Node* tempNode = root;
        do
        {
            if (tempNode != NULL) {
                // 存储数据
                retLst.push_back(tempNode->val);
                
                // 有叶子，则反序存放叶子
                if (tempNode->children.size() != 0) {
                    for (int i = tempNode->children.size() - 1; i >= 0; --i) {
                        tStack.push(tempNode->children[i]);
                    }   
                }
                
               if (!tStack.empty()){
                    tempNode = tStack.top();
                    tStack.pop();
                } else {
                   tempNode = NULL;
               }
            }
        } while(!tStack.empty() || tempNode != NULL);
        
        return retLst;
    }
};