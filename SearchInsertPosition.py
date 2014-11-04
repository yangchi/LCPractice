class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        return self.binarySearchInsert(A, 0, len(A), target)
    
    def binarySearchInsert(self, A, begin, end, target):
        if begin >= end:
            return end
        mid = begin + (end - begin) / 2
        if A[mid] == target:
            return mid
        if A[mid] > target:
            return self.binarySearchInsert(A, begin, mid, target)
        return self.binarySearchInsert(A, mid + 1, end, target)