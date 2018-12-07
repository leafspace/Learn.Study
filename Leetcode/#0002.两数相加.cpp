/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* retNode = NULL;
        ListNode* p = retNode;
        int value = 0;
        bool isFirst = true;
        while(l1 != NULL || l2 != NULL || value != 0) {
            if (l1 == NULL && l2 == NULL) {
                while (value) {
                    p->next = new ListNode(value % 10);
                    value = value / 10;
                    p = p->next;
                }
                break;
            } else if (l1 == NULL) {
                value += l2->val;
                l2 = l2->next;
            } else if (l2 == NULL) {
                value += l1->val;
                l1 = l1->next;
            } else {
                value += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            cout << value << endl;
            
            if (isFirst) {
                retNode = new ListNode(value % 10);
                p = retNode;
                isFirst = false;
            } else {
                p->next = new ListNode(value % 10);
                p = p->next;
            }
            value = value / 10;
            
        }
        return retNode;
    }
};