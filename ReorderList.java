
public class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;
        ListNode quick = head, slow = head;
        while(quick != null && quick.next != null && quick.next.next != null) {
            quick = quick.next.next;
            slow = slow.next;
        }
        ListNode second_half = slow.next;
        slow.next = null;
        printList(second_half);

        second_half = reverseList(second_half);
        printList(head);
        printList(second_half);
        ListNode first_half = head;
        while(second_half != null) {
            ListNode temp = second_half.next;
            second_half.next = first_half.next;
            first_half.next = second_half;
            first_half = second_half.next;
            second_half = temp;
        }

    }

    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode previous = null;
        ListNode current = head;
        ListNode current_next = head.next;
        while(current_next != null) {
            current.next = previous;
            previous = current_next;
            ListNode temp = current_next.next;
            current_next.next = current;
            current = temp;
            if (current != null)
                current_next = current.next;
            else
                break;
        }
        if (current != null && current.next == null) {
            current.next = previous;
            return current;
        }
        return current_next;
    }

    public void printList(ListNode node) {
        while(node != null) {
            System.out.print(node.val + " -> ");
            node = node.next;
        }
        System.out.println("NULL");
    }

    public static void main (String [] args) {
        Solution mysolution = new Solution();
        ListNode first = new ListNode(1);
        ListNode second = new ListNode(2);
        ListNode third = new ListNode(3);
        ListNode fourth = new ListNode(4);
        /*
        ListNode fifth = new ListNode(5);
        ListNode sixth = new ListNode(6);
        ListNode seventh = new ListNode(7);
        */
        first.next = second;
        second.next = third;
        third.next = fourth;
        /*
        fourth.next = fifth;
        fifth.next = sixth;
        sixth.next = seventh;
        */
        fourth.next = null;
        mysolution.printList(first);
        mysolution.reorderList(first);
        mysolution.printList(first);
    }
}