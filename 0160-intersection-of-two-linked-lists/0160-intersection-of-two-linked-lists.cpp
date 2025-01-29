/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int countLen(ListNode* node){
        int a=0;
        while(node!=NULL){
            a++;
            node= node->next;
        }
        return a;
    }
    ListNode* solver(ListNode* node1, ListNode* node2, int val){

        while(val){
            node1= node1->next;
            val--;
        }

        while(node1!=node2){
            node1=node1->next;
            node2=node2->next;
        }
        return node1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int a =0,b=0;
        
        a = countLen(headA);
        b = countLen(headB);

        if( a>b){
            return solver(headA,headB,a-b);
        }
        
        return solver(headB,headA, b-a);

    }
};