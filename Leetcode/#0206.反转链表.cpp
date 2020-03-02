/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return NULL;
        }
        
        if (head->next == NULL)
            return head;
        else
        {
            ListNode* pReverList = reverseList(head->next);
            ListNode* backupList = pReverList;
            while (backupList->next)
            {
                backupList = backupList->next;
            }

            head->next = NULL;
            backupList->next = head;
            
            // backupList = pReverList;
            // while (backupList)
            // {
            //     std::cout << backupList->val << " ";
            //     backupList = backupList->next;
            // }
            // std::cout << endl;
            return pReverList;
        }

    }
};