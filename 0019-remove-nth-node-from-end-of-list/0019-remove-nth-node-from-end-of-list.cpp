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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(n==1 && head->next==NULL) return NULL;
        ListNode* slow= head, *fast= head;
        int count =0;
        while(fast!=NULL && count!=n){
            fast=fast->next;
            count++;
        }
        if(fast==NULL){
            return head->next;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast = fast->next;
        }
        
        ListNode* node = slow->next;
        slow->next= slow->next->next;
        delete node;
        return head;
    }

};