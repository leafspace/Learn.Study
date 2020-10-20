/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    vector<ListNode*> m_listNode;
public:
    void reorderList(ListNode* head) {
        ListNode* p = head;
        m_listNode.clear();

        while (head)
        {
            m_listNode.push_back(head);
            head = head->next;
        }

        if (m_listNode.size() < 3) {
            head = p;
            return;
        }

        for (int i = 0; i < m_listNode.size() / 2; ++i) 
        {
            m_listNode[i]->next = m_listNode[m_listNode.size() - 1 - i];
            m_listNode[m_listNode.size() - 1 - i]->next = m_listNode[i + 1];
        }

        if (m_listNode.size() % 2) {
            m_listNode[m_listNode.size() / 2]->next = nullptr;
        }
        else
        {
            m_listNode[m_listNode.size() / 2 - 1]->next->next = nullptr;
        }

        head = p;
    }
};