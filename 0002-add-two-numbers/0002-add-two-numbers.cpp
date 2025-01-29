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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL, *nextNode = NULL, *curr= node;

        while(curr!=NULL){
            nextNode = curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextNode;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1,*temp2= l2;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry =0;
        
        while((temp1!= NULL || temp2!=NULL) || carry){
            int sum=0;
            if(temp1!=NULL){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                sum+=temp2->val;
                temp2= temp2->next;
            }

            sum= sum+carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            temp->next= newNode;
            temp = temp->next;
        }
        return dummy->next;
    }
};