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
        
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* nextNode = NULL;

        while(curr!=NULL){
            nextNode = curr->next;
            curr->next= prev;
            prev = curr;
            curr= nextNode;
        
        }
        return prev;
    }
ListNode* getKthNode(ListNode* node, int k){
    k-=1;
    while(node!=NULL && k>0){
        node = node->next;
        k--;
    }
    return node;

}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {


        ListNode* prevNode = NULL;
        ListNode* temp = head;
        while(temp){


            ListNode* kthNode = getKthNode(temp,k);

            if(kthNode ==NULL){
                if(prevNode!=NULL){
                    prevNode->next = temp;
                }
                break;

            }

            ListNode* nextNode = kthNode->next;

            kthNode->next = NULL;
            reverse(temp);

            if(temp == head){
                head = kthNode;
            }else{
                prevNode->next = kthNode;
            }
            prevNode = temp;

            temp = nextNode;
        }
        return head;
    }
};