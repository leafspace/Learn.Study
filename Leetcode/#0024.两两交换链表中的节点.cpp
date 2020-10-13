/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
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
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* before = head;
        ListNode* after = nullptr;
        ListNode* tHead = head;
        if (before == NULL || before && before->next == NULL) return before;
        if (before) after = before->next;
        if (after) head = after;

        tHead = before;
        before->next = after->next;
        after->next = before;
        if (tHead->next == NULL) return head;
        before = before->next;
        after = before->next;
        
        while (after && before)
        {
            before->next = after->next;
            after->next = before;
            tHead->next = after;
            tHead = before;
            if (tHead->next == NULL) break;
            before = before->next;
            after = before->next;
        }

        return head;
    }
};