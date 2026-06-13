/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummynode = new ListNode(-1);
        if(list1 == null){
            return list2;
        }
        if(list2 == null){
            return list1;
        }
        ListNode temp1 = list1;
        ListNode temp2 = list2;
        ListNode temp = dummynode;
        while(temp1!= null && temp2!= null){
            ListNode curr1 = temp1.next;
            ListNode curr2 = temp2.next;
            if(temp1.val == temp2.val){
                temp.next = temp1;
                temp1.next = temp2;
                temp2.next = null;
                temp = temp2;
                temp1 = curr1;
                temp2 = curr2;
            }else if(temp1.val < temp2.val){
                temp.next = temp1;
                temp1.next = null;
                temp = temp1;
                temp1 = curr1;
                
            }else{
                temp.next = temp2;
                temp2.next = null;
                temp = temp2;
                temp2 = curr2;
            }

            
        }

        if(temp1 != null){
            temp.next = temp1;
        }

        if(temp2 != null){
            temp.next = temp2;
        }

     
       return dummynode.next;
    }
}