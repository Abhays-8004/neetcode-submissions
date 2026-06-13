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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x = 0;
        ListNode* temp = head ;
        while(temp != NULL){
            x++;
            temp = temp->next;
        }

        temp = head;
        x = x-n;
        if(x == 0)return head->next;
        while(x>1){
            temp = temp->next;
            x--;
        }

        temp->next = temp->next->next;

        return head;

    }
};
