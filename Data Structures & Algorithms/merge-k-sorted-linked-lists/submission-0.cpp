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
    ListNode* mergetwolists(ListNode* list1,ListNode* list2){
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(list1 != NULL && list2 != NULL){
          ListNode* temp1 = list1->next;
          ListNode* temp2 = list2->next;
          if(list1->val == list2->val){
            temp->next = list1;
            list1->next = list2;
            list2->next = NULL;
            temp = list2;
            list1 = temp1;
            list2 = temp2;
          }
          else if(list1->val<list2->val){
            temp->next = list1;
            list1->next = NULL;
            temp = list1;
            list1 = temp1;
          }
          else{
            temp->next = list2;
            list2->next = NULL;
            temp = list2;
            list2 = temp2;
          }
        }

        if(list1 != NULL){
            temp->next = list1;
        }

        if(list2 != NULL){
            temp->next = list2;
        }

        return dummynode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()== 0 || (lists.size() == 1 && lists[0] == NULL)){
            return NULL;
        }
        ListNode* dummynode = new ListNode(-1);
        

        for(auto &list:lists){
           dummynode->next =  mergetwolists(dummynode->next,list);
        }


        return dummynode->next;
    }
};
