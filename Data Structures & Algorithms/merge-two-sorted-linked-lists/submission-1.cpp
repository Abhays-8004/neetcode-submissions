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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummynode = new ListNode(-1);
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = dummynode;
        while(temp1!= NULL && temp2!= NULL){
            ListNode* curr1 = temp1->next;
            ListNode* curr2 = temp2->next;
            if(temp1->val == temp2->val){
                temp->next = temp1;
                temp1->next = temp2;
                temp2->next = NULL;
                temp = temp2;
                temp1 = curr1;
                temp2 = curr2;
            }else if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1->next = NULL;
                temp = temp1;
                temp1 = curr1;
                
            }else{
                temp->next = temp2;
                temp2->next = NULL;
                temp = temp2;
                temp2 = curr2;
            }

            
        }

        if(temp1 != NULL){
            temp->next = temp1;
        }

        if(temp2 != NULL){
            temp->next = temp2;
        }

     
       return dummynode->next;
    }
};
