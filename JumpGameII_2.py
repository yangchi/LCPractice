class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        if len(A) < 2:
            return 0
        start = 0
        end = 0
        count = 0
        while end < len(A):
            count += 1
            current_max = 0
            for i in range(start, end + 1):
                if A[i] + i >= len(A) - 1:
                    return count
                if A[i] + i > current_max:
                    current_max = A[i] + i
            start = end + 1
            end = current_max
        return count