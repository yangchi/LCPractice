class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        count_red = 0
        count_white = 0
        count_blue = 0
        for i in A:
            if i == 0:
                count_red += 1
            elif i == 1:
                count_white += 1
            else:
                count_blue += 1
        for i in range(len(A)):
            if i < count_red:
                A[i] = 0
            elif i < count_red + count_white:
                A[i] = 1
            else:
                A[i] = 2