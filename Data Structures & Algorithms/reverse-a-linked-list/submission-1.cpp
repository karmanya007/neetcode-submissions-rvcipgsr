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
    ListNode *rec(ListNode *node){
        if(!node || !node->next)
            return node;

        ListNode *head = rec(node->next);

        node->next->next = node;
        node->next = nullptr;

        return head;
    }

    ListNode* reverseList(ListNode* head) {
        return rec(head);
    }
};
