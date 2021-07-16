# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        d1=headA
        d2=headB
        while d1!=d2:
            if d1.next==None and d2.next==None:
                return
            elif d1.next==None:
                d1=headB
                d2=d2.next
                
            elif d2.next==None:
                d2=headA
                d1=d1.next
            else:
                d1=d1.next
                d2=d2.next
        return d1
        
