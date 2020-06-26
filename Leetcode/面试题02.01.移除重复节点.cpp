/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        map<int, int> mapDiction;

        // 链表为空的情况
        if (head == NULL)
        {
            return NULL;
        }

        ListNode* pRetHead = head;
        ListNode* pLastLinkNode = head;
        ListNode* pTempLoopNode = head->next;

        mapDiction.insert(pair<int, int>(head->val, 1));
        while (pTempLoopNode != NULL)
        {
            if (mapDiction.find(pTempLoopNode->val) != mapDiction.end())
            {// 已存在此元素
                mapDiction[pTempLoopNode->val]++;
                pTempLoopNode       = pTempLoopNode->next;
            }
            else
            {// 未存在元素
                mapDiction.insert(pair<int, int>(pTempLoopNode->val, 1));
                pLastLinkNode->next = pTempLoopNode;
                pLastLinkNode       = pTempLoopNode;
                pTempLoopNode       = pTempLoopNode->next;
                pLastLinkNode->next = NULL;
            }
        }
        return pRetHead;
    }
};