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
    ListNode* reverse(ListNode* head){

        ListNode* prev =NULL, *nextNode = NULL, *currNode = head;

        while(currNode!=NULL){

            nextNode = currNode->next;

            currNode->next = prev;
            prev = currNode;
            currNode = nextNode;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {

        // parting the list from middel and applying the reverse 

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){

            slow = slow->next;
            fast= fast->next->next;
        }

        slow->next= reverse(slow->next);

        ListNode* p1=head, *p2 = slow->next;
        // cout<<p2->val;
        int maxSum = INT_MIN;
        while(p2!=NULL){

            maxSum = max(maxSum, (p1->val + p2->val));
            // cout<<maxSum<<" ";
            p1= p1->next;
            p2 = p2->next;
        }
        return maxSum;
    }
};