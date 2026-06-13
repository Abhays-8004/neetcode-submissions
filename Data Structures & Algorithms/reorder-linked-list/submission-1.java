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
    public void reorderList(ListNode head) {
        ListNode temp1 = head;

        while(temp1.next != null){
            ListNode prv = temp1;
            while(prv.next.next!= null){
                prv = prv.next;
            }
            if(prv == temp1){
                return;
            }
            ListNode temp2 = prv.next;
            prv.next = null;
            temp2.next = temp1.next;
            temp1.next = temp2;
            temp1 = temp2.next;
        }
    }
}
