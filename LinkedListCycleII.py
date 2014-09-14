# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        if head == None or head.next == None:
            return None
        if head.next == head:
            return head
        fast = head
        slow = head
        while True:
            if slow.next and fast.next and fast.next.next:
                slow = slow.next
                fast = fast.next.next
                if slow == fast:
                    break
            else:
                return None
        fast = head
        while fast != slow:
            slow = slow.next
            fast = fast.next
        return fast