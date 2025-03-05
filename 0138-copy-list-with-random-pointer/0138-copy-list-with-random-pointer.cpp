/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* move = head;
        while(move!= NULL){
            Node* temp = new Node(move->val);
            temp->next = move->next;
            move->next = temp;
            move = move->next->next;
        }
        Node* move2 = head;
        while(move2!=NULL){
            if(move2->random!=NULL){
                move2->next->random = move2->random->next;
            }else{
                move2->next->random = NULL;
            }
            move2 = move2->next->next;
        }
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* move3 = head;

        while(move3!=NULL){
            temp->next=move3->next;
            temp = temp->next;
            move3->next = temp->next;
            move3 = move3->next;
        }
        return dummy->next;
    }
};