/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        // head 中没有内容
        if (head == NULL) {
            return NULL;
        }
        
        int iModel = getListSize(head);
        k = k % iModel;
        
        // 找到最后一个结点，然后移动到第一个结点中来
        ListNode* preNode = head;
        ListNode* nowNode = head;
        for (int i = 0; i < k; ++i) {
            while(nowNode->next) {
                preNode = nowNode;
                nowNode = nowNode->next;
            }
            if (preNode == nowNode) {
                // 一个元素的情况
                continue;
            }
            preNode->next = NULL;
            nowNode->next = head;
            head = nowNode;
        }
        return head;
    }
    
    int getListSize(ListNode* head) {
        int iRetNum = 0;
        while(head) {
            iRetNum++;
            head = head->next;
        }
        return iRetNum;
    }
};