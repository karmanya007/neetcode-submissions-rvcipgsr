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
    ListNode* conquer(ListNode* left, ListNode* right){
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        
        while(left && right){
            if(left->val <= right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        
        if(left)
            cur->next = left;
        if(right)
            cur->next = right;
        
        return dummy->next;
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        if(l > r)
            return nullptr;
        if(l == r)
            return lists[l];
        
        int m = l + (r - l) / 2;
        ListNode *left = divide(lists, l, m);
        ListNode *right = divide(lists, m + 1, r);
        
        return conquer(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return nullptr;
        
        return divide(lists, 0, lists.size() - 1);
    }
};
