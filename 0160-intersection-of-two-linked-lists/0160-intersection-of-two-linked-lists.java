/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       while(headB!= null) {
        ListNode temp = headA;
        while(temp != null) {
            //if both nodes are same
            if(temp == headB) return headB;
            temp = temp.next;
        }
        headB = headB.next;
    }
    //intersection is not present between the lists return null
    return null;  
    }
}