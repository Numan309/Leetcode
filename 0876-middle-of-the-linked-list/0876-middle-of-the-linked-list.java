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

 //Optimal sloution BY Tortoise and hare solution

// Suppose we are given a linkedList [1]-->[2]-->[3]-->[4]-->[5]-->null
//odd                              //slow   slow   slow
                                  //fast         fast        fast
//even Suppose we are given a linkedList [1]-->[2]-->[3]-->[4]-->[5]-->[6]->null
                                    // slow.   slow  slow  slow
                                    //fast.          fast        fast     fast
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}