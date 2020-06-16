/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree
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

string itoa(int nNum)
{
    string retStr;
    bool bFlag = nNum >= 0;
    stack<int> tempStack;

    if (!bFlag) nNum = -nNum;
    while (nNum)
    {
        tempStack.push(nNum % 10);
        nNum = nNum / 10;
    }

    while (!tempStack.empty())
    {
        retStr.push_back(tempStack.top() + '0');
        tempStack.pop();
    }

    if (!bFlag) retStr = "-" + retStr;
    return retStr;
}

int atoi(string str)
{
    int retNum = 0;
    bool bFlag = true;
    if (str[0] == '-')
    {
        bFlag = false;
    }

    for (int i = bFlag ? 0 : 1; i < str.length(); ++i)
    {
        retNum = retNum * 10 + str[i] - '0';
    }

    if (!bFlag) retNum = -retNum;
    return retNum;
}

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string retStr = "";
        queue<TreeNode*> stackRoot;

        if (root != NULL)
        {
            stackRoot.push(root);
        }

        while (!stackRoot.empty())
        {
            queue<TreeNode*> tempStack;
            while (!stackRoot.empty())
            {
                TreeNode* tempRoot = stackRoot.front();
                stackRoot.pop();

                if (tempRoot != NULL)
                {
                    retStr = retStr + itoa(tempRoot->val) + ",";
                    tempStack.push(tempRoot->left);
                    tempStack.push(tempRoot->right);
                }
                else
                {
                    retStr = retStr + "NULL,";
                }
            }

            stackRoot = tempStack;
        }

        // if (retStr.length() != 0)
        // {
        //     retStr[retStr.length() - 1] = 0;
        // }

        return retStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int nBeginIndex = -1;
        int nFindPointIndex = -1;
        TreeNode* retTree = NULL;
        
        nFindPointIndex = data.find(",", nBeginIndex + 1);
        if (nFindPointIndex != string::npos)
        {
            string tempStr = data.substr(nBeginIndex + 1, nFindPointIndex - (nBeginIndex + 1));
            if (tempStr != "NULL")
            {
                retTree = new TreeNode(atoi(tempStr));
            }
        }
        nBeginIndex = nFindPointIndex;
        nFindPointIndex = -1;
        
        queue<TreeNode*> tempQueueNode;
        tempQueueNode.push(retTree);
        while (!tempQueueNode.empty())
        {
            TreeNode* tempNode = tempQueueNode.front();
            tempQueueNode.pop();

            // left
            nFindPointIndex = data.find(",", nBeginIndex + 1);
            if (nFindPointIndex == string::npos)
            {
                break;
            }
            string tempStr = data.substr(nBeginIndex + 1, nFindPointIndex - (nBeginIndex + 1));
            nBeginIndex = nFindPointIndex;
            nFindPointIndex = -1;

            if (tempStr == "NULL")
            {
                tempNode->left = NULL;
            }
            else
            {
                tempNode->left = new TreeNode(atoi(tempStr));
                tempQueueNode.push(tempNode->left);
            }

            // right
            nFindPointIndex = data.find(",", nBeginIndex + 1);
            if (nFindPointIndex == string::npos)
            {
                break;
            }
            tempStr = data.substr(nBeginIndex + 1, nFindPointIndex - (nBeginIndex + 1));
            nBeginIndex = nFindPointIndex;
            nFindPointIndex = -1;

            if (tempStr == "NULL")
            {
                tempNode->right = NULL;
            }
            else
            {
                tempNode->right = new TreeNode(atoi(tempStr));
                tempQueueNode.push(tempNode->right);
            }
        }
        return retTree;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));