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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode; 
        while(l1 != NULL && l2 != NULL){
            int x = carry + l1->val + l2->val;
            ListNode* newnode = new ListNode(x%10);
            carry = x/10;
            temp->next = newnode ;
            temp = newnode;
            l1 = l1->next;
            l2= l2->next;
        }

        while(l1!= NULL){
            int x = carry + l1->val ;
            ListNode* newnode = new ListNode(x%10);
            carry = x/10;
            temp->next = newnode;
            temp = newnode;
            l1 = l1->next;

        }
        while(l2 != NULL){
            int x = carry  + l2->val;
            ListNode* newnode = new ListNode(x%10);
            carry = x/10;
            temp->next = newnode ;
            temp = newnode;
            l2 = l2->next;
        }

        if(carry){
             ListNode* newnode = new ListNode(carry);
             temp->next = newnode ;
             temp = newnode;
        }

        return dummynode->next;
    }
};
