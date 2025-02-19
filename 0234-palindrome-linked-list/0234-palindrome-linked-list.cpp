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
    ListNode* Reverselist(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* move = head;
        while(move!= nullptr){
            ListNode* front = move->next;
            move->next=prev;
            prev=move;
            move=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* fast = head; 
        ListNode* slow = head;
        while(fast->next!=nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        } 
        ListNode* tail = Reverselist(slow->next);
        ListNode* first = head;
        ListNode* second = tail;
        while(second!=nullptr){
            if(first->val!=second->val){
                Reverselist(tail);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        Reverselist(tail);
        return true;
    }
};