/**
 * Definition for singly-linked list.
 *   public class ListNode {
 *      int val;
 *      ListNode next;
 *		ListNode(int x) {
 *			val = x;
 *			next = null;
 *      }
 *  }
 **/
public class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode newHead = null, new_cur = null;
		if(l1 == null && l2 == null)
			return newHead;
		else if(l1 == null)
			return l2;
		else if(l2 == null)
			return l1;
		ListNode l1_cur = l1, l2_cur = l2;
		while(l1_cur != null && l2_cur != null) {
			int l1_val = l1_cur.val;
			int l2_val = l2_cur.val;
			if(newHead == null) {
				if(l1_val < l2_val) {
					newHead = l1_cur;
					new_cur = newHead;
					l1_cur = l1_cur.next;
				} else {
					newHead = l2_cur;
					new_cur = newHead;
					l2_cur = l2_cur.next;
				}
			} else {
				if(l1_val < l2_val) {
					new_cur.next = l1_cur;
					new_cur = new_cur.next;
					l1_cur = l1_cur.next;
				} else {
					new_cur.next = l2_cur;
					new_cur = new_cur.next;
					l2_cur = l2_cur.next;
				}
			}
		}
		if(l1_cur != null)
			new_cur.next = l1_cur;
		else
			new_cur.next = l2_cur;
		return newHead;
	}
}
