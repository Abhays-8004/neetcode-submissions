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
    public ListNode removeNthFromEnd(ListNode head, int n) {
          int x = 0;
        ListNode temp = head ;
        while(temp != null){
            x++;
            temp = temp.next;
        }

        temp = head;
        x = x-n;
        if(x == 0)return head.next;
        while(x>1){
            temp = temp.next;
            x--;
        }

        temp.next = temp.next.next;

        return head;
    }
}
