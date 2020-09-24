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
    map<int, int> m_NumCount;
    int m_nMaxCount;

    void DeepLoop(TreeNode* root) {
        if (root == NULL) return;

        if (m_NumCount.find(root->val) == m_NumCount.end())
        {
            m_NumCount.insert(pair<int, int>(root->val, 1));
        }
        else
        {
            m_NumCount[root->val]++;
            if (m_NumCount[root->val] > m_nMaxCount) {
                m_nMaxCount = m_NumCount[root->val];
            }
        }

        DeepLoop(root->left);
        DeepLoop(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        m_NumCount.clear();
        m_nMaxCount = 1;

        vector<int> retList;

        if (root == NULL) return retList;

        DeepLoop(root);

        for (auto iter = m_NumCount.begin(); iter != m_NumCount.end(); ++iter)
        {
            if (iter->second == m_nMaxCount) {
                retList.push_back(iter->first);
            }
        }

        return retList;
    }
};