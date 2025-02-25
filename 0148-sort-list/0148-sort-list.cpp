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
    ListNode* FindMiddle(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!= NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergelist(ListNode* lefthead, ListNode* righthead){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(lefthead != NULL && righthead != NULL){
            if(lefthead->val < righthead->val){
                temp->next = lefthead;
                lefthead = lefthead->next;
            } else {
                temp->next = righthead;
                righthead = righthead->next;
            }
            temp = temp->next;
        }
        if(lefthead) temp->next = lefthead;
        if(righthead) temp->next = righthead;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = FindMiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        middle->next = NULL;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return mergelist(lefthead,righthead);

    }
};