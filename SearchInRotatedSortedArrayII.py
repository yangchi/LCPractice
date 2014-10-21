class Solution:
    # @param A a list of integers
    # @param target an integer
    # @return a boolean
    def search(self, A, target):
        for elem in A:
            if elem == target:
                return True
        return False