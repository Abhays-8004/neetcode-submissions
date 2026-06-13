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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode dummynode = new ListNode(-1);
        ListNode temp = dummynode; 
        while(l1 != null && l2 != null){
            int x = carry + l1.val + l2.val;
            ListNode newnode = new ListNode(x%10);
            carry = x/10;
            temp.next = newnode ;
            temp = newnode;
            l1 = l1.next;
            l2= l2.next;
        }

        while(l1!= null){
            int x = carry + l1.val ;
            ListNode newnode = new ListNode(x%10);
            carry = x/10;
            temp.next = newnode;
            temp = newnode;
            l1 = l1.next;

        }
        while(l2 != null){
            int x = carry  + l2.val;
            ListNode newnode = new ListNode(x%10);
            carry = x/10;
            temp.next = newnode ;
            temp = newnode;
            l2 = l2.next;
        }

        if(carry>0){
             ListNode newnode = new ListNode(carry);
             temp.next = newnode ;
             temp = newnode;
        }

        return dummynode.next;
    }
}
