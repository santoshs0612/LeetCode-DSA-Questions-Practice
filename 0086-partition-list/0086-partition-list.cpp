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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next ==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = dummy;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* temp2 = dummy1;

        while(head!=NULL){

            if(head->val < x){
                temp1->next = head;
                temp1= temp1->next;
            }else{
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head->next;
        }
        cout<< temp1->val;
        cout<< temp2->val;

        // cout<< dummy1->next->val;
        temp2->next = NULL;
        temp1->next = dummy1->next;

        return dummy->next;
        
    }
};