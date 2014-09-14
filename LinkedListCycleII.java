/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
	public ListNode detectCycle(ListNode head) {
		if (head == null || head.next == null)
			return null;
		ListNode fast = head, slow = head;
		while(true) {
			if(slow.next != null && fast.next != null && fast.next.next != null) {
				slow = slow.next;
				fast = fast.next.next;
				if (slow == fast)
					break;
			} else {
				return null;
			}
		}
		fast = head;
		while(fast != slow) {
			fast = fast.next;
			slow = slow.next;
		}
		return fast;
	}
}
