/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = 0;
        int pIndex = 0;
        
        ListNode *pNode = head;
        ListNode *before = NULL, *after = NULL;
        while (pNode != NULL) {
            listSize++;
            pNode = pNode->next;
        }
        cout << listSize << endl;
        if (listSize == 1 && n >= 1) {
            return NULL;
        }
        
        pNode = head;
        while (pNode != NULL) {
            if (pIndex == (listSize - n - 1)) {
                before = pNode;
            } else if (pIndex == (listSize - n + 1)) {
                after = pNode;
            }
            pNode = pNode->next;
            pIndex++;
        }
        
        if (before == NULL) {
            return after;
        }
        
        before->next = after;
        return head;
    }
};