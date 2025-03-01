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
    ListNode* reverseList(ListNode* head) {
        
        // ListNode* prev = NULL,*currNode = head,*nextNode= NULL;

        // while(currNode!=NULL){
        //     nextNode = currNode->next;
        //     currNode->next= prev;
        //     prev= currNode;
        //     currNode = nextNode;
        // }
        // return prev;
        
        // Base case 

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* nextNode = reverseList(head->next);

        head->next->next = head;
        head->next= NULL;
        return nextNode;



    }
};