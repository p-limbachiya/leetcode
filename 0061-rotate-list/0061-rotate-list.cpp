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
    int size(ListNode* head){
        ListNode* temp = head;
        int n=0;
        while (temp!=NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode* newhead(ListNode* head,int n){
        ListNode* temp = head;
        for(int i=0;i<n-1;i++){
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;
        int n = size(head);
        int rotate = k % n;
        if(rotate == 0) return head;
        ListNode* temp = head;
        ListNode* prev = newhead(head,n - rotate);
        ListNode* newhead = prev->next;
        ListNode* move = newhead;
        while(move->next!= NULL){
            move = move->next;
        }
        move->next = head;
        prev->next = NULL;
        return newhead;
    }
};