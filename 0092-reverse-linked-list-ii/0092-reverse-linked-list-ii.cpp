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
    void reverse(ListNode* head){
        ListNode* prev =NULL;
        ListNode* curr =head;
        ListNode* nextNode =NULL;

        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevLeft =NULL;
        ListNode* nextRight =NULL;
        ListNode* ans = head;
        // ListNode* prevLeft =NULL;
        if(head->next ==NULL || left==right){
            return head;
        }
        ListNode* leftNode;
        if(left ==1){
            leftNode = head;
        }
        else{
            int count =1;
            ListNode* node = head;
            while(count!=left){
                prevLeft = node;
                node= node->next;
                count++;
            }
            leftNode = node;
        }
        // calculate the right node;

        ListNode* rightNode= head;
        int count=1;
        ListNode* node = head;
        while(count!=right){
            node = node->next;
            nextRight= node->next;
            count++;
        }
        rightNode = node;
        rightNode->next= NULL;
        cout<<rightNode->val;
        reverse(leftNode);
        // if(r)

        if(prevLeft!=NULL){
            prevLeft->next = rightNode;
        }else{
            ans = rightNode;
        }
        // cout<< nextRight->val;
        if(nextRight!=NULL){
            leftNode->next = nextRight;
        }
        


        return ans;
    }
};