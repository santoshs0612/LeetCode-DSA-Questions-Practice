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
private:
    ListNode* solverRev(ListNode* head){

        ListNode* curr= head,*prev= NULL, *nextNode= NULL;

        while(curr!=NULL){
            nextNode = curr->next;
            curr->next= prev;
            prev= curr;
            curr=nextNode;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* fast = head, *slow = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* newHead= solverRev(slow->next);
        ListNode* second =newHead,*first= head;
        while(second!=NULL){

            if(second->val!=first->val){
                return false;
            }
            second= second->next;
            first= first->next;
        }
        return true;
    }
};