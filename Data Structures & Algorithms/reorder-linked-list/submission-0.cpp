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
    ListNode* reverseList(ListNode *node) {
        if(!node || !node->next)
            return node;
        
        ListNode *head = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        
        return head;
    }

    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *tempNode = head;
        while(tempNode){
            n++;
            tempNode = tempNode->next;
        }
        
        tempNode = head;
        int i = 0;
        while(i != (n - 1)/ 2){
            tempNode = tempNode->next;
            i++;
        }
        
        ListNode *mHead = tempNode->next;
        tempNode->next = nullptr;
        
        ListNode *rHead = reverseList(mHead);
        tempNode = head;
        
        for(int i = 0; i < n / 2; i++){
            ListNode *nextNode = tempNode->next;
            ListNode *rNextNode = rHead->next;
            
            tempNode->next = rHead;
            rHead->next = nextNode;
            
            rHead = rNextNode;
            tempNode = tempNode->next->next;
        }
    }
};
