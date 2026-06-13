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
    void reorderList(ListNode* head) {
        ListNode* temp1 = head;

        while(temp1->next != NULL){
            ListNode* prv = temp1;
            while(prv->next->next!= NULL){
                prv = prv->next;
            }
            if(prv == temp1){
                return;
            }
            ListNode* temp2 = prv->next;
            prv->next = NULL;
            temp2->next = temp1->next;
            temp1->next = temp2;
            temp1 = temp2->next;
        }
    }
};
